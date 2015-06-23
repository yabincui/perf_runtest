#include <sys/prctl.h>

volatile int var1;

__attribute__((noinline)) void Function1() {
  for (volatile int i = 0; i <= 1000000000; ++i) {
    ++var1;
  }
}

volatile int var2;

__attribute__((noinline)) void Function2() {
  for (volatile int i = 0; i <= 1000000000; ++i) {
    ++var2;
  }
}

int main() {
  prctl(PR_SET_NAME, reinterpret_cast<unsigned long>("RUN_FUNCTION1"), 0, 0, 0);
  Function1();
  prctl(PR_SET_NAME, reinterpret_cast<unsigned long>("RUN_FUNCTION2"), 0, 0, 0);
  Function2();
  return 0;
}
