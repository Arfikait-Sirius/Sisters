#include "Chloe.h"

// Name
static string MyName = "Chloe" ;

// Chloe's Memo
static _MyDataChloe MyData ;

// Birth
ChloeFunctions callEmily( void ){
	ChloeFunctions _ChloeSkills = BIRTH_CHLOE ;

	return _ChloeSkills ;
}

//------------------------
// :[ NAME ]:
//     acNot
//
// :[ CATEGORY ]:
//     Accessory
//------------------------
bool _acNot( bool b ){

	if( b ){
		return FALSE ;
	}

	return TRUE ;
}

//------------------------
// :[ NAME ]:
//     fnPass
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnPass( void ){

	// Do not anything.

	return ;
}

//------------------------
// :[ NAME ]:
//     isNo
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isNo( string judgement ){

	sfnToLower( judgement ) ;
	if( strcmp( judgement, NO ) == 0
			|| strcmp( judgement, "no" ) == 0 ){
		return TRUE ;
	}

	return FALSE ;
}

int _drIfInt( bool judgement, int ( *funcTrue )( void ), int ( *funcFalse )( void ) ){
	int result ;

	if( judgement ){
		result = *funcTrue() ;
	}else{
		result = *funcFalse() ;
	}

	return resutl ;
}

static void sfnToLower( string s ){
	char* p ;

	p = s ;
	while( *p != NL ){
		if( LOWER_A <= *p && *p <= LOWER_Z ){
			*p += L_U_OFFSET ;
		}
		p++ ;
	}

	return ;
}
