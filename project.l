%option yylineno

%{

#include <stdio.h>
#include "ast.h"
#include "project.tab.h"
void yyerror(char *);

%}

%x comment

%%

[ \t]		;
\n		;
^;		BEGIN(comment);
program		return PROGRAM;
[;.+]		return *yytext;
begin		return BEGIN_T;
end		return END_T;
if		return IF;
then		return THEN;
print		return PRINT;
:=		return ASSIGN;
and		return AND;
[a-zA-Z][a-zA-Z0-9]*	yylval.string = strdup(yytext); return ID;
[0-9]+		yylval.number = atoi(yytext); return NUM;
.		yyerror("invalid character");

<comment>\n	BEGIN(0);
<comment>.	;

%%