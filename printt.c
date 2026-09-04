#include<stdio.h>
#include"header.h"

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