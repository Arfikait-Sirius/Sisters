#!/bin/sh

gcc \
          SistersExams.c \
          ExamCommon.c \
\
          ./Exams/forLouise.c\
          ./Exams/forSylvia.c\
          ./Exams/forVeera.c \
\
     -L ../dir_Modules/ \
     -l Sisters \
\
     -o SistersExams

echo Completed!
