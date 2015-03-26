#!perl

# $Id: conv_lr_c.pl,v 1.1 2014-08-11 09:34:12 wilsonmar@gmail.com Exp $ [MISCCSID]

# Sample call: perl conv_lr_c.pl --in Action.c --out Action.commented.c

# From http://github.com/wilsonmar/loadrunner/conv_lr_c.pl
# 1. Ensure you have perl that comes with LoadRunner 12.02 or before: perl -v
# 2. cd to the folder where your LoadRunner script/
# 3. Copy conv_lr_c.pl into the script folder.
# 4. Invoke "conv_lr_c.pl Action.c" (without the ") which specifies a C-language script generated within LoadRunner.
# 5. If no file is specified, this program looks for a .c file.
# 6. If no file is found, the program aborts.
# For each .c file found:
# 7. This program generates a file with a timestamp containing the specified file's contents.
# 8. The original file name contains updated by this program.
#    a. A comment is added in the first line to detect and prevent repeat executions.
#    b. Two slashes are added in front of any line containing "web_add_cookie(" or "lr_think_time".
#    c. Slashes are also added in front of continuing lines commented out but not completed with ;.

use 5.12.1; # version in LR 12.01
use utf8;
use strict;
use warnings;

use POSIX;
use File::Basename;
use Getopt::Long;

# Initialize variables:
my $logging_time = getLoggingTime(); # prints immediate!

my $file_in  = "";
my $file_out = "";

my $USAGE = "$0 --in <file to process> --out <file to write to>";

GetOptions("in=s"  => \$file_in,
           "out=s" => \$file_out) or die $USAGE;

if (! $file_in || ! -e $file_in){
    die "No input file specified or bad filename\n$USAGE";
}

# TODO: If *.c is specified, cycle through .c files within a LR script folder.
# process_one_file() defined below.

if (! $file_out){
    $file_out = $file_in . $logging_time . '.txt';
    print "No output file specified. Using default file $file_out\n";
}

open(my $f_in, '<:encoding(UTF-8)', $file_in) or die "Could not open file '$file_in': $!";
open(my $f_out, '>', $file_out) or die "Could not open '$file_out' for writing: $!";


my $prev_line_was_commented_out = 0; # 0=NO to begin loop.
my $seen_semicolon = 0;

while (my $row = <$f_in>) { # loop through lines:
    chomp $row;

    my $line_num = $.;

    if( $line_num == 1){ # in first or 2nd line.
        my $script_name = basename($0);
        if( $row =~ /$script_name/ ){
            print "This file was already processed by $script_name.\n";
            print $f_out ">> This file was already processed by $script_name.\n";
            exit 0; # abort run.
        }
        else{
            print $f_out "// $script_name processed this file $logging_time.\n";
        }
    }

    my $should_comment = 0;

    if( $prev_line_was_commented_out && ! $seen_semicolon){
        $should_comment = 1;
    }
    if( $row =~ /web_add_cookie\(/ || $row =~ /lr_think_time\(/){
        $should_comment = 1;
    }

    if ($row =~ /;/){
        $seen_semicolon = 1;
    }
    else {
        $seen_semicolon = 0;
    }

    if ($should_comment){
        print $f_out "$line_num>> // $row\n";
        $prev_line_was_commented_out = 1;
    }
    else{
        print $f_out "$line_num>> $row\n";
        $prev_line_was_commented_out = 0;
    }

}# while loop

close $f_in;
close $f_out;

print "$0 done from $file_in to $file_out\n";


sub getLoggingTime {
    my $tz = strftime("%z", localtime());

    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)=localtime(time);
    my $nice_timestamp = sprintf ( "%04d%02d%02dT%02d%02d%02d%s",
                                   $year+1900,$mon+1,$mday,$hour,$min,$sec,$tz);
    return $nice_timestamp;
}
