#include<stdio.h>

struct Node
{
    int data1;
    int data2;
}n1;

typedef struct Node node;
int main()
{
    // struct Node n1;
    node n2,sum;

    printf("Enter first data1:");
    scanf("%d",&n1.data1);

    printf("\nEnter first data2:");
    scanf("%d",&n1.data2);


    printf("The value are:\nData 1=%d\nData 2=%d\n",n1.data1,n1.data2);

     printf("Enter second data1 :");
    scanf("%d",&n2.data1);

    printf("\nEnter second data2:");
    scanf("%d",&n2.data2);

    printf("The value are:\nData 1=%d\nData 2=%d\n",n2.data1,n2.data2);

    sum.data1=n1.data1+n2.data1;
    sum.data2=n1.data2+n2.data2;
    printf("\nSum of values of struct is :%d & %d\n",sum.data1,sum.data2);

    return 0;
}
