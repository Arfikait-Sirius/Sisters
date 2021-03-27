# How to call Emily
```c
static void callSisters( void ){
     Emily = callEmily() ;

     return ;
}
```

# Skills
## fnGetLine()
```c
string label = "Please input: " ;

string s = Emily.fnGetLine( label ) ;
// Wait for input from stdin.
```

## fnDispLine()
```c
string message = "This is message.";

Emily.fnDispLine( message ) ;
// Display "This is message" with line breaks.
```

## fnDispLineCustom()
```c
string prefix = "Prefix " ;
string message = "This is main message." ;
string suffix = " Suffix" ;

Emily.fnDispLineCustom( prefix, message, suffix ) ;
// Display "Prefix This is main message. Suffix" with line breaks.
```

## fnDispStr()
```c
string message = "This is message.";

Emily.fnDispLine( message ) ;
// Display "This is message".
```

## fnDispStrCustom()
```c
string prefix = "Prefix " ;
string message = "This is main message." ;
string suffix = " Suffix" ;

Emily.fnDispLineCustom( prefix, message, suffix ) ;
// Display "Prefix This is main message. Suffix".
```

## fnNewLine()
```c
Emily.fnNewLine() ;
// Display new line.
```
