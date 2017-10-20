#include<stdio.h>
int flag=0,flag1=0;
int main()
{
    float lenth=0,i=2,requirelenth=0;
    while(flag1==0)
    {
        scanf("%f",&requirelenth);
        if(requirelenth==0)
            break;
        flag=0;
        i=2;
        lenth=0;
        while(flag==0)
        {
            lenth+=1/i;
            if(requirelenth<=lenth)
            {
                printf("%.0f card(s)\n",i-1);
                flag=1;
            }
            i++;
        }
    }
}
