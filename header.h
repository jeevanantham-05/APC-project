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

int insertlast(Dlist **, Dlist **, char []);
int process(Dlist **, Dlist **, char *[]);

void printfunc(Dlist *);
void  printres(Dlist *);

Dlist* add(Dlist *, Dlist *);

Dlist* sub(Dlist *, Dlist *);
int symbol(char [], char []);

Dlist*  multiplication(Dlist *tail1, Dlist *tail2);

int divv(Dlist *, Dlist *);