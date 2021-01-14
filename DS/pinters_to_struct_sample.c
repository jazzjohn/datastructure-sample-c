#include<stdio.h>

struct person
{
    int age ;
    float weight;
};


typedef struct person person;
int main()
{
    person *personptr,person;
    personptr=&person;

    printf("Enter age:");
    scanf("%d",&personptr->age);

    printf("Enter weight:");
    scanf("%f",&personptr->weight);

    printf("Displaying:\n");
    printf("Age:%d\n",personptr->age);
    printf("Weight:%f\n",personptr->weight);

    return 0;
}

