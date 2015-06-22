#include <sys/wait.h>
#include <unistd.h>

__attribute__((noinline)) void ParentFunction() {
  for (volatile int i = 0; i < 1000000000; ++i) {
  }
}

__attribute__((noinline)) void ChildFunction() {
  for (volatile int i = 0; i < 1000000000; ++i) {
  }
}

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    ChildFunction();
    return 0;
  } else {
    ParentFunction();
    waitpid(pid, nullptr, 0);
  }
  return 0;
}
