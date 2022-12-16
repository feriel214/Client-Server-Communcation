#include "serv_cli.h"
int main(){
	printf("---------------- Server TCP ----------------\n");
	int sockfd, ret;
	struct sockaddr_in serverAddr;
	int newSocket;
	struct sockaddr_in newAddr;
	socklen_t addr_size;
	pid_t childpid;

	//Server Response Format 
	Response* response=malloc(sizeof(Response));
	response->pid_serv=getpid();
  
    //Client Question Format 
    Question* question=malloc(sizeof(Question));
    char* buffer=malloc(sizeof(Question));

    //creation of the server socket and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[Server] Error in connection.\n");
		exit(1);
	}
	printf("[Server] Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	//Assign IP , PORT
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //Binding newely created socket to given Ip and verification
	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("reeeeet %d  ",ret);
	if(ret < 0){
		printf("[Server] Error in binding.\n");
		exit(1);
	}
	printf("[Server] Bind to port %d\n", 5005);
    //Server is ready to listend and verification 
	if(listen(sockfd, 10) == 0){
		printf("[Server] My PID = %d \n",getpid());
		printf("[Server] Listening to clients requests ....\n");
	}else{
		printf("[Server] Error in binding.\n");
	}
	while(1){
		//accept the data packet from client and verification 
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("[Server] Connection accepted from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
		if((childpid = fork()) == 0){
			close(sockfd);
			while(1){
				//the server reads the client request 
				recv(newSocket,(char*)buffer, sizeof(question), 0);
                question=(Question*) buffer;
				//the server show the recieved Number
                printf("\n[Server] Client %d : %d ? \n",question->pid_client,question->qest);
                //server generate the appropriate response and show it on its terminal
				printf("\n[Server] Server Reponse : [");
                int j=0;
                while(j<(question->qest)){
                  response->resp[j]=rand()%NMAX+1;
                  printf(" %d ",response->resp[j]);
                  j<(question->qest)-1 ? printf(" ,"):printf(" ");
                  j++;
                }
                printf(" ]\n");
                //the server sends the response 
				send(newSocket, (char*)response, sizeof(Response), 0);
				printf("[Server] Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
				break;
			}
		}
	}
    //close server socket
	close(newSocket);
	return 0;
}




