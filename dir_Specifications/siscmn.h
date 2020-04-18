#ifndef _SISCMN_
#define _SISCMN_


//--< Use Headers >--//
#include "stdio.h"


//--< Standard Definition >--//
#include "../dir_Specifications/sisdef.h"
#include "../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
void logSisters( string, int, int ) ;

static void sfnWriteLog( string, string ) ;


//--< Free Definitions >--//
#define IS_LOG_FILE LOG_SETUP
#define LOG_FILE "../dir_Logs/Progress.log"
#define ATTENDANCE_FILE "../dir_Logs/Attendance.log"
#define INFO_FILE "../dir_Logs/Diary.log"
#define ERROR_FILE "../dir_Logs/Warning.log"
#define FATAL_FILE "../dir_Logs/Critical.log"

#define STATUS_COUNT 5
#define SET_ALL_STATUS_LABEL {\
	"ATTEND",\
	"ERROR",\
	"FATAL",\
	"INFO",\
	"MESSAGE"\
}

static const string statusLabel[STATUS_COUNT] = SET_ALL_STATUS_LABEL ;


#endif
