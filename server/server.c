#include "server.h"

static int registerID = 100000;
static int timeID = 0;
static int groupID;
struct sqlite3 *db;
int listenFd, acceptFd;
sockaddr_in client, server;
//客户端信息
client_details clients[MAX_CLIENT];

////
int initDatabase()
{
    if (SQLITE_OK != sqlite3_open("server.db", &db))
    {
        return 0;
    }
    sqlite3_exec(db, "create table if not exists onlineuser(uid int)", NULL, NULL, NULL);
    sqlite3_exec(db, "create table if not exists user (uid  int,username char,password char)", NULL, NULL, NULL);
    sqlite3_exec(db, "create table if not exists offlinemsg(fromid int,toid int,msg char,time char, timeid int)", NULL, NULL, NULL);
    sqlite3_exec(db, "create table if not exists groupmember(groupname char, groupid int, uid int)", NULL, NULL, NULL);
    sqlite3_exec(db, "create table if not exists contact(uid1 int,uid2 int)", NULL, NULL, NULL);
    return 1;
    printf("datebase initialization is successful\n");
}

int initSocket()
{
    listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenFd == -1)
    {
        perror("socket error");
        return 0;
    }
    //释放ip地址
    int vel = 1;
    setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, (void *)&vel, sizeof(vel));
    //清空server
    bzero(&server, sizeof(server));
    //初始哈serveraddr
    server.sin_family = AF_INET;
    server.sin_port = htons(MY_PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listenFd, (sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("bind error");
        return 0;
    }
    if (listen(listenFd, MAX_CLIENT) == -1)
    {
        perror("listen error");
        return 0;
    }
    printf("socket initialization is successful\n");
    return 1;
}

int initServer()
{
    //初始化客户端信息表
    int i = 0;
    for (i = 0; i < MAX_CLIENT; i++)
    {
        clients[i].client_fd = -1;
        clients[i].uid = -1;
        // clients[i].username = {0};
        clients[i].is_online = 0;
    }
    if (initDatabase() == 0)
    {
        perror("initialize database error");
        return 0;
    }
    if (initSocket() == 0)
    {
        perror("initialize socket error");
        return 0;
    }
    printf("server initialization is successful\n");
    return 1;
}
int acceptFunction()
{
    //接收一下客户端的信息
    int s = sizeof(struct sockaddr_in);
    acceptFd = accept(listenFd, (sockaddr *)&client, &s);
    if (acceptFd == -1)
    {
        perror("accept error");
        return 0;
    }
    //服务端打印一下客户端信息
    printf("connection from %s\n", inet_ntoa(client.sin_addr));
    int i = 0;
    for (i = 0; i < MAX_CLIENT ; i++)
    {
        //寻找空闲位置
        if (clients[i].client_fd == -1)
        {
            break;
        }
    }
    //用户已满
    if (clients[i].client_fd != -1)
    {
        printf("full\n");
        printf("clients is dull, %s is fail\n", inet_ntoa(client.sin_addr));
    }
    //给用户表赋值
    clients[i].client_fd = acceptFd;
    clients[i].addr = client;
    //创建线程
    pthread_t tid;
    pthread_create(&tid, NULL, listenCallbackFunction, &clients[i]);
    //pthread_join(tid,NULL);
    printf("created a thread to connect for %s\n", inet_ntoa(client.sin_addr));
    return 1;
}

void *listenCallbackFunction(void *arg)
{
    //将参数类型转换一下，我们使用封装好的用户结构通信
    client_details *clt = (client_details *)arg;
    //数据缓冲区
    char msg[BYTE_LEN];
    
    //接受数据长度
    int msgLen = 0;
    while (1)
    {
        bzero(msg,sizeof(msg));
        msgLen = recv(clt->client_fd, msg, BYTE_LEN, 0);
        printf("recv: %s\n",msg);
        if (msgLen == 0)
        {
            printf("user %s is offline.\n", inet_ntoa(clt->addr.sin_addr));
            break;
        }
        // msg[msgLen] ='\0'//设置末尾符号
        handleMsg(clt, msg);
    }
    deleteClient(clt);
    pthread_exit(NULL);
}
void deleteClient(client_details *clt)
{
    if (close(clt->client_fd) < -1)
    {
        perror("close error");
    }
    clt->uid = -1;
    bzero(clt->username, sizeof(clt->username));
}

