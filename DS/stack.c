#include<stdio.h>
#define SIZE 10

void push(int a[],int *top)
{
    *top=*top+1;
    printf("\nEnter a number:");
    scanf("%d",&a[*top]);
    printf("\n%d is pushed to the stack",a[*top]);

}
int pop(int a[],int *top)
{
    printf("\n%d is poped from the stack",a[*top]);
    *top-=1;
}
void display(int a[],int *top){
    printf("\n the stak elements are:");
    for(int i=*top;i>= 0;i--)
        printf("%d ",a[i]);
}
int main()
{
    int arr[SIZE],ch,e=1;
    int top=-1;

    while(e)
    {
        printf("\nSTACK OPERATIONS");
        printf("\n____________________MENU______________________\n");
        printf("\n\t 1. push\n\t 2. pop\n\t 3. Display\n\t 4. Exit\n");
        printf("\n__________________________________________________\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(top>=SIZE-1)
                    {
                        printf("\nSTACK overflow\n");
                        break;
                    }
                    push(arr, &top);
                    break;
            case 2:if(top<0)
                    {
                        printf("\nSTACK underflow\n");
                        break;
                    }
                    pop(arr,&top);
                    break;
            case 3:display(arr,&top);
            break;
            case 4:e=0;
                printf("\nExiting from the programe");
                break;
            default:printf("\n please enter valid choice");
        }
    }
    return 0;

}