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

string _VeerafnGetDate( void ){
     struct tm* utc ;

     timer = time( NULL ) ;
     utc = gmtime( &timer ) ;

     sprintf( MyData.date, "%04d/%02d/%02d", utc->tm_year + 1900, utc->tm_mon + 1, utc->tm_mday ) ;

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