void handleMsg(client_details *clt, char *msg)
{
    printf("handling msg from client %s, message is\n%s\n", inet_ntoa(clt->addr.sin_addr), msg);
    if (msg == NULL)
    {
        return;
    }
    char flag[20],submsg[500];
    bzero(flag,sizeof(flag));
    bzero(submsg,sizeof(submsg));
    sscanf(msg, "%19[a-z]|%s", flag, submsg);
    //一对一发送消息
    printf("debug sscanf\n");
    if (strcmp(flag, "signalmsg") == 0)
    {
        sendSingalMsg(clt, submsg);
    }
    else if (strcmp(flag, "register") == 0)
    {
        registerUser(clt, submsg);
    }
    else if (strcmp(flag, "login") == 0)
    {
        userLogin(clt, submsg);
    }
    else if (strcmp(flag, "logout") == 0)
    {
        userLogout(clt, submsg);
    }
    else if (strcmp(flag, "requestfriend") == 0)
    {
        sendRequestFriend(clt, submsg);
    }
    else if (strcmp(flag, "backfriend") == 0)
    {
        backRequestFriend(clt, submsg);
    }
    else if (strcmp(flag, "groupmsg") == 0)
    {
        sendGroupMsg(clt, submsg);
    }
    else if(strcmp(flag,"addgroup") == 0)
    {
        addGroup(clt,submsg);
    }
    printf("succeed in handling a msg\n");
}
//
void userLogout(client_details *clt, char *submsg)
{
    //clt->client_fd = -1;
    clt->uid = -1;
    clt->is_online = 0;
    bzero(clt->username, sizeof(clt->username));
}

int getUserFd(int ID)
{
    int i = 0;
    for (i = 0; i < MAX_CLIENT; i++)
    {
        if (clients[i].uid == ID)
        {
            return clients[i].client_fd;
        }
    }
    return -1;
}

void sendSingalMsg(client_details *clt, char *submsg)
{
    int fromID, toID;
    char sendTime[100], content[500];
    bzero(sendTime,sizeof(sendTime));
    bzero(content,sizeof(content));
    sscanf(submsg, "%d|%d|%99[0-9.:&-]|%s", &fromID, &toID, sendTime, content);
    //得到对方的句柄
    int toFd = getUserFd(toID);
    //用户不在线，保存离线消息
    if (toFd == -1)
    {
        char sqlStatement[1000];
        bzero(sqlStatement,sizeof(sqlStatement));
        //组装SQL语句
        sprintf(sqlStatement, "insert into offlinemsg values(%d,%d,\'%s\',\'%s\',%d)",
                fromID, toID, content, sendTime, timeID++);
        sqlite3_exec(db, sqlStatement, NULL, NULL, NULL);
        printf("%d id offline\n",toID);
    }
    else
    {
        char sendMsg[1000];
        bzero(sendMsg,sizeof(sendMsg));
        //组装协议信息
        sprintf(sendMsg, "signalmsg|%d|%d|%s|%s@", fromID, toID, sendTime, content);
        write(toFd, sendMsg, strlen(sendMsg));
        printf("sendSinalMsg is successful: %s\n",sendMsg);
    }
}

void registerUser(client_details *clt, char *submsg)
{
    printf("user register\n");
    int ID = registerID++;
    //向数据库插入用户信息
    char sqlStatement[200],userName[100], userPassword[100];
    bzero(sqlStatement,sizeof(sqlStatement));
    bzero(userName,sizeof(userName));
    bzero(userPassword,sizeof(userPassword));
    sscanf(submsg, "%99[^|]|%s", userName, userPassword);
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement, "insert into user values(%d,\'%s\',\'%s\')", ID, userName, userPassword);
    sqlite3_exec(db, sqlStatement, NULL, NULL, NULL);
    //向客户端返回账号
    char backMsg[200];
    bzero(backMsg,sizeof(backMsg));
    sprintf(backMsg, "register|%d@", ID);
    write(clt->client_fd, backMsg, strlen(backMsg));
    printf("succeed in register\n");
}

