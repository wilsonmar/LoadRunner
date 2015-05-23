#!/usr/bin/env python3

# Ported from Perl by Chris Angelico 20150506
# Translation work licensed under the MIT license (so, go ahead, do what you like, only don't sue me)

# Sample call: python3 parsec.py Recording.c Action.commented.c

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

import sys
import time
import os.path

# HACK: Super-simplified argument parsing.
# For nicer parsing, investigate argparse or docopt (or a wrapper
# such as Clize or docstringargs)
me, input_filename = sys.argv
me = os.path.basename(me)

logging_time = time.strftime("%Y%m%dT%H%M",time.gmtime())
# Alternatively, set output_filename to input_filename to simply overwrite.
output_filename = (".parsed.%s"%logging_time).join(os.path.splitext(input_filename))

# Declare working flags:
comment_needs_completion = False # 0=NO to begin loop.
web_reg_found = False # Assuming no.
start_trans_found = end_trans_found = False

# Read the entire file into memory to allow the input and output file names to
# be identical if desired (though this is risky; an error that bombs the script
# will overwrite the file).
with open(input_filename, encoding="utf-8") as infile:
	lines = infile.readlines()

if me in lines[0]:
	print(">>> This file was already processed by %s.",me)
	sys.exit(0)

with open(output_filename, "w", encoding="utf-8") as out:
	print("// %s processed this file on %s."%(me, logging_time), file=out)
	for line_num, row in enumerate(lines):
		row = row.rstrip("\n")
		should_comment = False
		##### Before row processing: See if previous row completed a multi-line phrase:
		if comment_needs_completion:
			should_comment = True
			# TODO: This will notice a semicolon anywhere in the line.
			# It may be better to use row.has_suffix(";") instead.
			if ';' in row: comment_needs_completion = False

		##### Current row pre-processing:
		if "lr_think_time(" in row:
			should_comment = True
		elif "web_reg_find(" in row:
			web_reg_found = True
		elif "web_url(" in row or "web_submit(" in row or "web_custom_submit(" in row:
			if not web_reg_found:
				print("\t// web_reg_find(\"Text=???\",LAST); // TODO: Specify unique text to verify.", file=out)
				web_reg_found = True
			if not start_trans_found:
				print("\twi_start_transaction(); // TODO: Specify transaction name in {pTransName}.", file=out)
				start_trans_found = True

		# Main processing
		if "web_add_cookie(" in row:
			should_comment = True
			comment_needs_completion = ';' not in row
		
		if "lr_start_transaction(" in row:
			start_trans_found = True
			# TODO: Extract out transaction name field:
			print("\twi_start_transaction(); // in wi_functions.c", file=out)
			continue

		if "lr_end_transaction(" in row:
			end_trans_found = True
			print("\twi_end_transaction(); // in wi_functions.c", file=out)
			continue

		if should_comment:
			# Make sure we do this only once, even if multiple requirements tell us to comment it out
			print("\t// "+row.strip(), file=out)
		else:
			print(row, file=out)

	##### After line processing:
	if not end_trans_found: # add a line if a lr_start_transaction() was not generated.
		print("\t// wi_end_transaction(); // in wi_functions.c", file=out)
		end_trans_found = False

print(">>> %s done from %s to %s."%(me, input_filename, output_filename))
