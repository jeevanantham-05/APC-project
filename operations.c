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


........................................sub.........................//.

int sub(Dlist *tail1, Dlist *tail2)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int res=0, barrow=0;

    while(temp1 != NULL || temp2 != NULL )
    {

        //create final list
        Dlist *final = malloc(sizeof(Dlist));
        if(!final) return fail;

        //data value storing part
        if(temp1==NULL)
        res = temp2->data - barrow;
        else if(temp2==NULL)
        res = temp1->data - barrow;
        else
        res = temp1->data + temp2->data + carry;

        //if res >9 then carry will keep carry value
        if(res>9) carry = 1;
        else carry = 0;

        //taking ryt most one digit in result 
        res = res%10;

        final->data = res;
        final->prev = NULL;

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
    printfunc(head);
    
    return success;
}
