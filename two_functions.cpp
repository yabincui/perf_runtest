volatile int var1;

__attribute__((noinline)) void Function1() {
  for (int i = 0; i <= 1000000000; ++i) {
	  ++var1;
  }
}

volatile int var2;
__attribute__((noinline)) void Function2() {
  for (int i = 0; i <= 1000000000; ++i) {
    ++var2;
  }
}

int main() {
  Function1();
  Function2();
  return 0;
}
