#include<stdio.h>
#include"header.h"

Dlist *head = NULL;
Dlist *tail = NULL;

int add(Dlist *tail1, Dlist *tail2)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int res=0, carry=0;

    while(temp1 != NULL || temp2 != NULL || carry==1)
    {
        

        //create final list
        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return fail;

        //this is insert first operations so previous alwasy NULL only
        final->prev = NULL;

    /*........if list 1&2 end but last carry have 1 means directly add in list...... */
        if(temp1==NULL && temp2 == NULL && carry ==1)
        {
            final->data = carry;
            Dlist *old = head; //backup previous node address

            final->next = old;
            head = final;
            old->prev = final;
            break;
        }

        //data value storing part
        if(temp1==NULL)
        {
            res = temp2->data + carry;
        }
        else if(temp2==NULL)
        {
            res = temp1->data + carry;
        }
        else
        res = temp1->data + temp2->data + carry;

        //if res >9 then carry will keep carry value
        if(res>9) carry = 1;
        else carry = 0;

        //taking ryt most one digit in result 
        res = res%10;

        final->data = res;
/*.....................performing insert first operations..............*/

        //Empty list
        if(head==NULL)
        {
            head = tail = final;
            final->next = NULL;
        }
        else
        {
            //list not empty
            Dlist *old = head; //backup previous node address

            final->next = old;
            head = final;
            old->prev = final;
        }

        //updating temp with previous node addres in list1 and 2
        if(temp1!=NULL)
        temp1 = temp1->prev;
        if(temp2!=NULL)
        temp2 = temp2->prev;
    }

    printf("addition result: \n");
    printres(head);
    
    return success;
}


//........................................sub.........................//.

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

    printf("subtraction result: \n");
    printres(head3); 

    return success;
}