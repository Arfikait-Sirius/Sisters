#include "Kotone.h"

static _MyDataKotone MyData = INIT_KOTONE_MYDATA ;

int mfnKotone( int argc, char* argv[] ){
     return CHAO ;
}

int _fnCreateList( char type, char mode ){
     int seq = MyData.listSeq ;

     MyData.existList[seq] = TYPE_DFT ;
     switch( type ){
     case TYPE_PTR:
          MyData.existList[seq] = TYPE_PTR ;
          break ;
     default:
          ;
     }
	switch( mode ){
	case TMP:
          MyData.chrListIndex[seq] = LIST_TOP ;
          MyData.strListIndex[seq] = LIST_TOP ;
          MyData.intListIndex[seq] = LIST_TOP ;
          MyData.PListIndex[seq] = LIST_TOP ;
          MyData.PListIndexAccess[seq] = LIST_TOP ;
		break ;
	case FIX:
		MyData.listSeq++ ;
		break ;
	}

	logSisters(
			"fnCreateList()",
			ATTEND,
			Kotone_ID
			) ;

     return seq ;
}

void _fnAppendPList( int listID, void* param, char type ){

     if( _isNotExistList( listID, TYPE_PTR ) ){
          logSisters(
                    "\"PList\" is not created.",
                    FATAL,
                    Kotone_ID
                    ) ;
          return ;
     }

     if( type == TYPE_CHR ){
          MyData.chrList[listID][MyData.chrListIndex[listID]] = *( char* )param ;
          MyData.PList[listID][MyData.PListIndex[listID]] = MyData.chrList[listID] + MyData.chrListIndex[listID]++ ;
     }else if( type == TYPE_STR ){
          strcpy( MyData.strList[listID][MyData.strListIndex[listID]], ( char* )param ) ;
          MyData.PList[listID][MyData.PListIndex[listID]] = MyData.strList[listID] + MyData.strListIndex[listID]++ ;
     }else if( type == TYPE_INT ){
          MyData.intList[listID][MyData.intListIndex[listID]] = *( int* )param ;
          MyData.PList[listID][MyData.PListIndex[listID]] = MyData.intList[listID] + MyData.intListIndex[listID]++ ;
     }
     MyData.PListType[listID][MyData.PListIndex[listID]++] = type ;
     if( MyData.PListIndex[listID] == MAX_LIST_SIZE ){
          logSisters(
                    "No more add to PList.",
                    ERROR,
                    Kotone_ID
                    ) ;
          return ;
     }

	logSisters(
			"fnAppendPList()",
			ATTEND,
			Kotone_ID
			) ;

     return ;
}

char _fnGetPListAsChr( int listID, int pos ){

     MyData.valueChr = *( char* )MyData.PList[listID][pos] ;

	logSisters(
			"fnGetPListAsChr()",
			ATTEND,
			Kotone_ID
			) ;

     return MyData.valueChr ;
}

char* _fnGetPListAsStr( int listID, int pos ){

     strcpy( MyData.valueStr, ( char* )MyData.PList[listID][pos] ) ;

	logSisters(
			"fnGetPListAsStr()",
			ATTEND,
			Kotone_ID
			) ;

     return MyData.valueStr ;
}

int _fnGetPListAsInt( int listID, int pos ){

     MyData.valueInt = *( int* )MyData.PList[listID][pos] ;

	logSisters(
			"fnGetPListAsInt()",
			ATTEND,
			Kotone_ID
			) ;

     return MyData.valueInt ;
}

bool _isNotExistList( int listID, char type ){
     if( MyData.existList[listID] == type ){
          return FALSE ;
     }

     return TRUE ;
}

bool _isNextPListTypeChr( int listID ){
     if( MyData.PListType[listID][MyData.PListIndexAccess[listID]] == TYPE_CHR ){
          MyData.PListIndexAccess[listID]++ ;
          return TRUE ;
     }

     return FALSE ;
}

bool _isNextPListTypeStr( int listID ){
     if( MyData.PListType[listID][MyData.PListIndexAccess[listID]] == TYPE_STR ){
          MyData.PListIndexAccess[listID]++ ;
          return TRUE ;
     }

     return FALSE ;
}

bool _isNextPListTypeInt( int listID ){
     if( MyData.PListType[listID][MyData.PListIndexAccess[listID]] == TYPE_INT ){
          MyData.PListIndexAccess[listID]++ ;
          return TRUE ;
     }

     return FALSE ;
}
