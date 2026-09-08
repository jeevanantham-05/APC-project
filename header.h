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

int operatorr(char *);

int linklist(char **);

void printfunc(Dlist *);
void  printres(Dlist *);

int add(Dlist *, Dlist *);

int sub(Dlist *, Dlist *, int );
int symbol(char **);

int mul(Dlist *, Dlist *);

int divv(Dlist *, Dlist *);