#include<stdio.h>
#include"header.h"

/*command line validations.............*/

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

