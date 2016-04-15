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
extern YYSTYPE yylval;
