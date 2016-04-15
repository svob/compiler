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
MOV | MOV ARG_1 NULL ARG_3 | move value of ARG_1 to ARG_3
JZ | JZ ARG_1 NULL ARG_3 | jump to label ARG_3 if ARG_1 = 0
ADD | ADD ARG_1 ARG_2 ARG_3 | ARG_3 = ARG_1 + ARG_2
AND | AND ARG_1 ARG_2 ARG_3 | ARG3 = ARG_1 and ARG_2
PRT | PRT ARG_1 NULL NULL | print ARG_1 on stdout
HLT | HLT NULL NULL NULL | end of program

####Usage
Parameter | Function | Example
--------- | -------- | -------
-t | Prints out a list of applied rules | Reducing by rule #11
-v | Extends -t by line number and grammar rules | Reducing by rule #2, line #11 (BEGIN statement_list END)
-d | Only check syntax | Syntax OK
-r | Run an intepreter and execute program |
-h | Prints out options |



I know that the code is ugly (especially printQuads function) so feel free to refactor and send pull request :stuck_out_tongue:
