#include <stdio.h>
#include <string.h>

#pragma data_seg(".ivan1")
  char login[]="Ivan\n";
#pragma data_seg()

#pragma data_seg(".ivan2")
  char pass[]=":obwcdt\n";
#pragma data_seg()

int main() {

  char buff1[256];
  char buff2[256];
  int i;

  printf("Enter login:");
    fgets(&buff1[0],256,stdin);

  printf("Enter password:");
    fgets(&buff2[0], 256,stdin);

  if (!strcmp(&login[0], &buff1[0])) {

    for (i=0; i<strlen(&buff2[0])-1; i++) {
      buff2[i]=(buff2[i]^5)-8;
	}
  
    if (!strcmp(&pass[0], &buff2[0]) &&
	  strcmp(&login[0], &pass[0])) {
      printf("\nYeees... You are cOOl HaCker!!!\n\n");
	  return 1;
	}
  }

  printf("\nHe he he. You are Lamer!\n\n");

return 0;
}
