# Regex (Regular Expressions)
A regular expression is a pattern that describes a set of strings. Regular expressions are constructued analogously to arithmetic expressions, by using various operators to combine smaller
expressions.

Widely used in many programming languages and editors
* Perl, Python, Java
* ed, ex, vi, emacs
* lex, yacc, ANTLR, JavaCC

The unix tool `grep` uses regex to search files fo rthe specified expressions.

Usage:
```
grep <regex> files
```

## Metacharacters
The caret `^` and the dollar sign `$`, are metacharacters that respectively match the empty string at the beginning and end of a line.
* `.` dot is any character
* `.*` dot star is any sequence of characters

### Character Class
A bracket expression is a list of characters enclosed by `[` and `]`. It matches any single character in that list; if the first character of the list is the caret, `^`, then it
matches any character not in the list.

## Operators
Regular expressions make use of three operators
* concatenation
* alternation
* closure

### Concatenation
Two regular expressions are simply joined / concatenated

### Alternation operator
Two regular expressions may be joined by the infix operator |; the resulting regular expression matches any string matching either subexpression

### Closure operator
Closure is represnted by the braces `{}*` and denotes repetition of the expression zero or more times.

### Precedence
Reptititon takes precedence over concatenation, which in turn takes precedence over alternation. A whole subexpression may be enclose in parentheses to override these precedence rules.

### Repitition operators
* ? - The preceding item is optional and ma

