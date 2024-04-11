#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char **argv) {
  pid_t pid;
  int childStatus;

  pid = fork();

  if (pid < 0) {
    // error occurred
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    // child process
    execlp("/bin/ls", "ls", NULL); // replace itself with ls command 
  } else {
    // parent process, wait for child to complete
    wait(&childStatus);
    printf("Child Complete with status: %d\n", childStatus);
  }

  return 0;
}