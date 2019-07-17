#include <stdio.h>
#include <stdlib.h>

#define $ /* */

#define ARGV argv

#define if($x) int main(int argc, char *argv[])

#define $start 1  

#if PERL
  sub atoi { $_[0] }
  $ argc=@ARGV;
  $ start=0;
  $ x=1;
#endif

if($x)
{
  int $ sum;
  int $ i;
  
  $ sum=0;

  for ( $ i = $start; $ i < $ argc ; $ i++) {
    $ sum += atoi ($ ARGV [$ i]);}

  printf("%d\n", $ sum);

exit(0);
}
