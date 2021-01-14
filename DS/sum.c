#include <stdio.h>

int main()
{
    int a,b;
    int sum=0;

    printf("\nEnter two numbers:");
    scanf("%d%d",&a,&b);

    sum=a+b;
    printf("\nThe sum of %d & %d is %d",a,b,sum);
    
    return 0;
}