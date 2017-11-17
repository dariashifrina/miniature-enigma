/* 
Queenie Xiang and Dasha Shifrina 
Systems pd5
HW12: Please Fork Responsibly
2017-11-16
*/
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main(){
  //Creating variables 
  int  signal;
  pid_t f1,f2;

  //Seeding rand() with time 
  srand(time(NULL));

  
  printf("Zoo wee mama! Starting le fork! \n");
  printf("*****************************\n");
  printf("I'm parent: %d\t f:%d\t\n", getpid(), f1);


  f1 = fork(); //Creating first fork
  if(f1){
    printf("Waiting for lazy children...\n");
    printf("*****************************\n");
    wait(&signal);
    printf("Child slept for: %d seconds\n", WEXITSTATUS(signal)); 
  }
  if (f1 == 0) {
    int t = rand() % 15 + 5;
    printf("Hi, I'm child 1: %d\t f:%d\t Parent: %d\t Sleeping for: %d seconds\n", getpid(), f1, getppid(), t);
    sleep(t);
    printf("I, child 1, am finished.\n");
    printf("*****************************\n");
    exit(t);
  }
  
  else {
    printf("*****************************\n");
    f2 = fork();
    if (f2 == 0) {
      rand();
      int t = rand() % 15 + 5;
      printf("Hi, I'm child 2: %d\t f:%d\t Parent: %d\t Sleeping for: %d seconds\n", getpid(), f2, getppid(), t);
      sleep(t); 
      printf("I, child 2, am finished.\n");
      printf("*****************************\n");
      exit(t); 
    }

    else {
      wait(&signal);
    }
  }
  
  return 0;
}
