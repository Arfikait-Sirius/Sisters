# How to call Louise
```c
static void callSisters( void ){
     Louise = callLouise() ;

     return ;
}
```

# Skills
## fnCount()
```c
string base = "String_123 and String_456, string_123:STRING_456" ;
string target = "String" ;

int count = Louise.fnCount( base, target ) ;
// count: 2
```

## fnCopy()
```c
string src = "String_123." ;

string result = Louise.fnCopy( src ) ;
// result: "String_123."
```

## fnReplace()
```c
string base = "This is normal String." ;
string target = "normal" ;
string replacement = "changed" ;

string result = Louise.fnReplace( base, target, replacement ) ;
// result: "This is changed String."
```

## fnSplit()
```c
string base = "String:Int:Object" ;
char splitter = ':' ;
int index = 1 ;

string result = Louise.fnSplit( base, splitter, index ) ;
// result: "Int"
```

## fnUpperAll()
```c
string base = "sTrInG_123." ;

string result = Louise.fnUpperAll( base ) ;
// result: "STRING_123."
```

## fnLowerAll()
```c
string base = "sTrInG_123." ;

string result = Louise.fnLowerAll( base ) ;
// result: "string_123."
```

## fnUpperFirst()
```c
string base = "sTrInG_123." ;

string result = Louise.fnUpperFirst( base ) ;
// result: "String_123."
```

## fnGetMiddle()
```c
string format = " is %s and " ;
string base = "This is String_123 and Int_456." ;

string result = Louise.fnGetMiddle( format, base ) ;
// result: "String_123"
```

## fnTrim()
```c
string base = "  \tString_123 \tInt_456\t " ;

string result = Louise.fnTrim( base ) ;
// result: "String_123 \tInt_456"
```

## fnToString()
```c
int base = 1234 ;

string result = Louise.fnToString( base ) ;
// result: "1234"
```

## fnFind()
```c
string base = "String_123 and Int_456." ;
string target = "and" ;

int index = Louise.fnFind( base, target ) ;
// index: 11
```

## fnGetLength()
```c
string base = "String_123." ;

int length = Louise.fnGetLength( base ) ;
// length: 11
```

# Judges
## isFormat()
```c
string base = "String:Int:Object" ;
string format = "%s:%s:%s" ;

bool result = Louise.isFormat( base, format ) ;
// result: true
```

## isContain()
```c
string base = "This is String_123String_456String_789." ;
string target = "String_456" ;

bool result = Louise.isContain( base, target ) ;
// result: true
```

## isEqual()
```c
string base = "String_123." ;
string target = "String_123." ;

bool result = Louise.isEqual( base, target ) ;
// result: true
```

## isEmpty()
```c
string target = "" ;

bool result = Louise.isEmpty( target ) ;
// result: true
```
