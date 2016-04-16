/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "project.y"
    
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
/*int yydebug = 1;*/

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
#line 36 "project.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int number;
    char *string;
    nodeType *nPtr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 68 "project.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PROGRAM 257
#define BLOCK 258
#define BEGIN_T 259
#define END_T 260
#define IF 261
#define THEN 262
#define ASSIGN 263
#define PRINT 264
#define ID 265
#define NUM 266
#define AND 267
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    3,    3,    3,    3,
    4,    4,    4,    4,
};
static const YYINT yylen[] = {                            2,
    5,    3,    3,    1,    3,    1,    4,    3,    2,    3,
    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    0,    0,    1,    3,   13,   14,    0,    0,    0,
    0,    2,    0,    0,    0,    0,   10,    0,    5,    7,
    0,   12,
};
static const YYINT yydgoto[] = {                          2,
   11,   12,   13,   18,
};
static const YYINT yysindex[] = {                      -247,
 -258,    0,  -41, -235, -250,  -30, -230, -239, -239, -243,
    0, -229,  -27,    0,    0,    0,    0,  -43,  -42, -236,
 -239,    0, -236, -236, -239, -239,    0,  -42,    0,    0,
 -234,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -226,    0,    0,    0,    0,    0,  -57,    0,
    0,    0,    0,    0,    0,    0,    0,  -55,    0,    0,
  -40,    0,
};
static const YYINT yygindex[] = {                         0,
   31,   13,  -12,   -4,
};
#define YYTABLESIZE 225
static const YYINT yytable[] = {                         25,
   25,    9,   11,    8,   19,    7,    3,   27,    5,    1,
    8,   30,   20,    9,   10,   14,   28,    4,   11,   21,
   31,   32,    5,    5,    8,   16,   17,    9,   10,   15,
   22,   23,   26,    4,    6,   29,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    9,    0,    8,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   24,   11,
    0,   11,    0,   26,   26,
};
static const YYINT yycheck[] = {                         43,
   43,   59,   43,   59,    9,  256,  265,   20,  259,  257,
  261,   24,  256,  264,  265,   46,   21,   59,   59,  263,
   25,   26,  259,  259,  261,  265,  266,  264,  265,  260,
  260,   59,  267,  260,    4,   23,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  260,   -1,  260,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  260,
   -1,  262,   -1,  267,  267,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 267
#define YYUNDFTOKEN 274
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'+'",0,0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PROGRAM","BLOCK",
"BEGIN_T","END_T","IF","THEN","ASSIGN","PRINT","ID","NUM","AND",0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : prog",
"prog : PROGRAM ID ';' block '.'",
"block : BEGIN_T list END_T",
"block : BEGIN_T error END_T",
"list : stmt",
"list : stmt ';' list",
"stmt : block",
"stmt : IF expr THEN stmt",
"stmt : ID ASSIGN expr",
"stmt : PRINT expr",
"stmt : ID error stmt",
"expr : expr '+' expr",
"expr : expr AND expr",
"expr : ID",
"expr : NUM",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 173 "project.y"

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
#line 560 "project.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 53 "project.y"
	{
					if (t_opt || v_opt) {
					    printf("Reducing by rule #1");
					    if (v_opt)
						printf("\tline #%d (PROGRAM)", yylineno);
					    printf("\n");
					}
					root = yystack.l_mark[-1].nPtr;
					}
break;
case 2:
#line 64 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #2");
				    if (v_opt)
					printf("\tline #%d (BEGIN statement_list END)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = yystack.l_mark[-1].nPtr;
				}
break;
case 3:
#line 73 "project.y"
	{ yyerrok; }
break;
case 4:
#line 76 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #3");
				    if (v_opt)
					printf("\tline #%d (STATEMENT)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = yystack.l_mark[0].nPtr;
				}
break;
case 5:
#line 85 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #4");
				    if (v_opt)
					printf("\tline #%d (STATEMENT_LIST)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = opr(';', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr);
				}
break;
case 6:
#line 96 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #5");
				    if (v_opt)
					printf("\tline #%d (BLOCK)", yylineno);
				    printf("\n");
				}
				}
break;
case 7:
#line 104 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #6");
				    if (v_opt)
					printf("\tline #%d (IF expression THEN statement)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = opr(IF, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr);
				}
break;
case 8:
#line 113 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #7");
				    if (v_opt)
					printf("\tline #%d (ASSIGNMENT)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = opr(ASSIGN, 2, id(yystack.l_mark[-2].string), yystack.l_mark[0].nPtr);
				}
break;
case 9:
#line 122 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #8");
				    if (v_opt)
					printf("\tline #%d (PRINT)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = opr(PRINT, 1, yystack.l_mark[0].nPtr);
				}
break;
case 10:
#line 131 "project.y"
	{ yyerrok; }
break;
case 11:
#line 134 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #9");
				    if (v_opt)
					printf("\tline #%d (expression + expression)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = opr('+', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr);
				}
break;
case 12:
#line 143 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #10");
				    if (v_opt)
					printf("\tline #%d (expression AND expression)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = opr(AND, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr);
				}
break;
case 13:
#line 152 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #11");
				    if (v_opt)
					printf("\tline #%d (NAME)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = id(yystack.l_mark[0].string);
				}
break;
case 14:
#line 161 "project.y"
	{
				if (t_opt || v_opt) {
				    printf("Reducing by rule #12");
				    if (v_opt)
					printf("\tline #%d (INTEGER)", yylineno);
				    printf("\n");
				}
				yyval.nPtr = num(yystack.l_mark[0].number);
				}
break;
#line 913 "project.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
