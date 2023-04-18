#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int n=6;
float R=95,c=0.618;
int main()
{
    int i=0;
    float r[n],t[n];
    float a,b,a0=0,b0=5,s=0,x1=0,x2=0,fx=0,fx1=0,fx2=0,fk=0,k=0;
    float obj(float k,float r[],float t[]);
    printf("请依次输入累计浮选时间和累计回收率\n");
    for(i=0;i<n;i++)
    {
    scanf("%f %f",&t[i],&r[i]);
    }
    x2=a0+c*(b0-a0);
    x1=b0-c*(b0-a0);
    fx1=obj(x1,r,t);
    fx2=obj(x2,r,t);
    a=a0,b=b0;
while(fabs((x1-x2)/(b0-a0))> 0.01)
{
    if(fx2<fx1)
    {
        a=x1;
        x1=x2;
        fx1=fx2;
        x2=a+c*(b-a);
        fx=obj(x2,r,t);
        fx2=fx;
    }
    else
    {
        b=x2;
        x2=x1;
        fx2=fx1;
        x1=b-c*(b-a);
        fx=obj(x1,r,t);
        fx1=fx;
    }
    k=(a+b)/2;
    fk=obj(k,r,t);
}
    s=sqrt(fk/(n-2));
    printf(" ***********************************\n");
    printf("浮选速率常数:   %f\n",k);
    printf("偏差平方和:     %f \n",fk);
    printf("剩余标准差:     %f \n",s);
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
float obj(float k,float r[],float t[])
    {
    float f=0;
    int i=0;
        for(i=0;i<n;i++)
    
        {
            float temp;
            temp=(float)((r[i]-R*(1-exp(-k*t[i])))*(r[i]-R*(1-exp(-k*t[i]))));
            f=f+temp;
        }
        return f;
    }
