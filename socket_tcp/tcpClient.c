#include "serv_cli.h"
int main(){
	
	int clientSocket, ret;
	struct sockaddr_in serverAddr;
    int n;
      //generate n a random number between 1 and 10 
      srand(getpid());	
      n=rand()%NMAX+1;
	  //client question structure declaration
      Question *question=malloc(sizeof(Question));
      question->pid_client=getpid();
      question->qest=n;
	  //server response structure declaration
      Response* response=malloc(sizeof(Response));
      char* buffer=malloc(sizeof(Response));
      //socket create and verification 
	  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if(clientSocket < 0){
			printf("Error in connection.\n");
			exit(1);
		}

	printf("----------------------- Client TCP -----------------------\n");
	printf("[Client] Client Socket is created.\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));
	//Assign IP , PORT
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   //connect client socket to server socket and verification 
	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		/* Connection with server socket dosen't established */
		printf("[Client] Error in connection.\n");
		exit(1);
	}
		printf("[Client] Connected to Server.\n");

        //client send the random generated number 
		send(clientSocket, (char*)question, sizeof(question), 0);

        //Recieving data from server 
		if(recv(clientSocket, (char*)buffer, sizeof(Response), 0) < 0){
			/* in case of error recieving */
			 printf("[Client] Error in receiving data.\n");
			 exit(1);
			
		}else{
			/* the client reads the data recieved and show it on its own terminal */
			 response=(Response*) buffer;
			 printf("[Client] My PID = %d, Server PID = %d, Numbser = %d\n",question->pid_client,response->pid_serv,n);
			  int j=0;
					printf("\n[Client] Recieved Reponse : [ ");
					while(j<(question->qest)){
					printf(" %d ",response->resp[j]);
					j<(question->qest)-1 ? printf(" ,"):printf(" ");
					j++;	}
					printf(" ]\n");

		}			
		//close the socket
		close(clientSocket);

	return 0;
}
