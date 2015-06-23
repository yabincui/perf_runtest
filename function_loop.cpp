volatile int var1;

__attribute__((noinline)) void Function1() {
  for (int i = 0; i < 5; ++i) {
    ++var1;
  }
}

volatile int var2;
__attribute__((noinline)) void Function2() {
  for (int i = 0; i < 5; ++i) {
    ++var2;
  }
}

__attribute__((noinline)) void FunctionLoop() {
  for (volatile int i = 0; i < 100000000; ++i) {
    Function1();
    Function2();
  }
}

int main() {
  FunctionLoop();
  return 0;
}
