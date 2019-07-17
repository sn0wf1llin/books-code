#include <stdio.h>

int main (int argc, char *argv[])
{
  FILE *in, *out;
  char *key;
  int byte;
 
  if (argc !=4) {
    printf ("Usage: xorer <key> <input_file> <output_file>\n");
    return 1;
  }

  key = argv[1];

  if ((in = fopen(argv[2], "rb")) != NULL) {
    if ((out = fopen(argv[3], "wb")) != NULL) {

      while ((byte = getc(in)) != EOF)
	  {
        if (!*key) key = argv[1]; 
          byte^= *(key++);
        putc(byte,out);
	  }

    fclose(out); } 
  fclose(in); }

  return 0;
}
