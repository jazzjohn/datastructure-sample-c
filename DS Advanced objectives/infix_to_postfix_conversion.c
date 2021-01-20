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
    printf("%s\n", temp->data);
    if (top == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = top;
    }
    top = temp;
    printf("one value added\n");
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
        printf("%s\n", val);
        top = temp->next;
        free(temp);
        printf("one value deleted\n");
        return val;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        stack *temp = top;
        while (temp->next != NULL)
        {
            printf("%s-->", temp->data);
            temp = temp->next;
        }
        printf("%s-->NULL\n", temp->data);
    }
}

void insertToPostfix(char ele)
{
    printf("%c\n", ele);
    char *val = &ele;
    strcat(postfix, val);
    printf("%s\n", postfix);
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
    printf("%c\n", op);
    char *operator= & op;
    printf("my%s\n", operator);
    char brace[2] = ")";
    char *cbrace = brace;
    printf("hoi%s\n", cbrace);
    int res = strcmp(operator, cbrace);
    printf("hoi%d\n", res);
    if (strcmp(operator, cbrace) == 0)
    {
        printf("first strcmpif\n");
        char *val = (char *)malloc(50 * sizeof(char));
        strcpy(val, pop());
        display();
        printf("%s\n", val);
        while (strcmp(val, "(") != 0)
        {
            printf("whilestrcmp\n");
            insertToPostfix(*val);
            strcpy(val, pop());
            display();
            printf("%s\n", val);
        }
    }
    else
    {
        printf("elseofcheck\n");
        display();
        stack *temp = top;
        char *val = (char *)malloc(50 * sizeof(char));
        printf("my%s\n", temp->data);
        int pre2 = precedence(temp->data);
        printf("%d\n", pre2);
        int pre1 = precedence(&op);
        printf("%d\n", pre1);
        while (pre2 >= pre1)
        {
            // char obrace[2]="";
            strcpy(val, pop());
            display();
            // char tempVal=*val;
            printf("%s\n", val);
            // strcpy(obrace,val);
            // printf("%s",obrace);
            if (strcmp(val, "(") == 0)
            {
                printf("strcmpif\n");
                push(*val);
                display();
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

    // }
}
int main()
{
    int len, i = 0, pre[20], j;
    char infix[50], cbrace[2] = ")";
    char brace[5] = "(";
    char *stack = (char *)malloc(50 * sizeof(char));
    printf("Enter an infix expression:");
    // fgets(infix, 50, stdin);
    scanf("%s", infix);
    len = strlen(infix);
    printf("%d\n", len);
    strcat(infix, cbrace);
    printf("%s\n", infix);
    char *exp = infix;
    push(*brace);
    printf("%s\n", exp);
    while (i < len + 1)
    {
        printf("%d----------\n", i + 1);
        display();
        printf("%c\n", infix[i]);
        if (isdigit(infix[i]) != 0)
        {
            printf("if_is_digit\n");
            insertToPostfix(*exp);
        }
        else
        {
            printf("else\n");
            switch (infix[i])
            {
            case '(':
                printf("(\n");
                push(*exp);
                break;
            case ')':
                printf(")\n");
                checkOperator(*exp);
                display();
                break;
            case '+':
                printf("+\n");
                checkOperator(*exp);
                push(*exp);
                display();
                printf("+end\n");
                break;
            case '-':
                printf("-\n");
                checkOperator(*exp);
                push(*exp);
                display();
                printf("-end\n");
                break;
            case '*':
                printf("*\n");
                checkOperator(*exp);
                push(*exp);
                display();
                printf("*end\n");
                break;
            case '/':
                printf("/\n");
                checkOperator(*exp);
                push(*exp);
                display();
                printf("/end\n");
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