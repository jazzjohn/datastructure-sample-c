#include <stdio.h>

int main()
{
    int a[10];
    int sum=0;
    int i,num;

    printf("Enter number of number:");
    scanf("%d",&num);

    printf("\nEnter %d numbers:",num);

    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<num;i++)
    {
        sum+=a[i]; 
    }

    printf("\nThe sum of given %d numbers is %d:",num,sum);

    return 0;

}