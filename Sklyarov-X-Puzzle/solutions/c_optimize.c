#include <stdio.h>

int main() {
  int A = 1;
  int B = -2;
  int n;

  n = A & 63;

  printf("A = %d B = %d --> n = %d\n", A, B, n);
  return 0;
}
