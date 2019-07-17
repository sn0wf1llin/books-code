#include <stdio.h>
#include <string.h>

void NoSecret()
{
  printf("You are loser!\n");
}

void Secret()
{
  printf("WOW! You are Cool Hacker! :)\n");
}

int main(int argc, char* argv[])
{
  char buf[10];
  char *s;
  int i=3;

  if (argc != 2) {
    printf("Usage: linepass2.exe <string>\n");
    return 1;
  }

  if (!strncmp(argv[1], "xxx", 3))
  {
    s=argv[1];

    while (s[i] != '\0') {
      s[i++]^=2;
    }

    strcpy(buf, s);    
    NoSecret();
  }

  if (!strcmp("ivan", "sklyaroff"))
  Secret();

  return 0;
}
