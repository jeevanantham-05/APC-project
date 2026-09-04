#include<stdio.h>
#include"header.h"


int main(int count, char *str[]) ///.a.out 1234 + 123
{

    if(count>3)
    {
        printf("arugments valid\n");
        if(digit(str[1])==valid)//checking operand 1 digit or not
        {
            printf("arug 1 valid\n");
            if(operator(str[2])==valid)//checking input valid operator or not
            {
                printf("operator valid\n");
                if(digit(str[3])==valid)//checking operand 2 digit or not
                {
                    printf("arug 2 valid\n");
                    if(linklist(str)==success)
                    {
                        printf("list creted success\n");
                        printfunc();
                    }
                    else printf("ERROR: list not created");

                }
                else printf("ERROR: arug3 should be integer only\n");
            }
            else printf("ERROR: Invalid operator\n");

        }
        else printf("ERROR: arug1 should be integer only\n");
    }
    else printf("ERROR: Aruguments should be more than 3\n");
}

