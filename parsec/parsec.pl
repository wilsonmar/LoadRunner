#!perl

# $Id: parsec.pl,v 1.1 2014-08-11 09:34:12 wilsonmar@gmail.com Exp $ [MISCCSID]

# Sample call: perl parsec.pl --in Recording.c --out Action.commented.c

# From http://github.com/wilsonmar/loadrunner/parsec.pl
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

# use 5.12.1; # 5.12.1 version in LR 12.01 # version 5.8.8 for mysysgit
use utf8;
use strict;
use warnings;

use POSIX;
use File::Basename; # for GetOptions()
use Getopt::Long;   # for GetOptions()

# Initialize variables:
my $file_in  = "";
my $logging_time = getLoggingTime(); # prints immediate!
my $file_out = "";
my $file_switch  = "";
my $file_temp = "";

my $USAGE = "$0 --in <file to process> --out <file to write to>";

GetOptions("in=s"  => \$file_in,
           "out=s" => \$file_out,
           "switch=s" => \$file_switch
           ) or die $USAGE;

if (! $file_in || ! -e $file_in){
    die ">>> No --in file specified.\n$USAGE";
}

if (! $file_out){
    $file_out = $file_in . '_' . $logging_time . '.c';
    print ">>> No output file specified, so it's $file_out.\n";
}

    $file_temp = $file_in . '_' . $logging_time . '.c.txt';
	
open(my $f_in, '<:encoding(UTF-8)', $file_in) or die ">>> Could not open file '$file_in': $!";
open(my $f_out, '>', $file_out) or die ">>> Could not open '$file_out' for writing: $!";

# Declare working flags:
my $comment_needs_completion = 0; # 0=NO to begin loop.
my $should_comment = 0; # Assuming no.

while (my $row = <$f_in>) { # loop through lines:
    chomp $row;

    my $line_num = $.;

    if( $line_num == 1){ # in first or 2nd line.
        my $script_name = basename($0);
        if( $row =~ /$script_name/ ){
            print ">>> This file was already processed by $script_name.\n";
            print $f_out ">>> This file was already processed by $script_name.\n";
            exit 0; # abort run.
        }else{
            print $f_out "// $script_name processed this file on $logging_time.\n";
        }
    }

    # If previous row did not complete a multi-line phrase:
    if( $line_num == $comment_needs_completion ){ 
 #       print $f_out "A: comment_needs_completion = $comment_needs_completion & should_comment = $should_comment\n";
           $should_comment = 1; # 0=No
        if ($row =~ /;/){ # in current row:
           $comment_needs_completion = 0;
        }else{
           $comment_needs_completion = $line_num + 1; # 1=Yes.
       }
    }

    if( $should_comment == 1 ){ 
        print $f_out "\t// $row\n";
        $should_comment = 0;

    # Comment out multiple lines until a semicolon is found to end the multi-line phrase:
	}elsif( $row =~ /web_add_cookie\(/){ # if row contains web_add_cookie:
        print $f_out "\t// $row\n";
        if ($row =~ /;/){ # in current row:
            $comment_needs_completion = 0; # 0=No.
        }else{
            $comment_needs_completion = $line_num + 1; # 1=Yes.
        }
 
	}elsif( $row =~ /lr_think_time\(/){ # TODO: substitute rather than replace to retain number in function.
        print $f_out "\tlr_think_time( floatThinkTime ); // TODO: substitute so number remains, and only once.\n";

	}elsif( $row =~ /lr_start_transaction\(/){
		# TODO: Extract out transaction name field:
		
        print $f_out "\tlr_save_string(\"url\",\"pTransName\");\n";
        print $f_out "\twi_start_transaction(); // in wi_functions.c\n";

	}elsif( $row =~ /lr_end_transaction\(/){
        print $f_out "\twi_end_transaction(); // in wi_functions.c\n";

	}else{
        print $f_out "$row\n"; # all other lines print out as is.
    }
    
}# while loop

close $f_in;
close $f_out;

# TODO: Switch file names so no one is the wiser for the processing.
#    if( $file_switch == "no" ){ 
        # skip renaming is default action
#    }else{
#        rename $f_in,   $f_temp
#        rename $f_out,  $f_in
#    }

print ">>> $0 done from $file_in to $file_out\n";


sub getLoggingTime {
    my $tz = strftime("%z", localtime());

    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)=localtime(time);
    my $nice_timestamp = sprintf ( "%04d%02d%02dT%02d%02d%02d%s",
                                   $year+1900,$mon+1,$mday,$hour,$min,$sec,$tz);
    return $nice_timestamp;
}
