#ifndef SEVER_H
#define SEVER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>
#include<sys/socket.h>
#include<pthread.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include<sqlite3.h>

#define MAX_CLIENT 12      //客户端上限
#define MY_PORT 8899    //服务端端口
#define BYTE_LEN 1024   //接受用户输出消息字符串长度

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;
typedef struct clientDetails
{
    //地址结构
    struct sockaddr_in addr;
    //客户端socket句柄
    int client_fd;
    //在线信息
    int is_online;
    //用户id
    int uid;
    //用户名称
    char username[32];
}client_details;

//初始化所需数据库
int initDatabase();
//初始化线程
int initSocket();
//初始化服务器
int initServer();
//监听函数
int acceptFunction();
//得到client句柄
int getUserFd(int ID);
//接受用户消息函数
void *listenCallbackFunction(void* arg);
//删除离线用户
void deleteClient(client_details* clt);
//处理客户端发来的字符串
void handleMsg(client_details* clt,char* msg);
//一对一发送消息
void sendSingalMsg(client_details* clt,char* submsg);
//用户注册
void registerUser(client_details* clt,char* submsg);
//用户登录
void userLogin(client_details* clt,char* submsg);
//用户登出
void userLogout(client_details* clt,char* submsg);
//发送一对一消息数据库回调函数
void sendSingalMsgCallbackFun(void* arg,int numCol,char** valueCol,char** nameCol);
//根据id得到用户的client_details
client_details* getClientDetails(int ID);
//检查用户是否已经登录 1表示登录，0未登录
int isLogined(int ID);
//给所有好友发送本人在线消息
void sendLoginMsg(client_details* clt);
//更新客户端群聊列表
void sendGroupList(client_details* clt);
//更新客户端好友列表
void sendFriendList(client_details* clt);
//给客户端发送离线消息
void sendOfflineUserMsg(client_details* clt);
//将添加好友的请求发给另一端
void sendRequestFriend(client_details* clt,char* msg);
//将被添加方消息处理给添加方
void backRequestFriend(client_details* clt,char* msg);
//发送加入的群聊列表
void sendGroupList(client_details* clt);
//发送群聊消息到客户端
void sendGroupMsg(client_details* clt,char* msg);
//加入群聊
void addGroup(client_details* clt,char* msg);
//
void sendSignalMsg(client_details* clt,char* msg);

void listenThreadFunction(void* arg);

// char* getUserName(int ID);
//发送群成员
// void sendGroupMember(client_details* clt,int groupID)
#endif 
