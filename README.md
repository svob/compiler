# Compiler :see_no_evil:
Compiler and LR parser of simple context-free grammar, implemeted in Flex and YACC

This compiler was implemented as school term project.

####Input
Compiler works with standard input `stdin` and accept grammar specified by rules:
```
PROG  -> program ID ; BLOCK .
BLOCK -> begin LIST end
LIST  -> STMT
       | STMT ; LIST
STMT  -> BLOCK
       | if EXPR then STMT
       | ID := EXPR
       | print EXPR
EXPR  -> EXPR + EXPR
       | EXPR and EXPR
       | ID
       | NUM
       
ID    -> case-sensitive identifier, starting with a lowercase letter
NUM   -> integer
```

####Output
The compiler produces intermediate code in quadruples.


OP | Syntax | Semantics
--- | ------ | ---------
MOV | MOV ARG_1 NULL ARG3 | ...
JZ | JZ ARG_1 NULL ARG_3 | ...
ADD | ADD ARG_1 ARG_2 ARG_3 | ...
AND | AND ARG_1 ARG_2 ARG_3 | ...
PRT | PRT ARG_1 NULL NULL | ...
HLT | HLT NULL NULL NULL | ...

####Usage
Parameter | Function | Example
--------- | -------- | -------
-t | Prints out a list of applied rules | Reducing by rule #11
-v | Extends -t by line number and grammar rules | Reducing by rule #2, line #11 (BEGIN statement_list END)
-d | Only check syntax | Syntax OK
-r | Run an intepreter and execute program |
-h | Prints out options |



I know that the code is ugly (especially printQuads function) so feel free to refactor and send pull request :stuck_out_tongue:
