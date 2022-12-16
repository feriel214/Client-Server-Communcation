#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>     
#define NMAX 10;
#define PORT 8080
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
