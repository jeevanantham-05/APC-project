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
        int flag =0;
        if(symbol(str[1],str[3]) < 0)
            flag =1;
        Dlist *Sres = sub(*tail1,*tail2);
        if( Sres == fail)
        {
            printf("ERROR: Subraction final list creation fails\n");
        }
        else{
            printf("result: ");
            if(flag)
            printf("-");
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
        if(divv(*tail1,*tail2) != success)
        {
            printf("ERROR: Division final list creation fails\n");
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
