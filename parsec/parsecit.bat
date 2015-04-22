@echo off
REM This is from http://github.com/wilsonmar/LoadRunner/parsec/parsecit.bat
REM Copy this file to the script folder you are working on, then run:
REM Assuming that you recording into the Recording.c file:
REM c:\LoadRunner\parsec\

perl parsec.pl  --in Recording.c
pause
