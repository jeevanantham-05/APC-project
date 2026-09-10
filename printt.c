#include <stdio.h>
#include "header.h"

void printres(Dlist *head)
{
    if(head == NULL)
    { 
        printf("0\n");
        return; 
    }

    while(head->next != NULL && head->data == 0) // it will skip more thsan 1 zeros 
    head = head->next;

    Dlist *temp = head;
    while(temp!=NULL)
    { 
        printf("%d",temp->data); 
        temp = temp->next; 
    }
    printf("\n");
}