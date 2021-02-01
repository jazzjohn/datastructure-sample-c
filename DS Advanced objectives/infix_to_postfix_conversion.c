#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char postfix[50];
struct Stack
{
    char data[20];
    struct Stack *next;
} *top = NULL;

typedef struct Stack stack;

void push(char data)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    strcpy(temp->data, &data);
    if (top == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = top;
    }
    top = temp;
}

char *pop()
{
    if (top == NULL)
    {
        printf("stack underflow!!!\n");
        return "f";
    }
    else
    {
        stack *temp = top;
        char *val = (char *)malloc(sizeof(char));
        strcpy(val, temp->data);
        top = temp->next;
        free(temp);
        return val;
    }
}

// void display()
// {
//     if (top == NULL)
//     {
//         printf("stack is empty\n");
//     }
//     else
//     {
//         stack *temp = top;
//         while (temp->next != NULL)
//         {
//             printf("%s-->", temp->data);
//             temp = temp->next;
//         }
//         printf("%s-->NULL\n", temp->data);
//     }
// }

void insertToPostfix(char ele)
{
    char *val = &ele;
    strcat(postfix, val);
}

int precedence(char *pre)
{
    int val;
    switch (*pre)
    {
    case '(':
        val = 3;
        break;
    case ')':
        val = 3;
        break;
    case '*':
        val = 2;
        break;
    case '/':
        val = 2;
        break;
    case '+':
        val = 1;
        break;
    case '-':
        val = 1;
        break;
    default:
        break;
    }
    return val;
}
void *checkOperator(char op)
{
    char *operator= & op;
    char brace[2] = ")";
    char *cbrace = brace;
    int res = strcmp(operator, cbrace);
    if (strcmp(operator, cbrace) == 0)
    {
        char *val = (char *)malloc(50 * sizeof(char));
        strcpy(val, pop());
        while (strcmp(val, "(") != 0)
        {
            printf("whilestrcmp\n");
            insertToPostfix(*val);
            strcpy(val, pop());
        }
    }
    else
    {
        stack *temp = top;
        char *val = (char *)malloc(50 * sizeof(char));
        int pre2 = precedence(temp->data);
        int pre1 = precedence(&op);
        while (pre2 >= pre1)
        {
            strcpy(val, pop());
            if (strcmp(val, "(") == 0)
            {
                printf("strcmpif\n");
                push(*val);
                break;
            }
            else
            {
                insertToPostfix(*val);
                temp = temp->next;
                pre2 = precedence(temp->data);
            }
        }
    }
}
int main()
{
    int len, i = 0, pre[20], j;
    char infix[50], cbrace[2] = ")";
    char brace[5] = "(";
    char *stack = (char *)malloc(50 * sizeof(char));
    printf("Enter an infix expression:");
    scanf("%s", infix);
    len = strlen(infix);
    strcat(infix, cbrace);
    char *exp = infix;
    push(*brace);
    while (i < len + 1)
    {
        // display();
        if (isdigit(infix[i]) != 0)
        {
            printf("if_is_digit\n");
            insertToPostfix(*exp);
        }
        else
        {
            switch (infix[i])
            {
            case '(':
                printf("(\n");
                push(*exp);
                break;
            case ')':
                printf(")\n");
                checkOperator(*exp);
                break;
            case '+':
                checkOperator(*exp);
                push(*exp);
                break;
            case '-':
                checkOperator(*exp);
                push(*exp);
                break;
            case '*':
                checkOperator(*exp);
                push(*exp);
                break;
            case '/':
                checkOperator(*exp);
                push(*exp);
                break;
            default:
                printf("Invalid expression!");
                break;
            }
        }
        i++;
        *exp++;
    }
    printf("The curresponding postfix expression is:%s\n", postfix);
}