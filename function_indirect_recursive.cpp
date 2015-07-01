volatile int var1;
volatile int var2;
volatile int var3;
volatile int var4;

void FunctionRecursiveTwo(int loop);

__attribute__((noinline)) void FunctionRecursiveOne(int loop) {
  if (loop == 0) {
    return;
  }
  for (int i = 0; i < 100000000; ++i) {
    ++var1;
  }
  FunctionRecursiveTwo(loop);
  for (int i = 0; i < 100000000; ++i) {
    ++var2;
  }
}

__attribute__((noinline)) void FunctionRecursiveTwo(int loop) {
  if (loop == 0) {
    return;
  }
  for (int i = 0; i < 100000000; ++i) {
    ++var3;
  }
  FunctionRecursiveOne(loop - 1);
  for (int i = 0; i < 100000000; ++i) {
    ++var4;
  }
}

int main() {
  FunctionRecursiveOne(4);
  return 0;
}
