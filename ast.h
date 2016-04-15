typedef enum { numType, idType, opType } nodeEnum;

typedef struct {
    int value;
} numNode;

typedef struct {
    char *value;
} idNode;

typedef struct {
    int oper;			// operator;
    int nops;			// num of operands
    struct nodeTypeTag **op;	// operands
} opNode;

typedef struct nodeTypeTag {
    nodeEnum type;
    
    union {
	numNode num;
	idNode id;
	opNode opr;
    };
} nodeType;

#define STACK_MAX 100

typedef struct {
    int num[STACK_MAX];
    char *id[STACK_MAX];
    int sizeNum;
    int sizeId;
}Stack;

#define MAX_SYMBOL 500

typedef struct {
    char *symbol;
    int value;
} Symbol;

Symbol *sym[MAX_SYMBOL];