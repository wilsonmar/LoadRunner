#!perl

# $Id: parsec.pl,v 1.1 2014-08-11 09:34:12 wilsonmar@gmail.com

# Sample call: perl parsec.pl --in Recording.c --out Action.commented.c

# From http://github.com/wilsonmar/loadrunner/parsec/parsec.pl
# 1. Ensure that perl version 5.12.1 that comes with LoadRunner 12.02 can process the script.
# 2. cd to the folder where your LoadRunner script/
# 3. Copy parsec.pl into the script folder. QUESTION: This required?
# 4. Invoke "parse.pl Recording.c" (without the ") which specifies a C-language script generated within LoadRunner.
# 5. If no file is specified, this program looks for a .c file.
# 6. If no file is found, the program aborts.
# 7. This program generates a file with a timestamp containing the specified file's contents.
#    The timestamp should contain the local time zone abbreviation.
# 8. After processing, the original file name should contain text output by this program.
#    That's unless a run parameter requests otherwise.
# 9. A line remains unchanged unless:
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
# Aakash start
my $UTC_OFFSET_HOUR = -3;
my $input_filename ="";
my $output_filename ="";
#Aakash End

my $file_in  = "";
my $logging_time = getLoggingTime(); # prints immediate!
my $file_out = "";
my $file_switch  = "";
#my $file_temp = "";  ## commented by Aakash No Need for this

my $USAGE = "$0 --in <file to process> --out <file to write to>";

GetOptions("in=s"  => \$file_in,
           "out=s" => \$file_out,
           "switch=s" => \$file_switch
           ) or die $USAGE;

if (! $file_in || ! -e $file_in){
    die ">>> No --in file specified.\n$USAGE";
}

if (! $file_out){
	#$file_out = $file_in . '_' . $logging_time . '.c';
    print ">>> No output file specified.\n";
}

#START : Fetching input filename ## Aakash

my ($name,$path,$suffix) = fileparse($file_in,qr"\..[^.]*$");
	$input_filename= $name;
	#print $name


($name,$path,$suffix) = fileparse($file_out,qr"\..[^.]*$");
	$output_filename= $name.$suffix;
	#print $name
#END

$file_out = 'tmp'.$logging_time . '.txt'; # Added by Aakash

#$file_temp = $file_in . '_' . $logging_time . '.c.txt';  ## commented by Aakash No Need for this
	  
open(my $f_in, '<:encoding(UTF-8)', $file_in) or die ">>> Could not open file '$file_in': $!";
open(my $f_out, '>', $file_out) or die ">>> Could not open '$file_out' for writing: $!";

# Declare working flags:
my $comment_needs_completion = 0; # 0=NO to begin loop.
my $should_comment = 0; # Assuming no.
my $web_reg_find = 0; # Assuming no.

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
        $should_comment = 1; # 1=Yes, comment this line out.
        if ($row =~ /;/){ # in current row:
           $comment_needs_completion = 0;
        }else{
           $comment_needs_completion = $line_num + 1; # 1=Yes.
       }
    }

	if( $row =~ /lr_think_time\(/){ # TODO: substitute rather than replace to retain number in function.
        $should_comment = 1; # 1=Yes, comment this line out.
		# lr_think_time(32); not needed because it's handled within wi_start_transaction(); 
 	}elsif( $row =~ /web_reg_find\(/){ # response check logic encountered.
		$web_reg_find = 1;
	}elsif( $row =~ /web_url\(/){ # web_url() encountered.
		if( $web_reg_find == 0 ){ # add a line if a web_reg_find was not generated.
			print $f_out "\t// web_reg_find(\"Text=???\",LAST);\n";
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
 
	}elsif( $row =~ /lr_start_transaction\(/){
        $should_comment = 0; 
 		
		# TODO: Extract out transaction name field:
        print $f_out "\twi_start_transaction(); // in wi_functions.c\n";

	}elsif( $row =~ /lr_end_transaction\(/){
        print $f_out "\twi_end_transaction(); // in wi_functions.c\n";

	}else{
        print $f_out "$row\n"; # all other lines print out as is.
    }
    
}# while loopThis should be commented out 

close $f_in;
close $f_out;

# TODO: Switch file names so no one is the wiser for the processing.
#    if( $file_switch == "no" ){ 
        # skip renaming is default action
#    }else{
#        rename $f_in,   $f_temp
#        rename $f_out,  $f_in
#    }

# START : Switching the files. ## Added by Aakash
if( $file_switch eq 'no' ){ 
        # skip renaming is default action
    }
else{
       rename $file_in, $logging_time.'.txt'  || die ( "Error in renaming input file to .txt file" );

       rename $file_out,  $input_filename.'.c' || die ( "Error in renaming output file to .c file" );
}
# END

print ">>> $0 done from $file_in to $output_filename\n";


sub getLoggingTime {
	#START : to add UTC time and return a date time string for filename.
	my $START_YEAR = 1900;
	# my $tz = strftime("%z", localtime()); ## Use this if you need to show the offset code. Currently the time itself is UTC-3.00

	my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)  = gmtime();

	my $nice_timestamp = sprintf("%04d%02d%02dT%02d%02d",$year+$START_YEAR,$mon+1,$mday,$hour + $UTC_OFFSET_HOUR,$min);
	#print $nice_timestamp;
	# END 

## START : Prev code commented
# my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)=localtime(time);
#   my $nice_timestamp = sprintf ( "%04d%02d%02dT%02d%02d%02d%s",
#                                 $year+1900,$mon+1,$mday,$hour,$min,$sec,$tz);
#print $nice_timestamp;
## END 

	return $nice_timestamp;
}
