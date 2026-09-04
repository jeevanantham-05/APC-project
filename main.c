#include<stdio.h>
#include"header.h"


int main(int count, char *str[]) ///.a.out 1234 + 1234
{

    if(count==4)
    {
        if(digit(str[1])==valid) //checking operand 1 digit or not
        {
            if(operator(str[2])==valid) //checking input valid operator or not
            {
                if(digit(str[3])==valid) //checking operand 2 digit or not
                {
                    if(linklist(str)==success) // creating list for 2 operands and implementing arithmetic operations
                    {
                        printf("ALL operations done success\n");
                        
                    }
                    else printf("ERROR: list not created");

                }
                else printf("ERROR: Operand2 should be integer only\n");
            }
            else printf("ERROR: Invalid operator, valid are \" + - x / \"\n");

        }
        else printf("ERROR: Operand1 should be integer only\n");
    }
    else printf("ERROR: Aruguments should be 'operand1' operator 'operand2'\n");
}



/*.....................command line validations..................*/

/*...........Operands validation...........*/
int digit(char str[])
{
    int i=0;
 
    while(str[i] != '\0') //checks given aruments all are integer or not
    {
        if(!isdigit(str[i++])) //if any non integral value found it will execute
          return invalid;
    }

    //in loop invalid input not found then,
    return valid;
}

/*...........Operator validation............*/
int operator(char *str)
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
