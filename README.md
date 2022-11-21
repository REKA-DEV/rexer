# Lexer Library For C++

## CMakeLists.txt

---

```cmake
find_package(rexer REQUIRED CONFIG)
target_link_libraries(${PROJECT_NAME} PRIVATE rexer)
```

## example

---

```c++
#include <iostream>

#include "rexer/Rexer.h"

using namespace rexer;

enum Keys {
	BRACE_OPEN,
	BRACE_CLOSE,
	
	BRACKET_OPEN,
	BRACKET_CLOSE,
	
	BLANK,
	
	COLON,
	COMMA,
	
	INTEGER,
	DECIMAL,
	NUMBER,
	
	IDENTIFIER,
	
	JSON_PAIR,
	JSON_OBJECT
};

int main() {
	Rexer rexer;
	
	Rule * braceOpen = rexer.mSkip(BRACE_OPEN, rexer.nmWord("{"));
	Rule * braceClose = rexer.mSkip(BRACE_CLOSE, rexer.nmWord("}"));

	rexer.mSkip(BRACKET_OPEN, rexer.nmWord("["));
	rexer.mSkip(BRACKET_CLOSE, rexer.nmWord("]"));
	
	Rule * blank = rexer.mOptional(BLANK, rexer.nmSkip(rexer.nmRegex(regex("[ \t\n\r]+"))));
	
	rexer.mSkip(COLON, rexer.nmWord(":"));
	rexer.mSkip(COMMA, rexer.nmWord(","));
	
	rexer.mRegex(INTEGER, regex("[1-9][0-9]*"));
	rexer.mRegex(DECIMAL, regex("[1-9][0-9]*\\.[0-9]*[1-9]"));
	rexer.mOr(NUMBER, vector<int>({ INTEGER, DECIMAL }));
	
	rexer.mRegex(IDENTIFIER, regex("(?![0-9])[a-zA-Z0-9]+"));
	
	rexer.mGroup(JSON_PAIR, true, vector<int>({ IDENTIFIER, BLANK, COLON, BLANK, NUMBER }));
	rexer.mGroup(JSON_OBJECT, true, vector<Rule *>({
		braceOpen,
		blank,
		
		rexer.nmMultiple(false, rexer.nmGroup(false, vector<int>({ JSON_PAIR, BLANK, COMMA, BLANK }))),
		rexer.nmOptional(JSON_PAIR),
		
		braceClose,
		blank
	}));
	
	RexerResult * rexerResult = rexer.execute(JSON_OBJECT, "{ a: 1, b: 2, c: 3.141592, }");
	
	cout << rexerResult->toString();
}
```

## output

---

```
success: 1
start: 0
end: 28

12 (0 28 3)
  11 (2 6 2)
    10 a (2 3)
    7 1 (5 6)
  11 (8 12 2)
    10 b (8 9)
    7 2 (11 12)
  11 (14 25 2)
    10 c (14 15)
    8 3.141592 (17 25)
```
