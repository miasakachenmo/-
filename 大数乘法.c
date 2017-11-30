#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *numbera,*numberb,flag=0;
    unsigned short int *numa,*numb,*numc;
    unsigned char i,j,lena,lenb,lenc;
    numbera=(char*)malloc(sizeof(char)*200);
    numberb=(char*)malloc(sizeof(char)*200);
    gets(numbera);
    gets(numberb);
    lena=strlen(numbera);
    lenb=strlen(numberb);
    lenc=lena+lenb;
    numa=(unsigned short int*)malloc(sizeof(unsigned short int)*lena);
    for(i=0;i<lena;i++)
        numa[i]=numbera[i]-'0';
    numb=(unsigned short int*)malloc(sizeof(unsigned short int)*lenb);
    for(i=0;i<lenb;i++)
        numb[i]=numberb[i]-'0';
    numc=(unsigned short int*)malloc(sizeof(unsigned short int)*(lenc+1));
    for(i=0;i<lenc;i++)
        *(numc+i)=0;
    for(i=0;i<lenb;i++)
    {
        for(j=0;j<lena;j++)
        {
            numc[lenc-1-i-j]+=(numb[lenb-i-1])*(numa[lena-j-1]);
        }
    }
    for(i=0;i<lenc;i++)
    {
        while(numc[lenc-i-1]>=10000)
        {
            numc[lenc-i-5]++;
            numc[lenc-i-1]-=10000;
        }
        while(numc[lenc-i-1]>=1000)
        {
            numc[lenc-i-4]++;
            numc[lenc-i-1]-=1000;
        }
        while(numc[lenc-i-1]>=100)
        {
            numc[lenc-i-3]++;
            numc[lenc-i-1]-=100;
        }
        while(numc[lenc-i-1]>=10)
        {
            numc[lenc-i-2]++;
            numc[lenc-i-1]-=10;
        }
    }
    for(i=0;i<lenc;i++)
    {
        if(numc[i]!=0)
        {
            flag=1;
            printf("%d",numc[i]);
            i++;
            break;
        }
    }
    for(;i<lenc;i++)
    {
        printf("%d",numc[i]);
    }
    if(flag==0)
        printf("0");
}
