#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

volatile int var1;

void* ThreadFunction(void* arg) {
  pthread_setname_np(pthread_self(), "Thread1");
  uintptr_t loop_count = reinterpret_cast<uintptr_t>(arg);
  while (loop_count-- > 0) {
    for (volatile int i = 0; i < 1000000000; ++i) {
      ++var1;
    }
  }
  return nullptr;
}

volatile int var2;

__attribute__((noinline)) void MainThreadFunction(uintptr_t loop_count) {
  while (loop_count-- > 0) {
    for (volatile int i = 0; i < 1000000000; ++i) {
      ++var2;
    }
  }
}

int main(int argc, char** argv) {
  uintptr_t loop_count = 1;
  if (argc == 2) {
    loop_count = static_cast<uintptr_t>(atoi(argv[1]));
  }
  pthread_t thread;
  int ret = pthread_create(&thread, nullptr, ThreadFunction, reinterpret_cast<void*>(loop_count));
  if (ret != 0) {
    fprintf(stderr, "pthread_create failed %d\n", ret);
    return 1;
  }

  MainThreadFunction(loop_count);

  ret = pthread_join(thread, nullptr);
  if (ret != 0) {
    fprintf(stderr, "pthread_join failed %d\n", ret);
    return 1;
  }
  return 0;
}
