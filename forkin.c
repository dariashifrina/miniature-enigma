#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main(){
  srand(time(NULL));
  int f, t;
  printf("Zoo wee mama!\n");

  fork();
  //  f = fork(); //fork() returns the PID of the child process
  t = rand() % 15 + 5;
  if (f == 0) {
    sleep(t); //child is asleep for t seconds!
    printf("I'm a child: %d\t f:%d\tparent: %d\t waited for: %d seconds\n", getpid(), f, getppid(), t);
    printf("I, the child, am finished.\n");
  } else {
    printf("waiting for lazy child\n");
    wait(&t); //wait for child to sleep for 2 seconds!
    printf("I'm a parent: %d\t f:%d\tparent: %d\n", getpid(), f, getppid());
  }
  return 0;
}
