#!/bin/sh

gcc \
     ./$1/$1.c \
\
     -L ../dir_Modules/ \
     -l Sisters \
\
     -o ./$1/$1

echo Completed!
