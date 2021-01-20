#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node * push(node *top)
{
    int val;
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter the value:");
    scanf("%d\n", &val);
    temp->data = val;
    if (top == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = top;
    }
    top = temp;
    printf("one value inserted into the stack\n");
    return top;
}
node * pop(node *top)
{
    if (top == NULL)
    {
        printf("\nSTACK underflow");
    }
    else
    {
        node *temp = top;
        printf("%d is deleted from the stack:\n", temp->data);
        top = temp->next;
        free(temp);
    }
    return top;
}
void display(node *top)
{
    if (top == NULL)
    {
        printf("STACK is empty\n");
    }
    else
    {
        node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d-->NULL", temp->data);
    }
}

int main()
{
    node *top = NULL;
    int e = 1;
    int ch;
    printf("\nSTACK USING LINKED LIST\n");
    while (e)
    {
        printf("\n__________________MENU_____________________\n");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d\n", &ch);
        switch (ch)
        {
        case 1:
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            e = 1;
            break;
        default:
            printf("Enter valid input!!!");
            break;
        }
    }
}