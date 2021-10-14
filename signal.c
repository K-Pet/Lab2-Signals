/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int isHandled;

void handler(int signum){ //signal handler
  isHandled = 1;
  printf("Hello World!\n");

}

int main(int argc, char * argv[]){
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1){
    isHandled = 0;
    alarm(1);
    while(isHandled == 0);
    printf("turing was right!\n");
  }
  return 0; //never reached
}