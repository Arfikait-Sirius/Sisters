#include "ExamCommon.h"

void dispExamGirl( char* girlName ){

     printf( "%s%s\n", LABEL_GIRLS_NAME, girlName ) ;

     return ;
}

void dispExamTarget( char* target ){

     printf( "%s%s()\n", LABEL_TARGET, target ) ;

     return ;
}

void dispResultOK( void ){

     printf( "%sOK\n", LABEL_EXAM ) ;

     return ;
}

void dispResultNG( void ){

     printf( "%sNG\n", LABEL_EXAM ) ;

     return ;
}
