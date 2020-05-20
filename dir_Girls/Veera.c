#include "Veera.h"

VeeraFunctions callVeera( void ){
     VeeraFunctions _VeeraSkills = BIRTH_VEERA ;

     return _VeeraSkills ;
}

static time_t seed = 0 ;

int mfnMainVeera( int argc, char* argv[] ){
	int i ;
	char s[80] ;

	_fnInitRandom() ;
	for( i = 0 ; i < 1000 ; i++ ){
		sprintf( s, "rand = %d", _fnRandom( 10000 ) ) ;
		logSisters( s, INFO, Veera_ID ) ;
	}

	return CHAO ;
}

void _fnInitRandom(){

	seed = time( NULL ) ;
	srand( seed ) ;

	return ;
}

int _fnRandom( int limit ){
	int randNum ;

	if( seed == 0 ){
		return STATUS_RED ;
	}
	randNum = rand() % limit ;

	return randNum ;
}

string _fnGetDate( void ){
     string date ;

     return date ;
}

string _fnGetTime( void ){
     string time ;

     return time ;
}

string _fnGetWeek( void ){
     string week ;

     return week ;
}
