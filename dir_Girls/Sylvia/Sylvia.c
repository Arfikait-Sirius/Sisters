#include "Sylvia.h"

SylviaFunctions callSylvia( void ){
     SylviaFunctions _SylviaSkills = BIRTH_SYLVIA ;

     return _SylviaSkills ;
}

int mfnSylvia( int argc, char* argv[] ){

     return CHAO ;
}

int _SylviafnStrToNum( string data ){
     int num ;
     char* p ;

     num = 0 ;
     p = data ;
     while( *p != NL ){
          if( *p < 0x30 || 0x39 < *p ){
               logSisters(
                         ERR_MSG_NOT_NUMBER,
                         ERR,
                         "Sylvia"
                    ) ;
               return NL ;
          }
          num *= 10 ;
          num += *p++ - 0x30 ;
     }

     return num ;
}

int _SylviafnCalcStrExpression( string expression ){
     int result ;
     char operators[NUM_OF_OPERATOR] = { NL } ;
     int numbers[NUM_OF_NUMBERS] = { 0 } ;
     char* p ;
     char* q ;
     int i ;
     int j ;
     int x ;
     int y ;
     int z ;
     int tmp ;
     char* expressionTrimSpace ;
     bool priorityFlg = false ;
     bool numSetFlg ;

     expressionTrimSpace = malloc( sizeof( expression ) ) ;
     p = expression ;
     q = expressionTrimSpace ;
     while( *p != NL ){
          if( *p == SPACE ){
               p++ ;
               continue ;
          }
          *q++ = *p++ ;
     }
     *q = NL ;
     i = 0 ;
     j = 0 ;
     p = expressionTrimSpace ;
     while( *p != NL ){
          if( i == NUM_OF_NUMBERS ){
               x = 0 ;
               break ;
          }
          tmp = 0 ;
          while( CHAR_0 <= *p && *p <= CHAR_9 ){
               tmp += *p - CHAR_NUM_OFFSET ;
               if( CHAR_0 <= *( p + 1 ) && *( p + 1 ) <= CHAR_9 ){
                    tmp *= 10 ;
               }else{
                    x = tmp ;
                    break ;
               }
               p++ ;
          }
          z = NO_NUMBER ;
          numSetFlg = false ;
          if( *p == ASTERISK ){
               p++ ;
               tmp = 0 ;
               while( CHAR_0 <= *p && *p <= CHAR_9 ){
                    tmp += *p - CHAR_NUM_OFFSET ;
                    if( CHAR_0 <= *( p + 1 ) && *( p + 1 ) <= CHAR_9 ){
                         tmp *= 10 ;
                    }else{
                         y = tmp ;
                         break ;
                    }
                    p++ ;
               }
               z = _SylviafnMul( x, y ) ;
               priorityFlg = true ;
          }else if( *p == SLASH ){
               p++ ;
               tmp = 0 ;
               while( CHAR_0 <= *p && *p <= CHAR_9 ){
                    tmp += *p - CHAR_NUM_OFFSET ;
                    if( CHAR_0 <= *( p + 1 ) && *( p + 1 ) <= CHAR_9 ){
                         tmp *= 10 ;
                    }else{
                         y = tmp ;
                         break ;
                    }
                    p++ ;
               }
               z = _SylviafnDiv( x, y ) ;
               priorityFlg = true ;
          }else if( *p == PLUS || *p == MINUS ){
               operators[j++] = *p ;
               if( !priorityFlg ){
                    numSetFlg = true ;
               }
               priorityFlg = false ;
          }
          if( z != NO_NUMBER ){
               numbers[i++] = z ;
          }else{
               if( numSetFlg ){
                    numbers[i++] = x ;
               }
          }
          p++ ;
     }
     free( expressionTrimSpace ) ;
     numbers[i] = x ;
     operators[j] = NL ;
     result = sfnCalc( numbers, operators ) ;

     return result ;
}

int sfnCalc( int* numbers, char* operators ){
     int result ;

     result = *numbers++ ;
     while( *operators != NL ){
          if( *operators == PLUS ){
               result = _SylviafnAdd( result, *numbers ) ;
          }else if( *operators == MINUS ){
               result = _SylviafnSub( result, *numbers ) ;
          }
          numbers++ ;
          operators++ ;
     }

     return result ;
}

int _SylviafnAdd( int a, int b ){

     return a + b ;
}

int _SylviafnSub( int a, int b ){

     return a - b ;
}

int _SylviafnMul( int a, int b ){

     return a * b ;
}

int _SylviafnDiv( int a, int b ){

     if( b == 0 ){
          return NL ;
     }

     return a / b ;
}
