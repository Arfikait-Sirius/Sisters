#ifndef _SISCMN_
#define _SISCMN_


//--< Use Headers >--//
#include "stdio.h"


//--< Standard Definition >--//
#include "../dir_Modules/skillsheets/commons/siscmn.h"
#include "../dir_Modules/skillsheets/commons/sisdef.h"
#include "../dir_Modules/skillsheets/commons/sisset.h"


//--< Prototype Declarations >--//
void logSisters( string, int, string ) ;

static void sfnWriteLog( string, string ) ;


//--< Free Definitions >--//
#define IS_LOG_FILE LOG_SETUP
#define LOG_FILE "../dir_Logs/Progress.log"
#define MASSAGE_FILE "../dir_Logs/Message.log"
#define INFO_FILE "../dir_Logs/Diary.log"
#define ERROR_FILE "../dir_Logs/Warning.log"
#define FATAL_FILE "../dir_Logs/Critical.log"

#define STATUS_COUNT 4
#define SET_ALL_STATUS_LABEL {\
     "MESSAGE",\
     "INFO",\
     "ERROR",\
     "FATAL"\
}

static const string statusLabel[STATUS_COUNT] = SET_ALL_STATUS_LABEL ;


#endif
