#include<stdio.h>
#include"header.h"


Dlist* multiplication(Dlist *tail1, Dlist *tail2)
{
    Dlist *finalResult = NULL;
    Dlist *temp2 = tail2;
    int zeros = 0;

    while(temp2 != NULL)
    {
        Dlist *head = NULL;
        Dlist *temp1 = tail1;
        int carry = 0;

        for(int i=0; i<zeros; i++){
            Dlist *z=malloc(sizeof(Dlist));
            z->data=0;
            z->prev=NULL;
            z->next=head;
            if(head) 
            head->prev=z; 
            head=z;
        }

        while(temp1){
            Dlist *final=malloc(sizeof(Dlist));
            final->prev=NULL;
            int r = temp1->data * temp2->data + carry;
            carry=r/10; 
            final->data=r%10;
            final->next=head;
            if(head) 
            head->prev=final; 
            head=final;
            temp1=temp1->prev;
        }
        if(carry){
            Dlist *final=malloc(sizeof(Dlist));
            final->data=carry; 
            final->prev=NULL; 
            final->next=head;
            head->prev=final;
             head=final;
        }

        if(finalResult==NULL) finalResult=head;
        else{
            Dlist *t1=finalResult;
            while(t1->next) t1=t1->next;
            Dlist *t2=head; 
            while(t2->next) t2=t2->next;
            finalResult = add(t1, t2); 
        }
        zeros++; temp2=temp2->prev;
    }

    return finalResult;
}