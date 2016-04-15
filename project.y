%{    
#define true 1
#define false 0
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"

nodeType *num(int value);
nodeType *id(char *value);
nodeType *opr(int oper, int nops, ...);
void printQuads(nodeType *root);
void freeNode(nodeType *p);
void stack_init(Stack *s);

extern int yylineno;
extern char *yytext;
extern int yylex();
//int yydebug = 1;

nodeType *root;
Stack *stack;

int tmp = 0;
int lbl = 0;
int err = false;

int t_opt = false,
    v_opt = false,
    d_opt = false,
    h_opt = false,
    r_opt = false;
%}

%union {
    int number;
    char *string;
    nodeType *nPtr;
};

%start prog
%token PROGRAM BLOCK BEGIN_T END_T IF THEN ASSIGN PRINT
%token <string> ID
%token <number> NUM
%left '+'
%left AND

%type <nPtr> block list stmt expr

%%

prog	: PROGRAM ID ';' block '.'	{
					if (t_opt || v_opt) {
					    printf("Reducing by rule #1");
					    if (v_opt)
						printf("\tline #%d (PROGRAM)", yylineno);
					    printf("\n");
					}
					root = $4;
					}
	;

block	: BEGIN_T list END_T	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #2");
				    if (v_opt)
					printf("\tline #%d (BEGIN statement_list END)", yylineno);
				    printf("\n");
				}
				$$ = $2;
				}
	| BEGIN_T error END_T	{ yyerrok; }
	;
    
list	: stmt			{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #3");
				    if (v_opt)
					printf("\tline #%d (STATEMENT)", yylineno);
				    printf("\n");
				}
				$$ = $1;
				}
	| stmt ';' list		{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #4");
				    if (v_opt)
					printf("\tline #%d (STATEMENT_LIST)", yylineno);
				    printf("\n");
				}
				$$ = opr(';', 2, $1, $3);
				}
	;
    
stmt	: block			{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #5");
				    if (v_opt)
					printf("\tline #%d (BLOCK)", yylineno);
				    printf("\n");
				}
				}
	| IF expr THEN stmt	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #6");
				    if (v_opt)
					printf("\tline #%d (IF expression THEN statement)", yylineno);
				    printf("\n");
				}
				$$ = opr(IF, 2, $2, $4);
				}
	| ID ASSIGN expr	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #7");
				    if (v_opt)
					printf("\tline #%d (ASSIGNMENT)", yylineno);
				    printf("\n");
				}
				$$ = opr(ASSIGN, 2, id($1), $3);
				}
	| PRINT expr		{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #8");
				    if (v_opt)
					printf("\tline #%d (PRINT)", yylineno);
				    printf("\n");
				}
				$$ = opr(PRINT, 1, $2);
				}
        | ID error stmt         { yyerrok; }
	;
    
expr	: expr '+' expr		{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #9");
				    if (v_opt)
					printf("\tline #%d (expression + expression)", yylineno);
				    printf("\n");
				}
				$$ = opr('+', 2, $1, $3);
				}
	| expr AND expr		{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #10");
				    if (v_opt)
					printf("\tline #%d (expression AND expression)", yylineno);
				    printf("\n");
				}
				$$ = opr(AND, 2, $1, $3);
				}
	| ID			{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #11");
				    if (v_opt)
					printf("\tline #%d (NAME)", yylineno);
				    printf("\n");
				}
				$$ = id($1);
				}
	| NUM			{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #12");
				    if (v_opt)
					printf("\tline #%d (INTEGER)", yylineno);
				    printf("\n");
				}
				$$ = num($1);
				}
	;

%%

void yyerror(char *s) {
    printf("%d: %s at %s\n", yylineno, s, yytext);
    err = true;
}

