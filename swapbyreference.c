#include <stdio.h>

void swap(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;

    printf("\nThu number after swap is %d & %d",*a,*b);
}


int main()
{
    int a,b;
    int sum=0;

    printf("\nEnter two numbers:");
    scanf("%d%d",&a,&b);

    swap(&a,&b);

    sum=a+b;
    printf("\nThe sum of %d & %d is %d",a,b,sum);
    
    return 0;
}