void userLogin(client_details *clt, char *submsg)
{
    printf("login user\n");
    int userID;
    char recvPassword[50],sqlStatement[200];
    sscanf(submsg, "%d|%99[^|]", &userID, recvPassword);
    printf("user:%d,password:%s want to login\n",userID,recvPassword);
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement, "select * from user where uid = %d", userID);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    //查询失败
    if (vel != SQLITE_OK)
    {
        perror("select fail of login\n");
        return;
    }
    //用户名不存在
    if (numRow == 0)
    {
        char *idError = "login|iderror@";
        write(clt->client_fd, idError, strlen(idError));
        printf("id is error\n");
    }
    else
    {
        if (strcmp(value[5], recvPassword) == 0)
        {
            printf("password is correct\n");
            //没有在别处登录
            if (isLogined(userID) == 0)
            {
                char idCorrect[1000];
                sprintf(idCorrect,"login|success|%s@",value[4]);
                write(clt->client_fd,idCorrect,strlen(idCorrect));
                printf("logined and send some msg\n");
                clt->is_online = 1;
                clt->uid = userID;
                strcpy(clt->username, value[4]);
                //发送一些列消息给客户端加载界面
                //给所有好友发送本人在线消息
                sendLoginMsg(clt);
                //更新客户端群聊列表
                sendGroupList(clt);
                //更新客户端好友列表
                sendFriendList(clt);
                //给客户端发送积累的离线消息(包括群聊)
                sendOfflineUserMsg(clt);
                
            }
        }
        else
        {
            char *passwordError = "login|passworderror@";
            write(clt->client_fd, passwordError, strlen(passwordError));
            printf("password is error");
        }
    }
}

client_details *getClientDetails(int ID)
{
    int i = 0;
    for (i = 0; i < MAX_CLIENT; i++)
    {
        if (clients[i].uid == ID)
        {
            return &clients[i];
        }
    }
    return NULL;
}

int isLogined(int ID)
{
    client_details *temp = getClientDetails(ID);
    if (temp == NULL)
    {
        return 0;
    }
    else if (temp->is_online == 0)
    {
        return 0;
    }
    return 1;
}

//给所有好友发送上线人在线消息
void sendLoginMsg(client_details *clt)
{
    printf("enter function sendloginmsg\n");
    char sqlStatement[1000];
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement,"select uid2 from contact where uid1 = %d",clt->uid);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    //查询失败
    if (vel != SQLITE_OK)
    {
        perror("select fail of sendloginmsg\n");
        return;
    }
    int i = 0;
    printf("number of friend: %d\n",numRow);
    for(i = 1; i < numRow + 1; i++)
    {
        int toID;
        sscanf(value[i],"%d",&toID);
        int recvFd = getUserFd(toID);
        if(recvFd !=- 1)
        {
            char backmsg[200];
            bzero(backmsg,sizeof(backmsg));
            sprintf(backmsg,"friendlogin|%d|%s@",clt->uid,clt->username);
            write(recvFd,backmsg,strlen(backmsg));
        }
    }
    printf("sendLoginMsg of %d\n",clt->uid);
}

//更新客户端群聊列表
void sendGroupList(client_details *clt)
{
    printf("enter function sendgrouplist\n");
    char sqlStatement[200];
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement, "select groupname,groupid from groupmember where uid = %d", clt->uid);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    if (vel != SQLITE_OK)
    {
        perror("select fail of sendgrouplist\n");
        return;
    }
    printf("numRow: %d,numCol: %d\n",numRow,numCol);
    //逐条发送
    int i = 0;
    // value[i]为groupID，value[i-1]为对应name
    for (i = 3; i < (numRow + 1) * numCol; i += 2)
    {
        char groupMsg[200];
        bzero(groupMsg, sizeof(groupMsg));
        sprintf(groupMsg, "grouplist|%s|%s@", value[i], value[i - 1]);
        //printf("%d\n",i);
        int groupID = 0;
        sscanf(value[i],"%d",&groupID);
        //sendGroupMember(clt,group);
        write(clt->client_fd, groupMsg, strlen(groupMsg));


        printf("sendgroupmember of %d\n",groupID);
        bzero(sqlStatement,sizeof(sqlStatement));
        sprintf(sqlStatement,"select uid from groupmember where groupid = %d",groupID);
        char **value0; //查询结果
        char *errmsg0; //返回错误信息
        int numRow0;  //结果数
        int numCol0;  //每条结果包含多少条数据
        int vel = sqlite3_get_table(db, sqlStatement, &value0, &numRow0, &numCol0, &errmsg0);
        int i = 1;
        if(numRow0 != 0)
        {
            int memberID = 0;
            for(i = 1; i < numRow0 + 1; i++)
            {
                sscanf(value0[i],"%d",&memberID);
                char sqlStatement0[200];
                bzero(sqlStatement0,sizeof(sqlStatement0));
                sprintf(sqlStatement0, "select username from user where uid = %d", memberID);
                char **value1; //查询结果
                char *errmsg1; //返回错误信息
                int numRow1;  //结果数
                int numCol1;  //每条结果包含多少条数据
                int vel = sqlite3_get_table(db, sqlStatement0, &value1, &numRow1, &numCol1, &errmsg1);
                char backMember[100];
                sprintf(backMember,"groupmember|%d|%d|%s@",groupID,memberID,value1[1]);
                write(clt->client_fd, backMember, strlen(backMember));
            }
        }


    }
    printf("sendGroupList of %d",clt->uid);
}