int main(int argc, char **argv) {
    
    if (argc > 1) {
	for (int i = 0; i < argc; i++) {
	    if (strcmp(argv[i], "-t") == 0)
		t_opt = true;
	    if (strcmp(argv[i], "-v") == 0)
		v_opt = true;
	    if (strcmp(argv[i], "-d") == 0)
		d_opt = true;
	    if (strcmp(argv[i], "-h") == 0)
		h_opt = true;
	}
	if (d_opt)
	    t_opt = v_opt = false;
    }

    if (h_opt) {
	printf("===========================================================\n");
	printf("VSPJ, KTS, xPJP, term project. Written by Filip Svoboda.\n");
	printf("Usage: ./project [options]\n");
	printf("Options:\n");
	printf("\t-h\tprint command line options\n");
	printf("\t-t\twrite parse trace\n");
	printf("\t-v\twrtie parse trace and grammar rules\n");
	printf("\t-d\tonly check of syntax, no intermediate code\n");
	printf("\t-r\trun program by interpreter\n");
	printf("Source: stdin, intermediate code: stdout\n");
	printf("===========================================================\n");
    }
    else {
        yyparse();
        if (!err) {
            if (d_opt) {
                printf("Syntax OK\n");
            }
            else {
                stack = malloc(sizeof(Stack));
                stack_init(stack);
                printf("\n\n");
                printQuads(root);
                printf("\tHLT, NULL, NULL, NULL\n");
            }
        }
    }
    return 0;
}

nodeType *num(int value) {
    nodeType *p;
    
    if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	
    p->type = numType;
    p->num.value = value;
    
    return p;
}

nodeType *id(char *value) {
    nodeType *p;
    
    if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	
    if ((p->id.value = strdup(value)) == NULL)
	yyerror("out of memory");
    p->type = idType;	
    
    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    
    if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
    if ((p->opr.op = malloc(nops * sizeof(nodeType *))) == NULL)
	yyerror("out of memory");
	
    p->type = opType;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (int i = 0; i < nops; i++)
	p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    
    return p;
}

void freeNode(nodeType *p){
    if (!p) return;
    if (p->type == opType) {
	for (int i = 0; i < p->opr.nops; i++)
	    freeNode(p->opr.op[i]);
	free(p->opr.op);
    } else if (p->type == idType) {
	free(p->id.value);
    }
    free(p);
}

void stack_init(Stack *s) {
    s->sizeNum = 0;
    s->sizeId = 0;
}

void stack_pushNum(Stack *s, int val) {
    if (s->sizeNum < STACK_MAX)
	s->num[s->sizeNum++] = val;
}

void stack_pushId(Stack *s, const char *val) {
    if (s->sizeId < STACK_MAX)
	s->id[s->sizeId++] = strdup(val);
}

int stack_popNum(Stack *s) {
    if (s->sizeNum != 0) {
	s->sizeNum--;
	return s->num[s->sizeNum];
    } else
	return -1;
}

char *stack_popId(Stack *s) {
    char *nP;
    if (s->sizeId != 0) {
	s->sizeId--;
	return s->id[s->sizeId];
    } else
	return NULL;
}

int stack_topNum(Stack *s) {
    if (s->sizeId > 0)
        return s->num[s->sizeNum-1];
    else
        return -1;
}

char *stack_topId(Stack *s) {
    if (s->sizeId > 0)
        return s->id[s->sizeId-1];
    else
        return NULL;
}

void stack_shuffleTopNum(Stack *s) {
    if (s->sizeNum > 1) {
        int temp1 = stack_popNum(s);
        int temp2 = stack_popNum(s);
        stack_pushNum(s, temp1);
        stack_pushNum(s, temp2);
    }
}

void stack_shuffleTopId(Stack *s) {
    if (s->sizeId > 1) {
        char *temp1 = stack_popId(stack);
        char *temp2 = stack_popId(stack);
        stack_pushId(stack, temp1);
        stack_pushId(stack, temp2);
    }
}

