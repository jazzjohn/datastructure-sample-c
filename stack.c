#include<stdio.h>
void push(int a[],int *last)
{
    *last=*last+1;
    printf("\nEnter a number:");
    scanf("%d",&a[*last]);
    printf("value pushed into the stack");

}
int pop(int a[],int *last)
{
    int ele;
    ele=a[*last];
    *last=*last-1;
    printf("\nThe value %d is poped from  the stack",ele);
}
void display(int a[],int *last){
    int i;
    printf("\n the stak elements are:");
    for(i=0;i<= *last;i++)
        printf("%d ",a[i]);
}
int main()
{
    int arr[10],ch,e=1;
    int last=-1;

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
            case 1: push(arr, &last);
                    break;
            case 2:pop(arr,&last);
                    break;
            case 3:display(arr,&last);
            break;
            case 4:e=0;
                printf("\nExiting from the programe");
                break;
            default:printf("\n please enter valid choice");
        }
    }
    return 0;

}