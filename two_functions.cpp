__attribute__((noinline)) void Function1() {
  for (volatile int i = 0; i <= 1000000000; ++i) {
  }
}

__attribute__((noinline)) void Function2() {
  for (volatile int i = 0; i <= 1000000000; ++i) {
  }
}

int main() {
  Function1();
  Function2();
  return 0;
}
