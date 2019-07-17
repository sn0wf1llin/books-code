#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char buff[100];
  char *env;

  if (argc==2) {
    env=getenv(argv[1]);
    if (env == NULL) exit (0);
    sprintf(buff, "%s", env);
  } else
    printf("Enter argument!\n");

  return 0;
}
