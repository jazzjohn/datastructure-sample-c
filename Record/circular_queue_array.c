#include <stdio.h>
#define SIZE 5

void enqueue(int a[], int *front, int *rear)
{
    int e;
    printf("\nEnter number:");
    scanf("%d", &e);
    if ((*rear + 1) % SIZE == *front)
    {
        printf("\nQUEUE overflow");
        return;
    }
    else if (*front > 0 && *rear == SIZE - 1)
    {
        *rear = 0;
    }
    else if ((*front == -1) && (*rear == -1))
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        printf("then");
        *rear += 1;
    }
    a[*rear] = e;
    printf("\nThe entered element %d is inserted in to the QUEUE\n", e);
}

void dequeue(int a[], int *front, int *rear)
{
    if (*front == -1)
    {
        printf("\nQUEUE underflow\n");
    }
    else if (*front == SIZE - 1)
    {
        *front = 0;
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
    if (((*front == -1) && (*rear == -1)))
    {
        printf("Queue is empty");
    }
    else
    {
        int i;
        printf("\nthe QUEUE elements are:");
        if(*front>*rear)
        {
            for (i = *front; i<=(*rear+SIZE) ; i++)
                printf("\t%d", a[i%SIZE]);
        }
        else{
            for (i = *front; i<=(*rear) ; i++)
                printf("\t%d", a[i]);
        }

    }
}

void search(int a[], int *front, int *rear,int ele)
{
    if (((*front == -1) && (*rear == -1)))
    {
        printf("Queue is empty");
    }
    else
    {
        if(*front>*rear)
        {
        for (int i=*front;i<=(*rear+SIZE);i++)
        {
            if(a[i%SIZE]==ele)
            {
                printf("Item found!!!");
                return;
            }

        }
        printf("Item not found!!!");
        }
        else
        {
            for (int i=*front;i<=(*rear);i++)
        {
            if(a[i]==ele)
            {
                printf("Item found!!!");
                return;
            }

        }
        printf("Item not found!!!");
        }
        
    }
}

    int main()
{
    int arr[SIZE], front = -1, rear = -1, ch, e = 1, val;
    while (e)
    {
        printf("\nCIRCULAR QUEUE OPERATIONS");
        printf("\n____________________MENU______________________\n");
        printf("\n\t 1. insert\n\t 2. delete\n\t 3. Display\n\t 4. Search\n\t 5. Exit\n");
        printf("\n__________________________________________________\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(arr, &front, &rear);
            break;
        case 2:
            dequeue(arr, &front, &rear);
            break;
        case 3:
            display(arr, &front, &rear);
            break;
        case 4:
            printf("\nEnter the data to be searched:");
            scanf("%d", &val);
            search(arr, &front, &rear, val);
            break;
        case 5:
            e = 0;
            printf("\nExiting from the programe");
            break;
        default:
            printf("\n please enter valid choice");
        }
    }
    return 0;
}
