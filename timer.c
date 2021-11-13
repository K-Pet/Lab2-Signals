/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

//Credit to: Shail Pokharel & Shane Oliver

int alarmOn = 0;
int alarmNum = 0;

void handler(int signum){ 
  //signal handler
  printf("Hello World!\n");
  sleep(5);
  alarmOn = 1;
  alarmNum ++;
}

void handler2(int signum){
  int totalTime;
  stop = time(NULL);
  totalTime = stop - start;
  printf("Number of alarms was %d\n", alarmNum);
  printf("\nRuntime: %d \n", (int)runtime);
  
}

int main(int argc, char * argv[]){
  signal(SIGALRM, handler);
  signal(SIGALRM, handler2);
  start = time(NULL);
  
  while(1){
    alarmOn = 0;
    alarm(5);
    
    while(!alarmOn)
      ;
    printf("turing was right!\n");
  }
  return 0;
}