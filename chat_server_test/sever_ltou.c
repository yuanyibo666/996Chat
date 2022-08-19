#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>
#include<ctype.h>
#include<sys/socket.h>
int main()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in myaddr;
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(8888);
	myaddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(fd,(struct sockaddr* )&myaddr,sizeof(myaddr))==-1)
	{
		perror("bind");
		return -1;
	}
	if(listen(fd,5)==-1)
	{
		perror("listen");
		return -1;
	}
	
	struct sockaddr_in clientAddr;
//	int fd1 = accept(fd,(struct sockaddr*)&clientAddr,NULL);
	int fd1 = accept(fd,NULL,NULL);
	if(fd1 == -1)
	{
		perror("accept error");
		return -1;
	}
	while(1)
	{
		char buf[1024] = {0};
		memset(buf,0,sizeof(buf));
		int len = read(fd1,buf,sizeof(buf));
		if(len >1)
		{
			int i;
			for(i = 0; i < len; i++)
			{
				buf[i] = toupper(buf[i]);
			}
			printf("%s\n",buf);
			write(fd1,buf,len);
		}
		else if(len == 0)
		{
			printf("break");
			break;
		}
		else
		{
			perror("read");
		}
	}
	return 0;
}
