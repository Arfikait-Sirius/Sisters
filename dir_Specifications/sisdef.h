#ifndef _SISDEF_
#define _SISDEF_


//** TYPE DEFINE **
typedef char mode ;
typedef void* pointer ;
typedef char bool ;
typedef char* string ;
typedef int file ;
typedef int list ;
typedef int stack ;
typedef int queue ;
typedef int map ;
typedef int schema ;
typedef void* fnp ;


// ** KEY SYMBOL DEFINE **
#define LF          0x0A
#define CR          0x0D
#define SPACE       0x20
#define BACK_SPACE  0x08
#define TAB         0x09
#define EQUAL       0x3D
#define DOLLAR      0x24
#define COMMA       0x2C
#define COLON       0x3A
#define SEMICOLON   0x3B
#define DOT         0x2E
#define SLASH       0x2F
#define ASTERISK    0x2A
#define AMPERSAND   0x26
#define PLUS        0x2B
#define MINUS       0x2D
#define LESS_THAN   0x3E
#define GRATER_THAN 0x3C
#define BRACE_LEFT  0x7B
#define BRACE_RIGHT 0x7D


// ** CONTROL SYMBOL DEFINE **
#define NL 0x00

#define CHAR_0 0x30
#define CHAR_1 0x31
#define CHAR_2 0x32
#define CHAR_3 0x33
#define CHAR_4 0x34
#define CHAR_5 0x35
#define CHAR_6 0x36
#define CHAR_7 0x37
#define CHAR_8 0x38
#define CHAR_9 0x39

#define CHAR_NUM_OFFSET 0x30

#define UPPER_A 0x41
#define UPPER_Z 0x5a
#define LOWER_A 0x61
#define LOWER_Z 0x7a

#define L_U_OFFSET 0x20

#define NO_NUMBER 0x40


// ** CONTEXT DEFINE **
#define FALSE  0
#define TRUE   1

#define STATUS_RED   0
#define STATUS_GREEN 1

#define DETAIL_COUNT_MAX 9

#define CHAO 0
#define TOO_BAD -1

#define STR_EMPTY ""

#define TYPE_DFT NL
#define TYPE_PTR 'p'
#define TYPE_CHR 'c'
#define TYPE_STR 's'
#define TYPE_INT 'd'

#define TMP 'T'
#define FIX 'F'

#define YES "y"
#define NO  "n"

#define FILE_CONTINUE	0x40
#define FILE_END	0x24

#define MIN_LENGTH 32
#define SHORT_LENGTH 64
#define MEDIUM_LENGTH 128
#define HALF_LENGTH 256
#define MAX_LENGTH 512
#define DOUBLE_LENGTH 1024
#define LARGE_LENGTH 4096


// ** OTHER DEFINE **
#define SISTERS_NAME 32
#define ZERO '0'


#endif
