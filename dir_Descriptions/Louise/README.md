# Louise のアサイン方法
```c
static void callSisters( void ){
     Louise = callLouise() ;

     return ;
}
```

# 作業スキル
## fnCount()
```c
string base = "String_123 and String_456, string_123:STRING_456" ;
string target = "String" ;

int count = Louise.fnCount( base, target ) ;
// count: 2
```
* 文字列 `base` に含まれる文字列 `target` がいくつあるのか数えてくれます

## fnCopy()
```c
string src = "String_123." ;

string result = Louise.fnCopy( src ) ;
// result: "String_123."
```
* 文字列 `src` を文字列 `result` にコピーしてくれます

## fnReplace()
```c
string base = "This is normal String." ;
string target = "normal" ;
string replacement = "changed" ;

string result = Louise.fnReplace( base, target, replacement ) ;
// result: "This is changed String."
```
* 文字列 `base` の文字列 `target` を文字列 `replacement` に置き換えてくれます
* 非破壊的スキルなので文字列 `base` は書き換えません
  * 優しいですね

## fnSplit()
```c
string base = "String:Int:Object" ;
string splitter = ":" ;
int index = 1 ;

string result = Louise.fnSplit( base, splitter, index ) ;
// result: "Int"
```
* 文字列 `base` を文字列 `splitter` で分割して数値 `index` で指定した位置の文字列を教えてくれます
* 非破壊的スキルなので文字列 `base` は書き換えません
* 数値 `index` は 0 始まりです

## fnUpperAll()
```c
string base = "sTrInG_123." ;

string result = Louise.fnUpperAll( base ) ;
// result: "STRING_123."
```
* 文字列 `base` に含まれる小文字をすべて大文字に変換して教えてくれます
* 非破壊的スキルなので文字列 `base` は書き換えません
* アルファベット以外には何もしません

## fnLowerAll()
```c
string base = "sTrInG_123." ;

string result = Louise.fnLowerAll( base ) ;
// result: "string_123."
```
* 文字列 `base` に含まれる大文字をすべて小文字に変換して教えてくれます
* 非破壊的スキルなので文字列 `base` は書き換えません
* アルファベット以外には何もしません

## fnUpperFirst()
```c
string base = "sTrInG_123." ;

string result = Louise.fnUpperFirst( base ) ;
// result: "String_123."
```
* 文字列 `base` の先頭 1文字だけ大文字に残りを小文字に変換して教えてくれます
* 非破壊的スキルなので文字列 `base` は書き換えません
* アルファベット以外には何もしません

## fnGetMiddle()
```c
string base = "This is String_123 and Int_456." ;
string format = " is %s and " ;

string result = Louise.fnGetMiddle( format, base ) ;
// result: "String_123"
```
* 文字列 `base` を基準として文字列 `format` の %s にあたる部分文字列を教えてくれます
* 複数ヒットする場合は最初の部分文字列が対象になります
  * 健気ですね
* 非破壊的スキルなので文字列 `base` は書き換えません

## fnTrim()
```c
string base = "  \tString_123 \tInt_456\t " ;

string result = Louise.fnTrim( base ) ;
// result: "String_123 \tInt_456"
```
* 文字列 `base` の両端にあるタブや半角スペースを切り取った部分文字列を教えてくれます
  * 一般に言うトリミングですね
* 非破壊的スキルなので文字列 `base` は書き換えません

## fnFromInt()
```c
int base = 1234 ;

string result = Louise.fnFromInt( base ) ;
// result: "1234"
```
* 数値 `base` を文字列に変換してくれます
* 非破壊的スキルなので数値 `base` は書き換えません

## fnFind()
```c
string base = "String_123 and Int_456." ;
string target = "and" ;

int index = Louise.fnFind( base, target ) ;
// index: 11
```
* 文字列 `base` に含まれる文字列 `target` を検索して最初にヒットした先頭文字の位置を教えてくれます
* 教えてくれる位置は 0 始まりです

## fnGetLength()
```c
string base = "String_123." ;

int length = Louise.fnGetLength( base ) ;
// length: 11
```
* 文字列 `base` の文字数を教えてくれます
  * 文字数は 1 始まりなので純粋に何文字あるのか分かりますよ

# 判定スキル
## isFormat()
```c
string base = "String:Int:Object" ;
string format = "%s:%s:%s" ;

bool result = Louise.isFormat( base, format ) ;
// result: true
```
* 文字列 `base` の形式が文字列 `format` と同じかどうかを教えてくれます

## isContain()
```c
string base = "This is String_123String_456String_789." ;
string target = "String_456" ;

bool result = Louise.isContain( base, target ) ;
// result: true
```
* 文字列 `base` に文字列 `target` が含まれるかどうかを教えてくれます

## isEqual()
```c
string base = "String_123." ;
string target = "String_123." ;

bool result = Louise.isEqual( base, target ) ;
// result: true
```
* 文字列 `base` が文字列 `target` と等しいかどうかを教えてくれます

## isEmpty()
```c
string target = "" ;

bool result = Louise.isEmpty( target ) ;
// result: true
```
* 文字列 `target` が空文字かどうかを教えてくれます
