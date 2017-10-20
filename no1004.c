#include<stdio.h>
int main()
{
    float total=0,mouth=0;
    int i=0;
    for(i=1;i<=12;i++)
    {
        scanf("%f",&mouth);
        total+=mouth;
    }
    printf("$%.2f",total/12);
}
