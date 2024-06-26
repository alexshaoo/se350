#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>


struct msg {
  long mtype;
  int data;
}

int main(int argc, char** argv) {
  int msgqid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

  int pid = fork();
  if (pid > 0) {
    // parent
    struct msg m;
    m.mtype = 42;
    m.data = 252;
    msgsnd(msgqid, &m, sizeof(int), 0);
  } else if (pid == 0) {
    // child
    strcut msg m2;
    msgrcv(msgqid, &m2, sizeof(int), 42, 0);
    printf("Received: %d!\n", m2.data);
    msgctl(msgqid, IPC_RMID, NULL);
  }
  return 0;
}
