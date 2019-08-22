#include <stdio.h>
#include <stdlib.h>

#define $ /* */
$ i = 0;
$ sum = 0;
#define i 1
#define cstart int main(int argc, char* argv[]) {
  #define ARGV argv
#define ret return 0;}

#if PERL
  sub atoi {
    return $_[0];
  }
=pod
#endif
cstart
int j = i;
#if PERL
=cut
$ argc = @ARGV;
$ j = $ i ;
#endif

for( $ j ; $ j < $ argc ; $ j++) { $ sum += atoi( $ ARGV[$ j]) ; }
#if PERL
  print($ sum);
=pod
#endif
  printf("%d\n", sum);
#if PERL
=cut
#endif

#if PERL
=pod
#endif
ret
#if PERL
=cut
#endif
