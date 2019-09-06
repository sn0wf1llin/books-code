#include <stdio.h>

int main() {
  int x, y, z, v, t;
  int counter, rightCounter;
  counter = 0;
  rightCounter = 0;

  for (int i = 0; i < 64; i++){
    x = i;
    for (int j = 0; j < 64; j++){
      y = j;
      for (int k = 0; k < 64; k++){
        z = k;
        for (int l = 0; l < 64; l++){
          t = l;
          for (int m = 0; m < 64; m++){
            v = m;

            if (((int)(x ^ y) == (int)0b110010) && ((int)(x | z) == (int)0b110111) && ((int)(x & t) == (int)0b100100) && ((int)(x & v) == (int)0b000100)) {
              printf(" found: x = %d y = %d z = %d v = %d t = %d\n", x, y, z, v, t);
              rightCounter++;
              counter++;
            } else {
              counter++;
            }
          }
        }
      }
    }
  }

  printf("Iterate over %d variants, found as right %d\n", counter, rightCounter);
  return 0;

}
