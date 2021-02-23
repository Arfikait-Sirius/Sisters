#!/bin/sh

gcc \
          SistersExams.c \
\
          ./Exams/forLouise.c \
          ./Exams/forDorothy.c \
          ./Exams/forSylvia.c \
          ./Exams/forVeera.c \
\
     -L ../dir_Modules/ \
     -l Sisters \
\
     -o SistersExams

echo Completed!
