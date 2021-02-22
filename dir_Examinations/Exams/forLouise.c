#include "forLouise.h"


static void callSisters( void ){
     Tina = callTina() ;
     Louise = callLouise() ;

     return ;
}


void examForLouise( void ){
     callSisters() ;

     Tina.fnSetGirlName( "Louise" ) ;

     examFnCount() ;
     examFnCopy() ;
     examFnReplace() ;
     examFnSplit() ;
     examFnUpperAll() ;
     examFnLowerAll() ;
     examFnUpperFirst() ;
     examFnGetMiddle() ;
     examFnTrim() ;
     examFnToString() ;
     examFnFind() ;
     examFnGetLength() ;

     examIsFormat() ;
     examIsContain() ;
     examIsEqual() ;
     examIsEmpty() ;

     return ;
}

static void examFnCount( void ){
     Tina.fnSetSkillName( "fnCount" ) ;

     int count ;
     bool result ;

     count = Louise.fnCount( "This is String and string or String_123. It is String!", "String" ) ;
     result = count == 3 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnCopy( void ){
     Tina.fnSetSkillName( "fnCopy" ) ;

     string s ;
     bool result ;

     s = Louise.fnCopy( "TestString 000" ) ;
     result = ( strcmp( s, "TestString 000" ) == 0 ) ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnReplace( void ){
     Tina.fnSetSkillName( "fnReplace" ) ;

     string s ;
     bool result ;

     s = Louise.fnReplace( "This is normal string.", "normal", "changed" ) ;
     result = strcmp( s, "This is changed string." ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnSplit( void ){
     Tina.fnSetSkillName( "fnSplit" ) ;

     string s ;
     bool result ;

     s = Louise.fnSplit( "String:Int:Object", COLON, 1 ) ;
     result = strcmp( s, "Int" ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnUpperAll( void ){
     Tina.fnSetSkillName( "fnUpperAll" ) ;

     string s ;
     bool result ;

     s = Louise.fnUpperAll( "sTrInG_123." ) ;
     result = strcmp( s, "STRING_123." ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnLowerAll( void ){
     Tina.fnSetSkillName( "fnLowerAll" ) ;

     string s ;
     bool result ;

     s = Louise.fnLowerAll( "sTrInG_123." ) ;
     result = strcmp( s, "string_123." ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnUpperFirst( void ){
     Tina.fnSetSkillName( "fnUpperFirst" ) ;

     string s ;
     bool result ;

     s = Louise.fnUpperFirst( "sTrInG_123." ) ;
     result = strcmp( s, "String_123." ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnGetMiddle( void ){
     Tina.fnSetSkillName( "fnGetMiddle" ) ;

     string s ;
     bool result ;

     s = Louise.fnGetMiddle( " is %s and", "This is String_123 and it is String_456." ) ;
     result = strcmp( s, "String_123" ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnTrim( void ){
     Tina.fnSetSkillName( "fnTrim" ) ;

     string s ;
     bool result ;

     s = Louise.fnTrim( "	   Trim 	String.  	 	  " ) ;
     result = strcmp( s, "Trim 	String." ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnToString( void ){
     Tina.fnSetSkillName( "fnToString" ) ;

     string s ;
     bool result ;

     s = Louise.fnToString( 1234 ) ;
     result = strcmp( s, "1234" ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnFind( void ){
     Tina.fnSetSkillName( "fnFind" ) ;

     string base = "teststring_123abc" ;
     bool result ;

     result = Louise.fnFind( base, "string" ) == 4 ;

     Tina.fnJudge( result) ;

     return ;
}

static void examFnGetLength( void ){
     Tina.fnSetSkillName( "fnGetLength" ) ;

     int len ;
     bool result ;

     len = Louise.fnGetLength( "This is String_123." ) ;
     result = len == 19 ;

     Tina.fnJudge( result ) ;

     return ;
}


static void examIsFormat( void ){
     Tina.fnSetSkillName( "isFormat" ) ;

     bool result ;

     result = Louise.isFormat( "%s:%s:%s", "String:Int:Object" ) ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examIsContain( void ){
     Tina.fnSetSkillName( "isContain" ) ;

     bool result ;

     result = Louise.isContain( "String_123:Int_456:Object_789", "Int_456" ) ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examIsEqual( void ){
     Tina.fnSetSkillName( "isEqual" ) ;

     bool result ;

     result = Louise.isEqual( "String_123", "String_123" ) ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examIsEmpty( void ){
     Tina.fnSetSkillName( "isEmpty" ) ;

     bool result ;

     result = Louise.isEmpty( "" ) ;

     Tina.fnJudge( result ) ;

     return ;
}
