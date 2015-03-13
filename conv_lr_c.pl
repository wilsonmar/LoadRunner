#!perl

# $Id: readfile.pl,v 1.1 2014-08-11 09:34:12 wilsonmar@gmail.com Exp $ [MISCCSID]

# From http://github.com/wilsonmar/loadrunner/readfile.pl
# Thanks to http://perlmaven.com/beginner-perl-maven-video-course and http://perlmaven.com/perl-tutorial
# Re-Writes new file with comment characters in front any line containing lr_think_time.

use 5.12.1;
use utf8;
use strict;
use warnings;
use autodie;
 
my $file_in  = 'conv_lr_c.pl';
my $file_out = 'conv_lr_c_converted.pl';

open(my $f_in, '<:encoding(UTF-8)', $file_in)
  or die "Could not open file '$file_in' $!";

open(my $f_out, '>', $file_out);
 
while (my $row = <$f_in>) {
  chomp $row;
  if( $row =~ /lr_think_time/ ){
	print $f_out "// $row\n";
  }else{
	print $f_out "$.>> $row\n"; # $. is shortcut for line number.
  }
}# while loop

close $f_in;
close $f_out;

say "done after $.\n";
