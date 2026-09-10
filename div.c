#include <stdio.h>
#include <stdlib.h>
#include "header.h"


Dlist* division(Dlist *tail1, Dlist *tail2)
{
    /*head poits to 1st node so travesre, because i passing tail that mean last node so.....*/
    Dlist *head1 = tail1;
    while(head1->prev != NULL) 
    head1 = head1->prev;

    Dlist *head2 = tail2;
    while(head2->prev != NULL)
     head2 = head2->prev;

     /*removing zeros for length comarision, which one higer data...*/
    head1 = removezero(head1);
    head2 = removezero(head2);

    if(head2->data==0 && head2->next==NULL) //number / 0 , is undefined so, i return error 'eg -> 55 / 0'
    {
        printf("ERROR: Divide by zero\n");
        return NULL;
    }

    if(symbolList(head1, head2)<0)
    {
        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return NULL;

        final->data = 0;
        final->prev = NULL; 
        final->next = NULL;
        return final;
    }

    Dlist *rem = NULL; //reminder
    Dlist *head3 = NULL; 
    Dlist *tail3 = NULL;
    Dlist *cur = head1; //current

    while(cur!= NULL)
    {
        if(rem==NULL)
        {
            rem = malloc(sizeof(Dlist));
            if(!rem) return NULL;

            rem->data = cur->data;
            rem->prev = NULL;
            rem->next = NULL;
        }
        else
        {
            if(rem->data==0 && rem->next==NULL)
             rem->data = cur->data;
            else
            {
                Dlist *temp = rem;
                while(temp->next!= NULL)
                 temp=temp->next;

                Dlist *new = malloc(sizeof(Dlist));
                if(!new) return NULL;

                new->data = cur->data;
                new->next = NULL; 
                new->prev = temp;
                temp->next = new;
            }
        }
        rem = removezero(rem);
        int q=0;
        if(symbolList(rem, head2)>=0)
        {
            for(int i=9;i>=1;i--)
            {
                Dlist *temp1 = head2;
                while(temp1->next!= NULL)
                 temp1=temp1->next;

                int carry=0;
                Dlist *head4 = NULL;
                while(temp1!= NULL)
                {
                    Dlist *final = malloc(sizeof(Dlist));
                    if(!final) return NULL;

                    final->prev = NULL;

                    int res = temp1->data * i + carry;

                    carry = res/10;

                    final->data = res%10;
                    final->next = head4;
                    if(head4)
                    head4->prev = final;

                    head4 = final;
                    temp1 = temp1->prev; //updating with previous node
                }
                if(carry)
                {
                    Dlist *final = malloc(sizeof(Dlist));
                    if(!final) return NULL;

                    final->data = carry; 
                    final->prev = NULL; 
                    final->next = head4;
                    head4->prev = final;
                    head4 = final;
                }
                if(symbolList(head4, rem)<=0)
                {
                    q=i; //quotient
                    Dlist *rt = rem;  //reminder tail travers to last
                    while(rt->next!= NULL) 
                    rt=rt->next;

                    Dlist *pt = head4;  // product tail traverse to last
                    while(pt->next!= NULL) 
                    pt=pt->next;

                    rem = sub(rt, pt); // passing rt,pt  tail
                    break;
                }
            }
        }
        if(head3==NULL && q==0) //for skipping leading zeros ...
        { 
            cur = cur->next;
            continue; 
        }

        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return NULL;

        final->data = q; 
        final->next = NULL;

        if(head3==NULL)
        { 
            head3 = tail3 = final; 
            final->prev = NULL; 
        }
        else
        { 
            tail3->next = final; 
            final->prev = tail3; 
            tail3 = final; 
        }
        cur = cur->next;
    }

    if(head3==NULL)
    {
        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return NULL;

        final->data = 0;
        final->prev = NULL;
        final->next = NULL;
        return final;
    }

    return head3;
}