#include "Veera.h"

// Name
static string MyName = "Veera" ;

// Veera's Memo
static _MyDataVeera MyData = INIT_VEERA_MYDATA ;

// Birth
VeeraFunctions callVeera( void ){
     VeeraFunctions _VeeraSkills = BIRTH_VEERA ;

     return _VeeraSkills ;
}

static time_t timer = 0 ;

void _VeerafnInitRandom(){

     timer = time( NULL ) ;
     srand( timer ) ;

     return ;
}

int _VeerafnRandom( int limit ){
     int randNum ;

     if( timer == 0 ){
          return STATUS_RED ;
     }
     randNum = rand() % limit ;

     return randNum ;
}

string _VeerafnGetDate( string baseFormat ){
     struct tm* utc ;
     char* p ;
     char resultFormat[BUF_SIZE_DATE] = { NL } ;
     char* r ;
     char tmp[5] = { NL } ;
     char* t ;
     bool year ;
     bool month ;
     bool day ;

     timer = time( NULL ) ;
     utc = gmtime( &timer ) ;

     year = false ;
     month = false ;
     day = false ;

     t = tmp ;
     p = baseFormat ;
     r = resultFormat ;
     while( *p != NL ){
          if( *p == VEERA_SYMBOL_YEAR ){
               *t++ = *p ;
          }else if( *p == VEERA_SYMBOL_MONTH ){
               *t++ = *p ;
          }else if( *p == VEERA_SYMBOL_DAY ){
               *t++ = *p ;
          }else{
               *r++ = *p ;
               *r = NL ;
          }
          *t = NL ;
          if( strcmp( tmp, VEERA_FORMAT_YEAR ) == 0 ){
               year = true ;
               strcat( resultFormat, "%04d" ) ;
               r += 4 ;
               t = tmp ;
          }else if( strcmp( tmp, VEERA_FORMAT_MONTH ) == 0 ){
               month = true ;
               strcat( resultFormat, "%02d" ) ;
               r += 4 ;
               t = tmp ;
          }else if( strcmp( tmp, VEERA_FORMAT_DAY ) == 0 ){
               day = true ;
               strcat( resultFormat, "%02d" ) ;
               r += 4 ;
               t = tmp ;
          }
          p++ ;
     }
     *r = NL ;

     if( year && month && day ){
          sprintf( MyData.date, resultFormat, utc->tm_year + 1900, utc->tm_mon + 1, utc->tm_mday ) ;
     }else if( month && day ){
          sprintf( MyData.date, resultFormat, utc->tm_mon + 1, utc->tm_mday ) ;
     }else if( year ){
          sprintf( MyData.date, resultFormat, utc->tm_year + 1900 ) ;
     }else if( month ){
          sprintf( MyData.date, resultFormat, utc->tm_mon + 1 ) ;
     }else if( day ){
          sprintf( MyData.date, resultFormat, utc->tm_mday ) ;
     }

     return MyData.date ;
}

string _VeerafnGetTime( void ){
     string now ;

     return now ;
}

string _VeerafnGetWeek( void ){
     string week ;

     return week ;
}
