#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void insert()
{
    struct node *temp;
    int val;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("\nList Overflow\n");
        return;
    }
    else
    {
        printf("\n Enter the value:");
        scanf("%d",&val);
        temp -> data = val;
        temp -> next = NULL;
        if(head == NULL)
            head = temp;
        else
        {
            tail -> next = temp;
        }
        tail = temp;
        printf("\n One value is inserted into the Linked list\n");
    }
}
void delete()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList Underflow\n");
        return;
    }
    else
    {
        temp = head;
        head = head -> next;
        printf("\n %d is deleted from the Linked list\n", temp -> data);
        free(temp);
        
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if(head == NULL)
    {
        printf("\n Empty List\n");
        return;
    }
    else
    {
        printf("\n List elements are:");
        while(temp != NULL)
        {
            printf("%d ->", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int ch, e=1;

    while(e)
    {
        printf("\n  LINKED LIST OPERATIONS");
	    printf("\n...........MENU...........");
	    printf("\n 1.INSERT \n 2.DELETE \n 3.DISPLAY \n 4.EXIT");
	    printf("\n..........................");
	    printf("\n Enter your choice:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    case 1:
			    insert();
			    break;
		    case 2:
			    delete();
			    break;
		    case 3:
			    display();
			    break;
		    case 4:
			    e=0;
			    printf("\n exiting...");
			    break;
		    default: printf("\n please enter valid choice\n");
                break;
	    }
    }
    
    return 0;
}