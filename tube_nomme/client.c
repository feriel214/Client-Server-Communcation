#include "serv_cli_fifo.h"
#include "Handlers_serv.h"
int main(){

   //////////////////////////////////////////////////////////////////////
   /**
   * Declarations : 
   * random integer n 
   * @Question client structure && @Response Server structure  
   *
   */
    //////////////////////////////////////////////////////////////////////
   int n;
   srand(time(0));
   n=rand()%NMAX+1;  
   char str[200];
   Question *question=malloc(sizeof(Question));
   question->pid_client=getpid();
   question->qest=n;
   Response* response=malloc(sizeof(Response));
   char* data=malloc(sizeof(Response));

   //////////////////////////////////////////////////////////////////////
   /** 
   * Open named pipe 
   * @fifo1 :the client read and the server read 
   * @fifo2 :the server write and the client read 
   */
   //////////////////////////////////////////////////////////////////////

   //the client opened fifo2 pipe to read server response 
    fifo1=open("fifo1",O_WRONLY);
    fifo2=open("fifo2",O_RDONLY);

    //we notify the server with SIGUSR1 signal to wake up him 
    signal(SIGUSR1,hand_reveil);
   
    if(fifo1<0 ) {
        perror("error open fifo ");
        exit(2);
    }
    //The list of available questions thatclient can ask 
    printf("\n ************ Hello I am client with PID = %d ,i send %d  *********",getpid(),n);

        //the client write his question inthe terminal thew we write it into fifo1 pipe
        write(fifo1,(char*)question,sizeof(Question)); 
        if(fifo2<0 ) {
            perror("error open fifo ");
            exit(2);
        }
        pause();
        read(fifo2,data,sizeof(Response));
        //the client show the response of the server 
        response=(Response*) data;
      
        int j=0;
                printf("\nReponse : [ ");
                    while(j<(question->qest)){
                    printf(" %d ",response->resp[j]);
                    j<(question->qest)-1 ? printf(" ,"):printf(" ");
                        j++;
                }
                printf(" ]\n");
                
        
     

 
    //the client send SIGUSR1 signal to the server to tell him that he complete reading & to tell him the his session finished .
    kill(response->pid_serv,SIGUSR1);
    signal(SIGUSR1,fin_serveur);


   //we close the pipes fifo1 & fifo2 
   //close(fifo1);
   //close(fifo2);


   
   return 0;


}
