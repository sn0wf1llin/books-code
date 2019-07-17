#include <string.h>
#include <ctype.h>

void convert(char *str)
{
  while (*str != '\0') {
    *str=toupper(*str);
    ++str;
  }
}
int main(int argc, int *argv[])
{
  char buff[500];

  if (argc>1)
  {
    convert(argv[1]);
    strcpy(buff, argv[1]);
    printf("OK!\n");
} else
    printf("Enter argument!\n");

  return 0;
}