// void sendGroupMember(client_details* clt,int groupID)
// {


// }
//更新客户端好友列表
void sendFriendList(client_details *clt)
{
    printf("enter function sendfriendlist\n");
    char sqlStatement[200];
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement, "select uid2 from contact where uid1 = %d", clt->uid);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据

    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    if (vel != SQLITE_OK)
    {
        perror("select fail of sendfriendlist\n");
        return;
    }
    int i = 1;
    for (i = 1; i < (numRow + 1) * numCol; i++)
    {
        int friendID = 0;
        sscanf(value[i], "%d", &friendID);
        char sqlStatement0[200];
        bzero(sqlStatement0,sizeof(sqlStatement0));
        sprintf(sqlStatement0, "select username from user where uid = %d", friendID);
        char **value0; //查询结果
        char *errmsg0; //返回错误信息
        int numRow0;  //结果数
        int numCol0;  //每条结果包含多少条数据
        int vel = sqlite3_get_table(db, sqlStatement0, &value0, &numRow0, &numCol0, &errmsg0);
        int state = 0;
        char fri[100];
        bzero(fri, sizeof(fri));


        if (isLogined(friendID) == 1)
        {
            state = 1;
        }

        sprintf(fri, "friendlist|%s|%s|%d@", value[i],value0[1],state);
        write(clt->client_fd, fri, strlen(fri));
    }
    printf("sendFriendList of %d\n",clt->uid);
}


char* getUserName(int ID)
{
    char sqlStatement[200];
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement, "select username from user where uid = %d", ID);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    char* name;
    bzero(name,sizeof(name));
    if(numRow !=0)
    {
        strcpy(name,value[1]);
    }
    return name;
}
//给客户端发送离线消息
void sendOfflineUserMsg(client_details *clt)
{
    char sqlStatement[200];
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement, "select fromid,msg,time,timeid from offlinemsg where toid = %d order by timeid", clt->uid);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    if (vel != SQLITE_OK)
    {
        perror("select fail of sendofflinemsg\n");
        return;
    }
    int i = 7;
    // value[i]为timeid,value[i-1]=time,value[i-2]=msg,value[i-3]=fromid
    for (i = 7; i < (numRow + 1) * numCol; i += 4)
    {
        char offlineMsg[1000];
        bzero(offlineMsg, sizeof(offlineMsg));
        sprintf(offlineMsg, "offlinemsg|%s|%s|%s@", value[i - 3], value[i - 1], value[i - 2]);
        write(clt->client_fd, offlineMsg, strlen(offlineMsg));
    }
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement,"delete from offlinemsg where toid = %d",clt->uid);
    sqlite3_exec(db,sqlStatement,NULL,NULL,NULL);
    printf("sendOfflineUserMsg of %d\n",clt->uid);
}

void sendRequestFriend(client_details *clt, char *msg)
{
    printf("sendrequestfriend\n");
    int fromid, toid;
    sscanf(msg, "%d|%d", &fromid, &toid);
    char sqlStatement[200];
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement, "select * from contact where uid1 = %d and uid2 = %d", fromid, toid);
    //printf("request fri sql: %s",sqlStatement);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    if (vel != SQLITE_OK)
    {
        perror("select fail of sendrequestfriend\n");
        return;
    }
    printf("from: %d, to: %d, numRow: %d\n",fromid,toid,numRow);
    //返回已添加好友消息
    if (numRow != 0)
    {
        char *backMsg = "backfriend|already@";
        write(clt->client_fd, backMsg, strlen(backMsg));
        printf("friend is already\n");
    }
    else
    {
        char sendMsg[200];
        bzero(sendMsg,sizeof(sendMsg));
        sprintf(sendMsg, "requestfriend|%d|%s@", clt->uid, clt->username);
        int recvFd = getUserFd(toid);
        //在线的时候发过去
        if (recvFd != -1)
        {
            write(recvFd, sendMsg, strlen(sendMsg));
            printf("sendRequestFriend to %d\n",toid);
        }
        
    }
}

