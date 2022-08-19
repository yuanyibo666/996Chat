#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<errno.h>
//#include<signal.h>
//#include<pthread.h>
#include<arpa/inet.h>
#include"warp.h"

#define SRV_PORT 8888
#define MAX_SIZE 1024

int main()
{
	int lfd;
	char buf[MAX_SIZE] = {0};
	struct sockaddr_in srv_addr;	
	bzero(&srv_addr,sizeof(srv_addr));

	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(SRV_PORT);
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	lfd = Socket(AF_INET,SOCK_STREAM,0);

	Bind(lfd,(struct sockaddr* )&srv_addr,sizeof(srv_addr));
	
	Listen(lfd,10);

	int cfd;
//	struct sockaddr_in clt_addr;
//	bzero(&clt_addr,sizeof(clt_addr));
//	socklen_t clt_addr_len = sizeof(clt_addr);
	
	pid_t pid;
	while(1)
	{
		cfd = Accept(lfd,NULL,NULL);
		pid = fork();
		if(pid < 0)
		{
			perror("fork error");
			return -1;
		}
		//subprocess
		else if(pid == 0)
		{
			Close(lfd);
			break;
		}
		//father process
		else
		{
			Close(cfd);
			continue;
		}
	}

	// subprocess 
	if(pid == 0)
	{	
		while(1)
		{
			bzero(buf,sizeof(buf));
			int ret = Read(cfd,buf,sizeof(buf));
			if(ret == 0)
			{
				Close(cfd);
				exit(1);
			}
			printf("%s\n",buf);
			char re[10] = "recived";
			Write(cfd,re,sizeof(re));
		}
	}
}
