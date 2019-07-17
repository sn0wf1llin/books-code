#include <stdio.h>
#include <string.h>

void Ok()
{
  char buf[10];
  gets(buf);
  printf("You are loser!\n");
}

void No()
{
  printf("WOW! You are Cool Hacker! :)\n");
}

int main(int argc, char* argv[])
{

  printf("Password:"); 

  Ok();
  if (!strcmp("ivan", "sklyaroff"))
  No();

  return 0;
}
