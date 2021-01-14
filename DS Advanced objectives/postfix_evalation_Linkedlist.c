#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
}*top=NULL;

void push(char data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    if(top==NULL)
        temp->next=NULL;
    else
        temp->next=top;
    top=temp;
}
char pop()
{
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        int val;
        struct node *temp = top;
        val = temp->data;
        top = temp->next;
        free(temp);
        return val;
    }
}
void display()
{
    struct node *temp=top;
    while(temp->next!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("%d-->NULL",temp->data);
}
int main()
{
    int ch,value1,value2,result,len;
    int j=0;
    int e=0;
    char exp[50];
    printf("\nEnter a postfix expression:");
    fgets(exp,50,stdin);
    len=strlen(exp);
    while (j<len-1)
    {
        if(isdigit(exp[j])!=0)
        {
            exp[j]=exp[j]-'0';
            push(exp[j]);
        }
        else
        {
            // display();
            value1=pop();
            value2=pop();
            if(value1==-1 || value2==-1)
            {
                printf("\nInvalid postfix expression!!\n");
                break;
            }
            switch (exp[j])
            {
                case '+':result=value1+value2;
                push(result);
                break;
                case '-':result=value2-value1;
                push(result);
                break;
                case '*':result=value1*value2;
                push(result);
                break;
                case '/':result=value2/value1;
                push(result);
                break;
                default:printf("\nInvalid postfix expression!!!\n");
            }
        }
        j+=1;
    }
    printf("\nSolution is:%d ",result);
    return 0;
}
