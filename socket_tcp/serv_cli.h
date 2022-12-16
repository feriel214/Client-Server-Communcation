#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<time.h>
#define NMAX 10;
#define PORT 5005


//question structure 
typedef struct {
 int qest;
 int pid_client;
}Question;
//response structure 
typedef struct {
 int resp[200];
 int pid_serv;
}Response;

Response* sresponse;
Question* question;
