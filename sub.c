#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Dlist* sub(Dlist *tail1, Dlist *tail2)
{
    Dlist *head3 = NULL;
    Dlist *temp1 = tail1; 
    Dlist *temp2 = tail2; 

    int borrow = 0;

    while(temp1!= NULL)
    {
        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return NULL;

        final->prev = NULL;

        int data1 = temp1->data;
        int data2 = (temp2!=NULL) ? temp2->data : 0; //temp2 reach NULL then update with '0' ternary operations

        int res = data1 - borrow - data2;

        if(res < 0)
        {
            res = res + 10;
            borrow = 1;
        }
        else borrow=0;

        final->data = res;

    /*...Insert first logic .......*/
        if(head3 == NULL)
        { 
            head3 = final; 
            final->next = NULL; //this for empty list case
        }
        else { 
            final->next = head3; // this for not empty list case
            head3->prev = final; 
            head3 = final;
        }
     //temps updating with previous node link   
        temp1 = temp1->prev;
        if(temp2) temp2 = temp2->prev;
    }

    /* Removing zeros from LHS sides at last step ........*/
    while(head3 && head3->data==0 && head3->next!=NULL)
    {
        Dlist *temp = head3;
        head3 = head3->next;
        head3->prev = NULL;
        free(temp);
    }
    //finall return result node address for printing result
    return head3;
}