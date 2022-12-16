// Client side implementation of UDP client-server model
#include "serv_cli.h"

int main() {
	
	struct sockaddr_in	 servaddr;
	int sockfd;
	  //generate n a random number between 1 and 10 
      int n;
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
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("[UDP Client] Socket creation failed");
		exit(EXIT_FAILURE);
	}
	printf("----------------------- Client UDP -----------------------\n");
	printf("[UDP Client] Client Socket is created.\n");
	
	memset(&servaddr, 0, sizeof(servaddr));	
	// Filling server information ,IP and PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
		
	int len;
	//client send the random generated number 
	sendto(sockfd, (char *)question, sizeof(question),MSG_CONFIRM, (const struct sockaddr *) &servaddr,sizeof(servaddr));
	//Recieving data from server 
		if(recvfrom(sockfd, (char *)buffer, sizeof(Response),
				MSG_WAITALL, (struct sockaddr *) &servaddr,
				&len) < 0){
			 /* in case of error recieving */
			 printf("[UDP Client] Error in receiving data.\n");
			 exit(1);
			
		}else{
			 /* the client reads the data recieved and show it on its own terminal */
			 response=(Response*) buffer;
			 printf("[UDP Client] N =  %d, Client PID = %d, Server PID = %d",n,question->pid_client,response->pid_serv);
			  int j=0;
					printf("\n[UDP Client] Server Response : [ ");
					while(j<(question->qest)){
					printf(" %d ",response->resp[j]);
					j<(question->qest)-1 ? printf(" ,"):printf(" ");
					j++;
						}
					printf(" ]\n");
					//close socke
					close(sockfd);

		}	
			
	return 0;
}

