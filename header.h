#include<ctype.h>
#include<string.h>
#include<stdlib.h>


//for cmd line validation macros
#define invalid 0
#define valid 1

//for function validations
#define fail 0
#define success 1

//structure
typedef struct LIST{
    struct LIST *prev;
    int data;
    struct LIST *next;
}Dlist;

//function proto-types
int digit(char *);

int operator(char *);

int linklist(char **);

void printfunc(Dlist *);

int add(Dlist *, Dlist *);