#if PERL #define kkk 1 #endif
$ sum = 0;
for($ i = 0; $ i < @ ARGV ; $ i ++ ) {
  $ sum +=
    $ ARGV[$ i]
    ;
}
print $ sum;
