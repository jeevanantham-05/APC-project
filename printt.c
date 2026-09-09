#include<stdio.h>
#include"header.h"

void  printres(Dlist *head)
{
    if(head== NULL)
    {
        printf("0\n");
        return;
    }
    
    /* SKIP ZEROS */ 
    while(head->next != NULL && head->data == 0)
    {
        head = head->next;
    }

    Dlist *temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

