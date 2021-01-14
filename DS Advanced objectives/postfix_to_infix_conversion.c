#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdlib.h>

struct node
{
    char data[50];
    struct node *next;
}*top=NULL;

void push(char data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->data,&data);
    if(top==NULL)
        temp->next=NULL;
    else
        temp->next=top;
    top=temp;
}
char* pop()
{
    printf("pop\n");
    if(top==NULL)
    {
        return "false";
    }
    else
    {
        printf("else\n");
        struct node *temp = top;
        char *val;
        strcpy(val,temp->data);
        top = temp->next;
        free(temp);
        printf("%s",val);
        return val;
    }
}
void display()
{
    struct node *temp=top;
    while(temp->next!=NULL)
    {
        printf("%s-->",temp->data);
        temp=temp->next;
    }
    printf("%s-->NULL\n",temp->data);
}
int main()
{
    int len;
    int j=0;
    char exp[50],*value1,*value2,*result;
    printf("\nEnter a postfix expression:");
    fgets(exp,50,stdin);
    printf("%s\n",exp);
    len=strlen(exp);
    printf("%d\n",len);
    while (j<len-1)
    {
        printf("%c\n",exp[j]);
        if(isdigit(exp[j])!=0)
        {
            push(exp[j]);
        }
        else
        {
            printf("else block\n");
            display();
            strcpy(value1,pop());
            printf("%s\n",value1);
            strcpy(value2,pop());
            printf("%s\n",value2);
            if(strcmp(value1,"false") || strcmp(value2,"false"))
            {
                printf("\nInvalid postfix expression!!\n");
                break;
            }
            else
            {
                printf("strcat else block\n");
                printf("1.%s\n",value1);
                printf("2.%d\n",exp[j]);
                strcat(value1,&exp[j]);
                printf("3.%s\n",value1);
                printf("4.%s\n",value2);
                strcat(value1,value2);
                printf("%s\n",value1);
                push(value1[50]);
            }
            
        }
        j+=1;
    }
    printf("\ncurresponding infix expression is:%s ",value1);
    return 0;
}
