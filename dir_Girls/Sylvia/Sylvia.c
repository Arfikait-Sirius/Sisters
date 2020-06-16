#include "Sylvia.h"

SylviaFunctions callSylvia( void ){
     SylviaFunctions _SylviaSkills = BIRTH_SYLVIA ;

     return _SylviaSkills ;
}

int mfnSylvia( int argc, char* argv[] ){

     return CHAO ;
}

int _fnStrToNum( string data ){
     int num ;
     char* p ;

     num = 0 ;
     p = data ;
     while( *p != NL ){
          if( *p < 0x30 || 0x39 < *p ){
               logSisters(
                         ERR_MSG_NOT_NUMBER,
                         FATAL,
                         Sylvia_ID
                    ) ;
               return NL ;
          }
          num *= 10 ;
          num += *p++ - 0x30 ;
     }

     logSisters(
               "fnStrToNum()",
               ATTEND,
               Sylvia_ID
          ) ;

     return num ;
}

int _fnCalcStrExpression( string expression ){
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
     bool priorityFlg = FALSE ;
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
          numSetFlg = FALSE ;
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
               z = _fnMul( x, y ) ;
               priorityFlg = TRUE ;
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
               z = _fnDiv( x, y ) ;
               priorityFlg = TRUE ;
          }else if( *p == PLUS || *p == MINUS ){
               operators[j++] = *p ;
               if( !priorityFlg ){
                    numSetFlg = TRUE ;
               }
               priorityFlg = FALSE ;
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
               result = _fnAdd( result, *numbers ) ;
          }else if( *operators == MINUS ){
               result = _fnSub( result, *numbers ) ;
          }
          numbers++ ;
          operators++ ;
     }

     return result ;
}

int _fnAdd( int a, int b ){

     return a + b ;
}

int _fnSub( int a, int b ){

     return a - b ;
}

int _fnMul( int a, int b ){

     return a * b ;
}

int _fnDiv( int a, int b ){

     if( b == 0 ){
          return NL ;
     }

     return a / b ;
}
