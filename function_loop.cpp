__attribute__((noinline)) void Function1() {
  for (volatile int i = 0; i < 1; ++i) {
  }
}

__attribute__((noinline)) void Function2() {
  for (volatile int i = 0; i < 1; ++i) {
  }
}

__attribute__((noinline)) void FunctionLoop() {
  for (volatile int i = 0; i < 1000000000; ++i) {
    Function1();
    Function2();
  }
}

int main() {
  FunctionLoop();
  return 0;
}
