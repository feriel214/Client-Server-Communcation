#include<stdio.h>
int main(){
fork();
fork();
execlp("./client","./client");
}
