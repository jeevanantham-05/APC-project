#include<stdio.h>
#include"header.h"


int main(int count, char *str[]) ///.a.out 1234 + 1234
{

    if(count==4)
    {
        if(digit(str[1])==valid) //checking operand 1 digit or not
        {
                Dlist *head1 = NULL;
                Dlist *tail1 =NULL;
                if(insertlast(&head1,&tail1,str[1])==success)
                {
                    printf("list1 created success\n");
                    printres(head1);
                }
                else printf("ERROR: list1 not created\n");
            if(digit(str[3])==valid) //checking operand 2 digit or not
            {
                Dlist *head2 = NULL;
                Dlist *tail2 =NULL;
                if(insertlast(&head2,&tail2,str[3])==success)
                {
                    printf("list2 created success\n");
                    printres(head2);
                }
                else printf("ERROR: list not created\n");

                if(operatorr(str[2])==valid) //checking input valid operator or not
                {
                    if(process(&tail1,&tail2,str) == success)
                    printf("All operation success\n");
                    else
                    printf("ERROR: Arthmetics Process fail\n");

                }
                else printf("ERROR: Invalid operator, valid are \" + - x / \"\n");
            }
            else printf("ERROR: Operand2 should be integer only or one sign only allowed\n");
        }
        else printf("ERROR: Operand1 should be integer only or one sign only allowed\n");
    }
    else printf("ERROR: Aruguments should be 'operand1' operator 'operand2'\n");
}


/*.....................command line validations..................*/

/*...........Operands validation...........*/

int digit(char str[])
{
    int i=0,c=0;
 
    while(str[i] != '\0') //checks given aruments all are integer or not
    {
        if(str[i] == '-' || str[i] == '+' && c<1) //allows one sign '-15' and fails '--15'
        {
            c++;
            i++;
            continue;
        }
        else if(!isdigit(str[i++])) //if any non integral value found it will execute
          return invalid;
    }

    //in loop invalid input not found then,
    return valid;
}

/*..........................Operator validation........................*/

int operatorr(char *str)
{
    char *arr[]={"+", "-", "x", "/", NULL}; //valid operators

    int i=0;
    //checking operator matchine or not
    while(arr[i] != NULL)
    {
        if(!strcmp(arr[i++],str)) //valid operator match then,
          return valid;
    }

    //operator not matched in loop then,
    return invalid;
}
