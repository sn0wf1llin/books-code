int main (int argc, char *argv[])
{
char buff[100];

if (argc>1) {
   strcpy(buff, argv[1]);
   printf("OK!\n");
} else
   printf("Enter argument!\n");

return 0;
}
