#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push()
{
    struct Node *temp;
    int val;
    printf("\nEnter a value:");
    scanf("%d", &val);
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp)
    {
        temp->data = val;
        if (top == NULL)
            temp->next = NULL;
        else
            temp->next = top;
        top = temp;
        printf("\nOne value inserted into the STACK\n");
    }
    else
    {
        printf("\nSTACK overflow");
    }
    
}
int pop()
{
    if (top == NULL)
        printf("\nSTACK underflow\n");
    else
    {
        struct Node *temp = top;
        printf("\nDeleted element :%d", temp->data);
        top = temp->next;
        free(temp);
    }
}
void display()
{
    if (top == NULL)
    {
        printf("\nSTACK is empty\n");
    }
    else
    {
        struct Node *temp = top;
        printf("\n");
        while (temp->next != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d-->NULL\n", temp->data);
    }
}
void main()
{
    int ch, e = 1;

    while (e)
    {
        printf("\nSTACK OPERATIONS");
        printf("\n____________________MENU______________________\n");
        printf("\n\t 1. push\n\t 2. pop\n\t 3. Display\n\t 4. Exit\n");
        printf("\n__________________________________________________\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            e = 0;
            printf("\nExiting from the programe");
            break;
        default:
            printf("\n please enter valid choice");
        }
    }
}
