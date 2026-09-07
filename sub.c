#include<stdio.h>
#include"header.h"




Dlist *head3 = NULL;
Dlist *tail3 = NULL;

int sub(Dlist *tail1, Dlist *tail2)
{
    Dlist *temp1 = tail1; 
    Dlist *temp2 = tail2; 
    int borrow = 0;

    while(temp1!= NULL) //only checking temp1 because temp1 only contain big value so that
    {
        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return fail;
        final->prev = NULL;

        int d1 = temp1->data;
        int d2 = 0;       // if temp2 reach null then it data update as '0'
        if(temp2!= NULL)
        d2 = temp2->data;

        //data value storing part
        int res = d1 - borrow - d2;

        if(res < 0) //value -ve then borrow concep
        {
            res = res + 10;
            borrow = 1;
        }
        else
        borrow = 0;
        
        final->data = res; // data updation

    /* ..........Insert first logic implementing here ...........*/

        if(head3 == NULL)
        {
            head3 = tail3 = final;
            final->next = NULL;
        }
        else
        {
            Dlist *old = head3;
            final->next = old;
            head3 = final;
            old->prev = final;
        }

 //updating temps with previous node addres in list1 and 2
        temp1 = temp1->prev;
        if(temp2!= NULL) temp2 = temp2->prev;
    }

    // deleting L.H.S side zeros '005' -> '5 to get like this
    while(head3!= NULL && head3->data == 0 && head3->next!= NULL)
    {
        Dlist *temp = head3;
        head3 = head3->next;
        free(temp);
        head3->prev = NULL;
    }
    printres(head3); 

    return success;
}