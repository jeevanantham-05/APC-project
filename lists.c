#include<stdio.h>
#include"header.h"


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
        //create list 1 by performing insert last
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
    //`printf("list1: \n");
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
        if(add(*tail1,*tail2) != success)
        {
            printf("ERROR: Addition final list creation fails\n");
        }
        break;

    //subraction
        case '-':
        int flag =0;
        if(symbol(str[1],str[3]) < 0)
        {
            flag =1;
            if(sub(*tail2,*tail1,flag) != success)
            {
                 printf("ERROR: Subraction final list creation fails\n");
            }
        } 
        else
        {
            if(sub(*tail1,*tail2,flag) != success)
            {
                printf("ERROR: Subraction final list creation fails\n");
            }
        }
        break;

    //multiplication
        case 'x':
        if(mul(*tail1,*tail2) != success)
        {
            printf("ERROR: Multiplication final list creation fails\n");
        }
        break;

    //Division
        case '/':
        if(divv(*tail1,*tail2) != success)
        {
            printf("ERROR: Division final list creation fails\n");
        }
        break;

    }
    return success;
}


/*........comparing digit greater or lower and flag - or +.......*/
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
    else if(ln == ln2)
    {
        if(s1[0]>s2[0])
         return 1;
        else
         return -1;
    }
    else 
    return 1;

}