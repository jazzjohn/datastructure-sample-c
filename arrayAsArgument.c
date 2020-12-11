#include<stdio.h>
void read(int a[],int *num)
{
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
    int arr[10],num,sum;
    printf("\nEnter number of numbers:");
    scanf("%d",&num);

    read(arr,&num);

    sum=add(arr,&num);
    printf("\nthe sum of array elements is:%d \n",sum);
    return 0;

}