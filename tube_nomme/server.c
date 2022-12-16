#include "serv_cli_fifo.h"
#include "Handlers_serv.h"
int main(){
       
   //////////////////////////////////////////////////////////////////////
   /**
   * Declarations : 
   * @Question client structure && @Response Server structure  
   */
    //////////////////////////////////////////////////////////////////////
 
   //Server Response Format 
   Response* response=malloc(sizeof(Response));
   response->pid_serv=getpid();
  

   //Client Question Format 
   Question* question=malloc(sizeof(Question));
   char* data=malloc(sizeof(Question));


   /**
    * Creation of named pipe 
    * @create both fifo1 and fifo2 and mode assignement
    */
       
       
      if(mkfifo("fifo1",0777)<0){
       perror("mkfifo error ! ");
       exit(3);
       }
       if(fifo2=mkfifo("fifo2",0777)<0){
       perror("mkfifo error ! "); 
       exit(3);
       }
       
      printf("************ Hello I am the server My PID =%d  *********",getpid());

       /** Open named pipe  fifo1 to read clients questions */
       fifo1=open("fifo1",O_RDONLY);
       fifo2=open("fifo2",O_WRONLY);

       //handlers Installation 
       for(int i=0;i<NSIG;i++){
       signal(i,fin_serveur);  
       }
       signal(SIGUSR1,hand_reveil);

       
       srand(time(0));
       while(1){
           if(read(fifo1,data,sizeof(Question))!=0){
               question=(Question*) data;
               printf("\nClient %d : %d ? \n",question->pid_client,question->qest);
               printf("\nServer Reponse : [");

                //the server generate an array with n random numbers
                int j=0;
               
                while(j<(question->qest)){
                  response->resp[j]=rand()%NMAX+1;
                  printf(" %d ",response->resp[j]);
                  j<(question->qest)-1 ? printf(" ,"):printf(" ");
                  j++;
                }
                printf(" ]\n");
                //the server writes the response on fifo2
                write(fifo2,(char*)response,sizeof(Response));
                //the server notify the client with SIGUSR1 signal 
                kill(question->pid_client,SIGUSR1);
           }
       }


  //we close the pipes fifo1 & fifo2 
   close(fifo1);
   close(fifo2);



}
