#include <stdio.h>

int fib(int n, int arr[2]) {
  for (int i = 0; i < n; i++){
    printf(" %d ", arr[0]);
    int tmp = arr[1];
    arr[1] = arr[0]+arr[1];
    arr[0] = tmp;
  }

}

int main(int argc, char* argv[]){
  int arr[2];
  arr[0]=0;arr[1]=1;
  fib(13, arr);
  return 0;
}
