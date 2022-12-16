// Server side implementation of UDP client-server model
#include "serv_cli.h"

int main() {
	printf("----------------------- Server UDP ----------------------- \n");
	struct sockaddr_in servaddr, cliaddr;
	int sockfd;
	
	//Server Response Format 
	Response* response=malloc(sizeof(Response));
	response->pid_serv=getpid();
  
	//Client Question Format 
	Question* question=malloc(sizeof(Question));
	char* buffer=malloc(sizeof(Question));
	
	//creation of the server socket and verification
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("[UDP server] Socket creation failed\n");
		exit(EXIT_FAILURE);
	}
		
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
		
    //Binding newely created socket to given Ip and verification
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,sizeof(servaddr)) < 0 )
	{
		perror("[UDP server] Bind failed");
		exit(EXIT_FAILURE);
	}
	printf("[UDP server] Bind to port %d", PORT);
		
	int len, n;
	len = sizeof(cliaddr); //len is value/result
		while(1){
			//the server reads the client request 
			int bytes_read=recvfrom(sockfd, (char *)buffer, sizeof(question),MSG_WAITALL, ( struct sockaddr *) &cliaddr,&len);
					if(bytes_read>00){
                      question=(Question*) buffer;
					  printf("\n[UDP server] Client %d : %d ",question->pid_client,question->qest);
                       int child=fork();
					   if(child==0){

							//the server generate an array with n random numbers
							int j=0;
							printf("Response [ ");
							while(j<(question->qest)){
							response->resp[j]=rand()%NMAX+1;
							printf(" %d ",response->resp[j]);
							j<(question->qest)-1 ? printf(" ,"):printf(" ");
							j++;
							}
							printf(" ]\n");
							//the server sends the response 
							sendto(sockfd, (char*)response, sizeof(Response),MSG_CONFIRM, (const struct sockaddr *) &cliaddr,len);
							printf("\n------------- What's the next request --------------\n");
							//break;
					   }
					}
				
			}
	
	
    close(sockfd);	
	return 0;
}

