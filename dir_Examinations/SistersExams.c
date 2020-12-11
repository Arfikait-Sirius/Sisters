#include "SistersExams.h"


#define INIT_FNP_LIST {\
     examForLouise,\
     examForSylvia,\
     examForVeera,\
     finish\
}


static void finish( void ) ;
static void spExamAll( fnp[] ) ;


int main( void ){
     static fnp list[] = INIT_FNP_LIST ;

     spExamAll( list ) ;

     return CHAO ;
}

static void finish( void ){

     return ;
}

static void spExamAll( fnp doListFn[] ){
     int num = 0 ;
     void ( *fnExam )( void ) ;

     fnExam = doListFn[num] ;
     fnExam() ;
     while( doListFn[num++] != finish ){
          fnExam = doListFn[num] ;
          fnExam() ;
     }

     return ;
}
