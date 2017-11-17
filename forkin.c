/* 
Queenie Xiang and Dasha Shifrina 
Systems pd5
HW12: Please Fork Responsibly
2017-11-16
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main(){
  //Creating variables 
  int f1, f2, t, signal;

  //Seeding rand() with time 
  srand(time(NULL));

  
  printf("Zoo wee mama! Starting forking! \n");
  printf("*****************************\n");
  printf("I'm parent: %d\t f:%d\t\n", getpid(), f1);


  f1 = fork(); //Creating first fork 
  
  if (f1 == 0) {
    t = rand() % 15 + 5;
    //signal = t; 
    sleep(t);
    printf("Hi, I'm child 1: %d\t f:%d\t Parent: %d\t Slept for: %d seconds\n", getpid(), f1, getppid(), t);
    printf("I, child 1, am finished.\n");
    printf("*****************************\n");
    return t; 
  }
  
  else {
    printf("*****************************\n");
    f2 = fork();
    if (f2 == 0) {
      t = rand() % 15 + 5;
      sleep(t); 
      printf("Hi, I'm child 2: %d\t f:%d\t Parent: %d\t Slept for: %d seconds\n", getpid(), f2, getppid(), t);
      printf("I, child 2, am finished.\n");
      printf("*****************************\n");
      signal = t;
      return t; 
    }

    else {
      printf("Waiting for lazy child...\n");
      printf("*****************************\n");
      wait(&signal);
      //WEXITSTATUS will return whatever the child returned before exiting 
      printf("Child slept for: %d\n seconds", WEXITSTATUS(signal)); 
    }
  }
  
  return 0;
}
