#include<stdio.h>
void push(int a[],int *top)
{
    *top=*top+1;
    printf("\nEnter a number:");
    scanf("%d",&a[*top]);
    printf("value pushed into the stack");

}
int pop(int a[],int *top)
{
    int ele;
    ele=a[*top];
    *top=*top-1;
    printf("\nThe value %d is poped from  the stack",ele);
}
void display(int a[],int *top){
    int i;
    printf("\n the stak elements are:");
    for(i=*top;i>= 0;i--)
        printf("%d ",a[i]);
}
int main()
{
    int arr[10],ch,e=1;
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
            case 1: if(top==9)
                    {
                        printf("\nStack is full");
                        break;
                    }
                    push(arr, &top);
                    break;
            case 2:if(top<0)
                    {
                        printf("\nstack is empty");
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