void printQuads(nodeType *node) {
    if (!node) return;
    switch (node->type) {
    case numType:
	stack_pushNum(stack, node->num.value);
	break;
    case idType:
	stack_pushId(stack, node->id.value);
	break;
    case opType:
	switch (node->opr.oper) {
	case ASSIGN:
	    printQuads(node->opr.op[1]);
	    if (node->opr.op[1]->type == opType) {
		char *id = stack_popId(stack);
		if (strcmp(id, "tmp") == 0)
		    printf("\tMOV  %s%d  NULL  %s\n", id, tmp-1, node->opr.op[0]->id.value);
		else
		    printf("\tMOV  %s  NULL  %s\n", id, node->opr.op[0]->id.value);
	    } else if (node->opr.op[1]->type == numType)
		printf("\tMOV  %d  NULL  %s\n", stack_popNum(stack), node->opr.op[0]->id.value);
            else
                printf("\tMOV  %s  NULL  %s\n", stack_popId(stack), node->opr.op[0]->id.value);
	    break;
        case IF:
            printQuads(node->opr.op[0]);
            if (node->opr.op[0]->type == numType)
                printf("\tJZ   %d  NULL  lbl%d\n", stack_popNum(stack), lbl);
            else {
                char *id = stack_popId(stack);
                if (strcmp(id, "tmp") == 0)
                    printf("\tJZ   %s%d  NULL  lbl%d\n", id, tmp-1, lbl);
                else
                    printf("\tJZ  %s  NULL  lbl%d\n", id, lbl);
            }
            printQuads(node->opr.op[1]);
            if (!(node->opr.op[1]->type == opType && node->opr.op[1]->opr.oper == IF)) {
                printf("lbl%d:\n", lbl);
                lbl++;
            }
            break;
        case PRINT:
            printQuads(node->opr.op[0]);
            if (node->opr.op[0]->type == numType)
                printf("\tPRT  %d  NULL  NULL\n", stack_popNum(stack)); 
            else
                printf("\tPRT  %s  NULL  NULL\n", stack_popId(stack));
            break;
	default:
	    printQuads(node->opr.op[0]);
	    printQuads(node->opr.op[1]);
	    switch(node->opr.oper) {
	    case '+':
                if (node->opr.op[0]->type == numType && node->opr.op[1]->type == numType)
                    stack_shuffleTopNum(stack);
                else if (node->opr.op[0]->type == idType && node->opr.op[1]->type == idType)
                    stack_shuffleTopId(stack);
                
		if (node->opr.op[0]->type == numType) {
		    printf("\tADD  %d  ", stack_popNum(stack));
                }
		else {
		    char *id = stack_popId(stack);
		    if (strcmp(id, "tmp") == 0)
			printf("\tADD  %s%d  ", id, tmp-1);
		    else
			printf("\tADD  %s  ", id);
		}
		if (node->opr.op[1]->type == numType)
		    printf("%d  tmp%d\n", stack_popNum(stack), tmp);
		else {
		    char *id = stack_popId(stack);
		    if (strcmp(id, "tmp") == 0)
			printf("%s%d  tmp%d\n", id, tmp-1, tmp);
		    else
			printf("%s  tmp%d\n", id, tmp);
		    free(id);
		}
		stack_pushId(stack, "tmp");
		tmp++;
		break;
	    case AND:
                if (node->opr.op[0]->type == numType && node->opr.op[1]->type == numType)
                    stack_shuffleTopNum(stack);
                else if ((node->opr.op[0]->type == idType) && (node->opr.op[1]->type == idType))
                    stack_shuffleTopId(stack);
                
		if (node->opr.op[0]->type == numType) {
		    printf("\tAND  %d  ", stack_popNum(stack));
                }
		else {
		    char *id = stack_popId(stack);
		    if (strcmp(id, "tmp") == 0)
			printf("\tAND  %s%d  ", id, tmp-1);
		    else
			printf("\tAND  %s  ", id);
		}
		if (node->opr.op[1]->type == numType)
		    printf("%d  tmp%d\n", stack_popNum(stack), tmp);
		else {
		    char *id = stack_popId(stack);
		    if (strcmp(id, "tmp") == 0)
			printf("%s%d  tmp%d\n", id, tmp-1, tmp);
		    else
			printf("%s  tmp%d\n", id, tmp);
		    free(id);
		}
		stack_pushId(stack, "tmp");
		tmp++;
		break;
	    }
	}
    }
}