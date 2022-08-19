//guard of head file
#ifndef WARP_H
#define WARP_H

#include<unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
int bind(int sockfd,const struct sockaddr*my_addr,socklen_t addrlen);
 int Socket(int domain, int type, int protocol);
 int Listen(int sockfd, int backlog);
 int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int Connect(int  sockfd,  const  struct sockaddr *serv_addr, socklen_t
       addrlen);
ssize_t Read(int fd, void *buf, size_t count);
ssize_t Write(int fd, const void *buf, size_t count);
int Close(int fd);
#endif
