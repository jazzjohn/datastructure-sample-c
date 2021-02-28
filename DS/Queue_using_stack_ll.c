#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top1 = NULL, *top2 = NULL;

void insert()
{
    if(top2)
    {
        while(top2->next!=NULL)
        {
            if(top2==NULL)
                top1=top2;
            else
            {
                top2->next=top1;
                top1=top2;
            }
        }
        top2==NULL;
    }
    struct node *temp;
    int val;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n Queue Overflow\n");
        return;
    }
    else
    {
        printf("\n Enter the value:");
        scanf("%d", &val);
        temp->data = val;
        if (top1 == NULL)
            temp->next = NULL;
        else
        {
            temp->next = top1;
        }
        top1 = temp;
        printf("\n One value is inserted into the queue\n");
    }
}
void delete ()
{
    struct node *temp;
    if (top1 == NULL)
    {
        printf("\n Underflow\n");
        return;
    }
    else
    {
        while(top1->next!=NULL)
        {
            if(top2==NULL)
                top2=top1;
            else
            {
                top1->next=top2;
                top2=top1;
            }
        }
        top1==NULL;
    }
}
void display()
{
    struct node *temp;
    temp = top1;
    if (top1 == NULL)
    {
        printf("\n Empty Queue\n");
        return;
    }
    else
    {
        printf("\n Queue elements are\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int ch, e = 1;

    while (e)
    {
        printf("\n QUEUE USING STACK");
        printf("\n...........MENU...........");
        printf("\n 1.INSERT \n 2.DELETE \n 3.DISPLAY \n 4.EXIT");
        printf("\n..........................");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            e = 0;
            printf("\n exiting...");
            break;
        default:
            printf("\n please enter valid choice\n");
            break;
        }
    }

    return 0;
}