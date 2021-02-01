#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int arr2[], int marr[], int *s1, int *s2)
{
    int i=0, j=0, k = 0, num;
    while (k < *s1 + *s2)
    {
        if (j < *s2 && i < *s1)
        {
            if (arr1[i] <= arr2[j])
            {
                marr[k] = arr1[i];
                k++;
                i++;
            }
            else
            {
                marr[k] = arr2[j];
                k++;
                j++;
            }
        }
        else
        {
            if (j >= *s2 && i < *s1)
            {
                marr[k] = arr1[i];
                i++;
                k++;
            }
            else if (i >= *s1 && j < *s2)
            {
                marr[k] = arr2[j];
                j++;
                k++;
            }
        }
    }
}

int main()
{
    int arr1[50], arr2[50], marr[100], s1, s2, i, j,k=0, size;
    printf("\nEnter the size of the first array:");
    scanf("%d", &s1);
    printf("\nEnter the values in sorted order:");
    for (i = 0; i < s1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter the size of the second array:");
    scanf("%d", &s2);
    printf("\nEnter the values in sorted order:");
    for (i = 0; i < s2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    merge(arr1, arr2, marr, &s1, &s2);
    printf("\nThe merged sorted elements are:");
    for(i=0;i<s1+s2;i++)
    {
        printf("%d ",marr[i]);
    }
    printf("\n\n");
    return 0;
}