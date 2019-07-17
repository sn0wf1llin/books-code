#include <stdio.h>

int main()
{
  unsigned int mask = 0x2C;
  unsigned int r[] = {0x24, 0x04, 0x32, 0x37};
  unsigned int i, j;
 
  for (i = 0; i < 64; i++)
  {
    if ((i & mask) - r[0]) continue;
    printf("======= %02X\n", i);
    printf("%02X = %02X AND ", r[0], i);
    for (j = 0; j < 64; j++)
      if((i & j) == r[0]) printf(" %02X", j);
    printf("\n");
    printf("%02X = %02X AND ", r[1], i);
    for (j = 0; j < 64; j++)
      if((i & j) == r[1]) printf(" %02X", j);
    printf("\n");
    printf("%02X = %02X XOR ", r[2], i);
    for (j = 0; j < 64; j++)
      if((i ^ j) == r[2]) printf(" %02X", j);
    printf("\n");
    printf("%02X = %02X OR  ", r[3], i);
    for (j = 0; j < 64; j++)
      if((i | j) == r[3]) printf(" %02X", j);
    printf("\n");
  }
  printf("\n");
}
