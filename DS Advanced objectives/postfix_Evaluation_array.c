#include <stdio.h>
#include <string.h>
#include<ctype.h>

void push(int arr[],int op,int *top)
{
    *top+=1;
    arr[*top]=op;

}
int pop(int arr[],int *top)
{
    int value;
    value=arr[*top];
    *top-=1;
    return value;
}

// void display(int arr[],int *top)
// {
//     for(int i=0;i<=*top;i++)
//     {
//         printf("\t%d",arr[i]);
//     }
// }


int main()
{
    int top=-1;
    int arr[30];
    int len,i,value1=0,value2=0,result=0;
    char exp[50];
    printf("Enter a postfix expression:\n");
    scanf("%s",exp);
    len=strlen(exp);
     printf("%d\n",len);
    for(i=0;i<len;i++)
    {
        if(isdigit(exp[i])!=0)
        {
            exp[i]=exp[i]-'0';
            push(arr,exp[i],&top);
        }
        else
        {
            // display(arr,&top);
            value1=pop(arr, &top);
            value2=pop(arr, &top);
            switch (exp[i])
            {
            case '+':
                result = value1 + value2;
                push(arr, result, &top);
                break;
            case '-':
                result = value2 - value1;
                push(arr, result, &top);
                break;
            case '*':
                result = value1 * value2;
                push(arr, result, &top);
                break;
            case '/':
                result = value2 / value1;
                push(arr, result, &top);
                break;
            default :printf("Invalid expression!!!");
            break;
            }
        }
        
    }
    printf("The solution is:%d\n",result);
    return 0;
}
