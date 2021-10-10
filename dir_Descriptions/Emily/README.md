# Emily のアサイン方法
```c
static void callSisters( void ){
     Emily = callEmily() ;

     return ;
}
```

# 作業スキル
## fnGetLine()
```c
string label = "Please input: " ;

string str = Emily.fnGetLine( label ) ;
// Wait for input from stdin.
```
* 標準入力に入力された文字列を文字列 `str` に格納してくれます
* 文字列 `label` をプロンプト表示させることができます
  * 不要な場合は `NULL` を指定するそうですよ

## fnDispLine()
```c
string message = "This is message.";

Emily.fnDispLine( message ) ;
// Display "This is message" with line breaks.
```
* 文字列 `message` を標準出力に改行付きで表示してくれます

## fnDispLineCustom()
```c
string prefix = "Prefix " ;
string message = "This is main message." ;
string suffix = " Suffix" ;

Emily.fnDispLineCustom( prefix, message, suffix ) ;
// Display "Prefix This is main message. Suffix" with line breaks.
```
* 文字列 `message` を標準出力に改行付きで表示してくれます
* 文字列 `prefix` と文字列 `suffix` で指定した文字列を文字列 `message` の前後に結合して表示してくれます

## fnDispStr()
```c
string message = "This is message.";

Emily.fnDispLine( message ) ;
// Display "This is message".
```
* 文字列 `message` を標準出力に改行なしで表示してくれます

## fnDispStrCustom()
```c
string prefix = "Prefix " ;
string message = "This is main message." ;
string suffix = " Suffix" ;

Emily.fnDispLineCustom( prefix, message, suffix ) ;
// Display "Prefix This is main message. Suffix".
```
* 文字列 `message` を標準出力に改行なしで表示してくれます
* 文字列 `prefix` と文字列 `suffix` で指定した文字列を文字列 `message` の前後に結合して表示してくれます

## fnNewLine()
```c
Emily.fnNewLine() ;
// Display new line.
```
* 標準出力に空行を 1行表示してくれます
