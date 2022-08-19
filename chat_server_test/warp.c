#include"warp.h"
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int n = accept(sockfd,addr,addrlen);
again:
	if(n < 0)
	{
		if(n == EINTR)
		{
			goto again;
		}
		else
		{
			perror("accept error");
		}

	}
	return n;
}
int Listen(int sockfd, int backlog)
{
	int n = listen(sockfd,backlog);
	if(n == -1)
	{
		perror("listen error");
		return -1;
	}
	return n;
}
int Bind(int   sockfd,  const  struct  sockaddr  *my_addr,  socklen_t addrlen)
{
	int n = bind(sockfd,my_addr,addrlen);
	if(n < 0)
	{
		perror("bind error");
	}
	return n;
}
int Socket(int domain, int type, int protocol)
{
	int n = socket(domain,type,protocol);
	if(n == -1)
	{
		perror("socket error");
		return -1;
	}
	return n;
}
int  Connect(int  sockfd,  const  struct sockaddr *serv_addr, socklen_t
       addrlen)
{
	int n = connect(sockfd,serv_addr,addrlen);
	if(n < 0)
	{
		perror("connect error");
	}
	return n;
}
ssize_t Read(int fd, void *buf, size_t count)
{
	ssize_t n;
again:
	n = read(fd,buf,count);
	if(n < 0)
	{
		if(n == EINTR)
		{
			goto again;
		}
		else
		{
			perror("read error");
		}
	}
	return n;
}
ssize_t Write(int fd, const void *buf, size_t count)
{
	ssize_t n;
again:
	n = write(fd,buf,count);
	if(n == -1)
	{
		perror("write error");

	}
	return n;
}
int Close(int fd)
{
	int n = close(fd);
	if(n < -1)
	{
		perror("close error");
	}
	return n;
}
