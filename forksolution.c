#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t pid;
  int child_result;
  int parent_result;

  pid = fork();

  if (pid < 0) {
    // fork failed
    return -1;
  } else if (pid == 0) {
    // child
    return execute_B();
  } else {
    // parent
    parent_result = execute_A();
    wait(&child_result);
  }

  if (child_result == 0 && parent_result == 0) {
    printf("Completed.\n");
    return 0;
  }

  if (child_result != 0) {
    printf("Error %d Occured.\n", child_result);
  }
  if (parent_result != 0) {
    printf("Error %d Occured.\n", parent_result);
  }

  return -1;
}
