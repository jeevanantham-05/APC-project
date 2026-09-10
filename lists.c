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

    int s1 = 1, s2 = 1;

    if(str[1][0]=='-') 
    s1=-1;
    else if(str[1][0]=='+') 
    s1=1;
    if(str[3][0]=='-') 
    s2=-1;
    else if(str[3][0]=='+') 
    s2=1;

    /*make h1&2 heads point to first so traverse backward*/
    Dlist *h1 = *tail1; 
    while(h1->prev)
     h1=h1->prev;

    Dlist *h2 = *tail2; 
    while(h2->prev) 
    h2=h2->prev;

    //passing expression through switch
    switch(c)
    {
        case '+':
            if(s1==1 && s2==1)
            {
                Dlist *resl = add(*tail1,*tail2);
                printf("result: ");
                printres(resl);
            }
            else if(s1==1 && s2==-1) 
            {
                printf("result: ");
                if(symbolList(h1,h2) >=0)
                { 
                    Dlist *Sres = sub(*tail1,*tail2); 
                    printres(Sres); 
                }
                else 
                { 
                    printf("-"); 
                    Dlist *Sres = sub(*tail2,*tail1); 
                    printres(Sres); 
                }
            }
            else if(s1==-1 && s2==1) // -1 + 2
            {
                printf("result: ");
                if(symbolList(h2,h1) >=0) 
                { 
                    Dlist *Sres = sub(*tail2,*tail1); 
                    printres(Sres); 
                }
                else 
                { 
                    printf("-"); 
                    Dlist *Sres = sub(*tail1,*tail2); 
                    printres(Sres); 
                }
            }
            else // -1 + -1
            {
                printf("result: -");
                Dlist *resl = add(*tail1,*tail2);
                printres(resl);
            }
            break;

        case '-':
            printf("result: ");
            if(s1==1 && s2==1)
            {
                if(symbolList(h1,h2) < 0) 
                { 
                    printf("-"); 
                    Dlist *Sres = sub(*tail2,*tail1); 
                    printres(Sres); 
                }
                else 
                { 
                    Dlist *Sres = sub(*tail1,*tail2); 
                    printres(Sres);
                }
            }
            else if(s1==1 && s2==-1) // 1 - (-1) => +
            {
                Dlist *resl = add(*tail1,*tail2);
                printres(resl);
            }
            else if(s1==-1 && s2==1) // -1 - 1
            {
                printf("-");
                Dlist *resl = add(*tail1,*tail2);
                printres(resl);
            }
            else // -1 - -1
            {
                if(symbolList(h2,h1) < 0) 
                { 
                    printf("-"); 
                    Dlist *Sres = sub(*tail1,*tail2); 
                    printres(Sres); }
                else 
                { 
                    Dlist *Sres = sub(*tail2,*tail1); 
                    printres(Sres); 
                }
            }
            break;

        case 'x':
            if(s1*s2==-1) 
            printf("result: -");
            else
            printf("result: ");

            Dlist *mres = multiplication(*tail1,*tail2);
            printres(mres);
            break;

        case '/':
            if(s1*s2==-1) 
            printf("result: -");
            else 
            printf("result: ");
            Dlist *Dres = division(*tail1,*tail2);
            printres(Dres);
            break;
    }
    return success;
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
    /*first removing leadind zeros by calling remove() functiom*/
    head1 = removezero(head1);
    head2 = removezero(head2);

    int ln=0, ln2=0;

    /*counting list 1 and 2 length by traverseing...*/
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

    //returning final comparision result.....
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