void backRequestFriend(client_details *clt, char *msg)
{
    int toid,myid;
    char back[10];//yes or no
    char name[20];
    sscanf(msg, "%d|%19[0-9a-z]|%d|%9[a-z]", &myid,name,&toid, back);
    printf("myid: %d,toid: %d\n",myid,toid);
    
    int toFd = getUserFd(toid);
    char backMsg[200];
    bzero(backMsg,sizeof(backMsg));
    sprintf(backMsg, "backfriend|%d|%s|%s@", clt->uid, clt->username,back);
    //反馈消息
    if (toFd != -1)
    {
        write(toFd, backMsg, strlen(backMsg));
    }
    if (strcmp(back, "yes") == 0)
    {
        char sqlStatement[200];
        bzero(sqlStatement,sizeof(sqlStatement));
        sprintf(sqlStatement, "insert into contact values(%d,%d)", clt->uid, toid);
        sqlite3_exec(db, sqlStatement, NULL, NULL, NULL);
        bzero(sqlStatement, sizeof(sqlStatement));
        sprintf(sqlStatement, "insert into contact values(%d,%d)", toid, clt->uid);
        sqlite3_exec(db, sqlStatement, NULL, NULL, NULL);
    }
}

void sendGroupMsg(client_details *clt, char *msg)
{
    char sqlStatement[200];
    bzero(sqlStatement,sizeof(sqlStatement));
    int groupID, fromID;
    char a[500];
    char b[20];
    char fromName[20];
    sscanf(msg, "%d|%19[a-z0-9]|%d|%500[^|]|%19[0-9/]", &fromID,fromName,&groupID, a, b);
    sprintf(sqlStatement, "select uid from groupmember where groupid = %d", groupID);
    char **value; //查询结果
    char *errmsg; //返回错误信息
    int numRow;  //结果数
    int numCol;  //每条结果包含多少条数据
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    printf("sql:　%s\n",sqlStatement);
    if (vel != SQLITE_OK)
    {
        perror("select fail of sendgroupmsg\n");
        return;
    }
	printf("numRow: %d\n",numRow);
    if (numRow > 0)
    {
        int i = 1;
        for (i = 1; i < (numRow + 1) * numCol; i++)
        {
            int recvID;
            sscanf(value[i], "%d", &recvID);
	    if(recvID == fromID)
	    {
	    	continue;
	    }
	    printf("recvID: %d\n",recvID);
            int recvFd = getUserFd(recvID);
            if (recvFd != -1)
            {
                char msg0[1000];
                sprintf(msg0,"groupmsg|%s@",msg);
                write(recvFd, msg0, strlen(msg0));
            }
        }
        printf("sendgroupmsg is successful\n");
    }
}

void addGroup(client_details* clt,char* msg)
{
    char sqlStatement[200];
    bzero(sqlStatement,sizeof(sqlStatement));
    int fromID,groupID;
    char groupName[100];
    bzero(groupName,sizeof(groupName));
    //sscanf(msg, "%99[^|]|%d|%d",groupName, &fromID, &groupID);
    sscanf(msg, "%d|%d", &fromID, &groupID);
    sprintf(sqlStatement, "select * from groupmember where groupid = %d and uid = %d", groupID,fromID);
    char **value; char *errmsg; int numRow;  int numCol; 
    int vel = sqlite3_get_table(db, sqlStatement, &value, &numRow, &numCol, &errmsg);
    if(numRow != 0)
    {
        printf("addgroup is already\n");
        char* back0 = "addgroup|already@";
        //char back[200];
        //bzero(back,sizeof(back));
        //sprintf(back,"addgroup|%d|%s|already@",groupID,groupName);
        write(clt->client_fd,back0,strlen(back0));
        return;
    }
    bzero(sqlStatement,sizeof(sqlStatement));
    sprintf(sqlStatement,"insert into groupmember values(\'%s\',%d,%d)",groupName,groupID,fromID);
    sqlite3_exec(db,sqlStatement,NULL,NULL,NULL);
    char back[200];
    bzero(back,sizeof(back));
    sprintf(back,"addgroup|%d|%s|yes@",groupID,groupName);
    write(clt->client_fd,back,strlen(back));
    printf("addgroup is successful\n");
}

void listenThreadFunction(void* arg)
{
    acceptFunction();
}
