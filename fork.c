#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  printf("%d about to create 2 child processes\n", getpid());
  pid_t a, b;
  (a = fork()) && (b = fork());
  if (a < 0 || b < 0) {
    perror("Fork fail");
    exit(1);
  }
  else if (a == 0 || b == 0) {
    srand(getpid());
    int k = rand() % 5 + 1;
    printf("%d %dsec\n", getpid(), k);
    sleep(k);
    printf("%d finished after %dsec\n", getpid(), k);
    return k;
  }
  else {
    printf("Main process %d is done.", getpid());
    int status;
    wait(&status);
    if (WIFEXITED(status)) {
      int exit_status = WEXITSTATUS(status);
      printf(" Child slept for %dsec\n", exit_status);
    }
  }
  return 0;
}
