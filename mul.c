#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Dlist* multiplication(Dlist *tail1, Dlist *tail2)
{
    Dlist *head3 = NULL;
    Dlist *temp2 = tail2;

    int zeros = 0;

    while(temp2 != NULL)
    {
        Dlist *head = NULL;
        Dlist *temp1 = tail1;

        int carry = 0;

        for(int i=0;i<zeros;i++)
        {
            Dlist *final = malloc(sizeof(Dlist));
            if(!final) return NULL;

            final->data=0;
            final->prev=NULL; 
            final->next=head;

            if(head)
             head->prev = final;

            head=final;
        }
        //traverse
        while(temp1 != NULL)
        {
            Dlist *final = malloc(sizeof(Dlist));
            if(!final) return NULL;

            final->prev=NULL;

            int res = temp1->data * temp2->data + carry; //multiplication here..

            carry = res/10;
            final->data = res%10;

            final->next=head;

            if(head)
             head->prev=final;

            head=final;
            temp1=temp1->prev;// temp1 update with previous node
        }

        if(carry) // carry still have value then 'insert first operation'...
        {
            Dlist *final = malloc(sizeof(Dlist));
            if(!final) return NULL;

            final->data=carry;
            final->prev=NULL;
            final->next=head;
            head->prev=final;
            head=final;
        }

        if(head3==NULL) //list empty 
         head3=head;
        else             // not mepty traverse thorugh last node
        {
            Dlist *t1=head3;
            while(t1->next) // until NULL , it takes last node address, update t1
            t1=t1->next;

            Dlist *t2=head;
            while(t2->next) // t2 update with last node
            t2=t2->next;

            head3 = add(t1,t2); // calling addition to perform add operation
        }

        zeros++; //for next nxt line +0's
        temp2=temp2->prev;
    }

    return head3;
}