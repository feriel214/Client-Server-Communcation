#include<stdio.h>
#include<signal.h>

void hand_reveil(int sig){
    printf("\n*********** Iam wake up i recieve your signal ********\n");
 }

void fin_serveur(int sig ){
    unlink("fifo1");
    unlink("fifo2");
exit(0);
}






