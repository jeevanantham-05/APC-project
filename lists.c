#include<stdio.h>
#include"header.h"

/* creating link lists.......................*/

Dlist *head1 = NULL;
Dlist *tail1 =NULL;

Dlist *head2 = NULL;
Dlist *tail2 =NULL;

int linklist(char **str)
{

//list 1........................................................

    char *arg1=str[1];
    int i=0;
    char ch = arg1[i];

    while( ch != '\0')
    {
        //create list 1 by performing insert last
        Dlist *opr1 = malloc(sizeof(Dlist));
        if(!opr1) return fail;

        opr1->data = ch - '0';
        opr1->next = NULL;

        if(head1==NULL)
        {
            head1=tail1=opr1;
            opr1->prev =NULL;
        }
        else{
            tail1->next = opr1;
            opr1->prev = tail1;
            tail1 = opr1;
        }

        ch = arg1[++i];
    }
    printf("list1: \n");
    printfunc(head1);
//list 2...................................................

    char *arg2=str[3];
    int j=0;
    char chh = arg2[j];
    while( chh != '\0')
    {
        //create list 2 by performing insert last
        Dlist *opr2 = malloc(sizeof(Dlist));
        if(!opr2) return fail;

        opr2->data = chh - '0';
        opr2->next = NULL;

        if(head2==NULL)
        {
            head2=tail2=opr2;
            opr2->prev =NULL;
        }
        else{
            tail2->next = opr2;
            opr2->prev = tail2;
            tail2 = opr2;
        }

        chh = arg2[++j];
    }
    printf("list2: \n");
    printfunc(head2);

//checking user input operations..........................................

    char *s = str[2];
    char c = s[0];
    switch(c)
    {
        case '+':
        if(add(tail1,tail2) != success)
        {
            printf("ERROR: final list creation fails\n");
        }
        break;

        case '-':
        //sub(tail1,tail2);
        break;
    }

    return success;
}
