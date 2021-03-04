#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head;

void display()
{
    printf("display function\n");
    if (head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        node *temp = head;
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
    int ch, e = 1, op;
    while (e)
    {
        printf("\n DOUBLY LINKED LIST");
        printf("\n______________MENU______________");
        printf("\n 1.INSERT FIRST \n2.INSERT END \n 3.INSERT IN PERTICULAR POSITION\n 4.DELETE HEAD\n5.DELETE END");
        printf("\n 6.DELETE AT PERTICULAR POSITION\n 7.DISPLAY \n 8.SORT\n 9.EXIT");
        printf("\n_________________________________\n");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n__________Insertion option__________\n");
            printf("\n1.Front\n2.Last\n3.In between\n");
            printf("_________________________________\n");
            printf("\nchose your option:");
            scanf("%d", &op);
            insert(&op);
            break;
        case 2:
            printf("\n__________Deletion option__________\n");
            printf("\n1.Front\n2.Last\n3.In between\n");
            printf("_________________________________\n");
            printf("\nchose your option:");
            scanf("%d", &op);
            delete (&op);
            break;
        case 3:
            display();
            break;
        case 4:
            e = 0;
            printf("\n exiting........");
            break;
        default:
            printf("\n please enter valid choice\n");
            break;
        }
    }
    printf("\n\n\n\t\t\t----------successfully exited----------\n\n");
    return 0;
}