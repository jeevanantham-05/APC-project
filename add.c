#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Dlist* add(Dlist *tail1, Dlist *tail2)
{
    Dlist *head = NULL;
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int res=0, carry=0;

    while(temp1 != NULL || temp2 != NULL || carry==1) //temp reach NULL and carry have 1 then add it last as it 
    {
        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return NULL;

        final->prev = NULL;
        if(temp1==NULL && temp2==NULL && carry==1)
        {
            final->data = carry;
            final->next = head;
            if(head) 
            head->prev = final;

            head = final;
            break;
        }

        if(temp1==NULL) 
        res = temp2->data + carry;
        else if(temp2==NULL)
        res = temp1->data + carry;
        else 
        res = temp1->data + temp2->data + carry;

        carry = (res>9) ? 1 : 0; // by using ternry so total > 9 then add 1 to carry

        res = res%10; // taking last digit, adding to list

        final->data = res;

        /*...Insert First operation performing here....*/
        if(head==NULL)
        {
            head = final;
            final->next = NULL;
        }
        else
        {
            final->next = head;
            head->prev = final;
            head = final;
        }
        if(temp1) temp1 = temp1->prev; //uptating temps with previous node link
        if(temp2) temp2 = temp2->prev;
    }
    return head;
}