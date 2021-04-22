#include <stdio.h>

void insert(int a[], int *front, int *rear)
{
    int e;
    printf("\nEnter number:");
    scanf("%d", &e);
    if ((*front == -1) && (*rear == -1))
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        *rear += 1;
    }
    a[*rear] = e;
    printf("\nThe entered element %d is inserted in to the QUEUE\n", e);
}

void delete (int a[], int *front, int *rear)
{
    if(*front>*rear)
    {
        printf("\nQUEUE underflow\n");
    }
    else
    {    
    int e;
    e = a[*front];
    printf("\nThe element %d deleted from QUEUE", e);
    *front += 1;
    }

}

void display(int a[], int *front, int *rear)
{
    if (((*front == -1) && (*rear == -1)) || *front>*rear)
    {
        printf("Queue is empty");
    }
    else
    {
    int i;
    printf("\nthe QUEUE elements are:");
    for (i = *front; i <= *rear; i++)
        printf("\t%d", a[i]);
    }
}

int main()
{
    int arr[10], front=-1, rear=-1, ch, e = 1;
    while (e)
    {
        printf("\nQUEUE OPERATIONS");
        printf("\n____________________MENU______________________\n");
        printf("\n\t 1. insert\n\t 2. delete\n\t 3. Display\n\t 4. Exit\n");
        printf("\n__________________________________________________\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(arr, &front, &rear);
            break;
        case 2:
            delete (arr, &front, &rear);
            break;
        case 3:
            display(arr, &front, &rear);
            break;
        case 4:
            e = 0;
            printf("\nExiting from the programe");
            break;
        default:
            printf("\n please enter valid choice");
        }
    }
    return 0;
}
