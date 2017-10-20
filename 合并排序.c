#include<stdio.h>
#include<stdlib.h>
int *mar(int *p1,int lenth1,int *p2,int lenth2)//实现合并排序 输入两个数组与两个数组长度,返回一个排好序的数组
{
    if(lenth1==0)
        return p2;
    if(lenth2==0)
        return p1;
    int i=0;
    int i1=0,i2=0;
    int *p=0;
    p=(int*)malloc(sizeof(int)*(lenth1+lenth2));
    while((i1<lenth1)&&(i2<lenth2))
    {
        p[i++]=((p1[i1]<=p2[i2])?p1[i1++]:p2[i2++]);
    }
    for(i=0;i<i1+i2;i++)
        printf("%d ",p[i]);
    printf("\n");
    while(i1<lenth1)
        p[i++]=p1[i1++];
    while(i2<lenth2)
        p[i++]=p2[i2++];
    return p;
}
int* divide(int* p,int lenth)        //拆分数组 lenth:数组长度 p:数组头指针
{
    int *p1,*p2,lenth1,lenth2,i=0,j=0;

    if(lenth==1)
        return p;
    if(lenth%2==0)
        lenth1=lenth2=lenth/2;
    else
    {
        lenth2=(lenth+1)/2;
        lenth1=lenth2;
        lenth2=lenth2-1;
    }
    p1=(int*)malloc(lenth1*sizeof(int));
    p2=(int*)malloc(lenth2*sizeof(int));
    while(i<lenth1)
    {
        p1[i++]=p[j++];
    }
    i=0;
    while(i<lenth2)
    {
        p2[i++]=p[j++];
    }
    if(lenth1==2&&lenth2==1)
    {
        if(p1[0]>p1[1])
        {
            p1[0]=p1[0]+p1[1];
            p1[1]=p1[0]-p1[1];
            p1[0]=p1[0]-p1[1];
        }
        return mar(p1,2,p2,1);
    }
    if(lenth1==1&&lenth2==1)
    {
        return mar(p1,lenth1,p2,lenth2);
    }
    p1=divide(p1,lenth1);
    p2=divide(p2,lenth2);
    return mar(p1,lenth1,p2,lenth2);
}
int main()
{
    int i=0;
    int *p=0;
    int lenth;
    printf("input the lenth of the numbers:\n");
    scanf("%d",&lenth);
    int a[lenth];
    printf("input the numbers one by one\n");
    for(i=0;i<lenth;i++)
        scanf("%d",&a[i]);
    p=divide(a,lenth);
    for(i=0;i<lenth;i++)
        printf("%d ",p[i]);
    return 0;
}
