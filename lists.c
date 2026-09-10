#include<stdio.h>
#include"header.h"

/*create list by performing insert last*/
int insertlast(Dlist **head, Dlist **tail, char str[])
{
    int i=0;
    char ch = str[i];

    while( ch != '\0')
    {
        if(ch == '-' || ch == '+')
        {
            ch = str[++i];
            continue;
        }
        
        Dlist *new = malloc(sizeof(Dlist));
        if(!new) return fail;

        new->data = ch - '0';
        new->next = NULL;

        if(*head==NULL)
        {
            *head=*tail=new;
            new->prev =NULL;
        }
        else{
            (*tail)->next = new;
            new->prev = *tail;
            *tail = new;
        }

        ch = str[++i];
    }
    return success;
}


/*.........................ARITHEMITC OPERATIONS......................*/

int process(Dlist **tail1, Dlist **tail2, char *str[])
{
    char c = str[2][0];
    
    switch(c)
    {
    //addition
        case '+':
        Dlist *resl = add(*tail1,*tail2);
        if( resl == fail )
        {
            printf("ERROR: Addition final list creation fails\n");
        }
        else {
             printf("result: ");
             printres(resl);
        }
        break;

    //subraction
        case '-':
        printf("result: ");
        if(symbol(str[1], str[3]) < 0)
        {
            printf("-");
            Dlist *Sres = sub(*tail2,*tail1);
            printres(Sres);

        }
        else{
            Dlist *Sres = sub(*tail1,*tail2);
            printres(Sres);
        }
        break;

    //multiplication
        case 'x':
        Dlist *mres = multiplication(*tail1,*tail2);
          
        if( mres == fail)
        {
            printf("ERROR: Multiplication final list creation fails\n");
        }
        else{
            printf("result: ");
           printres(mres);
        }
        break;

    //Division
        case '/':
        Dlist *Dres = division(*tail1,*tail2);
          
        if( Dres == fail)
        {
            printf("ERROR: Division final list creation fails\n");
        }
        else{
            printf("result: ");
           printres(Dres);
        }
        break;

    }
    return success;
}


/*........ comparing digit greater or lower and flag - or +  .......*/
int symbol(char str1[], char str2[])
{
    char *s1 = str1;
    char *s2 = str2;
    
    //skips zeros lhs side 0012 -> '12'
    while( *s1 == '0' && *(s1+1)!='\0') s1++;
    while( *s2 == '0' && *(s2+1)!='\0') s2++;

    int ln = strlen(s1);
    int ln2 = strlen(s2);

    if(ln<ln2)
    return -1;
    else if(ln>ln2)
    return 1;
    else
    {
        int cmp = strcmp(s1,s2);
        if(cmp>0) return 1;
        else if (cmp<0) return -1;
        else return 0;
    }


}

/*Removing L.H.S ide leading zerossss*/
Dlist* removezero(Dlist *head)
{
    while(head!= NULL && head->data == 0 && head->next!= NULL)
    {
        Dlist *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    return head;
}

/*comparsion for which one is higher data..by passing node address .*/
int symbolList(Dlist *head1, Dlist *head2)
{
    head1 = removezero(head1);
    head2 = removezero(head2);

    int ln=0, ln2=0;

    Dlist *temp = head1;
    while(temp!= NULL)
    { 
        ln++; 
        temp=temp->next; 
    }
    temp = head2;
    while(temp!= NULL)
    { 
        ln2++; 
        temp=temp->next; 
    }

    if(ln<ln2) return -1;
    else if(ln>ln2) return 1;
    else
    {
        Dlist *temp1 = head1;
        Dlist *temp2 = head2;
        while(temp1!= NULL)
        {
            if(temp1->data > temp2->data) 
            return 1;
            if(temp1->data < temp2->data) 
            return -1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return 0;
    }
}