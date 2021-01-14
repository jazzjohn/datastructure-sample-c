#include<stdio.h>
void read(int a[],int *num)
{
    printf("\nEnter number of numbers:");
    scanf("%d",num);
    printf("\n Enter array elements:");
    for(int i=0;i< *num;i++){
        scanf("%d",&a[i]);
    }
}
int add(int a[],int *num)
{
    int sum=0;
    int i;

    for(i=0;i < *num;i++)
    {
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int arr[10],sum,ch,e=1,num;

    while(e)
    {
        printf("\n____________________MENU______________________\n");
        printf("\n\t1. Read\n\t2. Sum\n\t3. Exit\n");
        printf("\n__________________________________________________\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: read(arr, &num);
                    break;
            case 2:sum=add(arr,&num);
                    printf("\nthe sum of array elements is:%d \n",sum);
                    break;
            case 3:e=0;
                printf("\nExiting from the programe");
                break;
            default:printf("\n please enter valid choice");
        }
    }





    return 0;

}