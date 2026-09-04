#include<stdio.h>
#include"header.h"

//list type print
void printfunc(Dlist *head)
{
    Dlist *temp = head;

    printf("Head");
    while(temp!=NULL)
    {
        printf("<-%d->",temp->data);
        temp = temp->next;
    }
    printf("Tail\n");
}

//normal print
void  printres(Dlist *head)
{
    Dlist *temp = head;

    
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

