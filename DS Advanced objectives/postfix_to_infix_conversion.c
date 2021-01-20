#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct node
{
    char data[50];
    struct node *next;
} *top = NULL;

void push(char *data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->data, data);
    if (top == NULL)
        temp->next = NULL;
    else
        temp->next = top;
    top = temp;
}
char *pop()
{
    if (top == NULL)
    {
        return "f";
    }
    else
    {
        struct node *temp = top;
        char *val = (char *)malloc(50 * sizeof(char));
        strcpy(val, temp->data);
        top = temp->next;
        free(temp);
        return val;
    }
}
// void display()
// {
//     struct node *temp = top;
//     while (temp->next != NULL)
//     {
//         printf("%s-->", temp->data);
//         temp = temp->next;
//     }
//     printf("%s-->NULL\n", temp->data);
// }
int main()
{
    int len;
    int j = 0;
    char exp[50];
    // char *ope=(char *)malloc(50*sizeof(char));
    char *value1=(char *)malloc(50*sizeof(char));
    char *value2=(char *)malloc(50*sizeof(char));
    // char *result=(char *)malloc(50*sizeof(char));
    printf("\nEnter a postfix expression:");
    fgets(exp, 50, stdin);
    len = strlen(exp);
    char *op=exp;
    while (j < len - 1)
    {
        if (isdigit(exp[j]) != 0)
        {
            char temp=exp[j];
            push(&temp);
        }
        else
        {
            // display();
            strcpy(value1, pop());
            strcpy(value2, pop());
            if (strcmp(value1, "f")==0 || strcmp(value2, "f")==0)
            {
                printf("\nInvalid postfix expression!!\n");
                break;
            }
            else
            {
                char temp=*op;
                strcat(value1, &temp);
                strcat(value1, value2);
                push(value1);
            }
        }
        *op++;
        j += 1;
    }
    printf("\ncurresponding infix expression is:%s \n\n", value1);
    free(value1);
    free(value2);
    return 0;
}
