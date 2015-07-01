volatile int var1;
volatile int var2;

__attribute__((noinline)) void FunctionRecursive(int loop) {
  if (loop == 0) {
    return;
  }
  for (int i = 0; i < 300000000; ++i) {
    ++var1;
  }
  FunctionRecursive(loop - 1);
  for (int i = 0; i < 300000000; ++i) {
    ++var2;
  }
}

int main() {
  FunctionRecursive(4);
  return 0;
}
