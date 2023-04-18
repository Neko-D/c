#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n=10,i,model_n;
    double a,b,c,d,r,e=0,f=0,g=0,l=0,m=0,q=0,sm;
    printf("请输入数据组数\n");
    scanf("%d",&n);
    double p[n],u[n],v[n];
    float x[n],y[n];
    n=n-1;
    for(i=0;i<=n;i++)
    {
    printf("请依次输入筛孔和正累计产率\n");
    scanf("%f %f",&x[i],&y[i]);
    }
    printf("输入所选模型号：\n");
    scanf("%d",&model_n);
    switch(model_n)
{
case 1:for(i=0;i<=n;i++)
{
u[i]=x[i];
v[i]=y[i];
}
break;
case 2:for(i=0;i<=n;i++)
{
u[i]=log(x[i]);
v[i]=log(log(100/y[i]));
}
break;
case 3:for(i=0;i<=n;i++)
{
u[i]=log10(x[i]);
v[i]=log10(y[i]);
}
break;
case 4:for(i=0;i<=n;i++)
{
u[i]=x[i];
v[i]=log(y[i]);
}
break; 
case 5:for(i=0;i<=n;i++)
{
u[i]=1/x[i];
v[i]=log(y[i]);
}
break;
case 6:for(i=0;i<=n;i++)
{
u[i]=log10(x[i]);
v[i]=y[i];
}
break;
case 7:for(i=0;i<=n;i++)
{
u[i]=exp(-x[i]);
v[i]=1/y[i];
}
break;
case 8:for(i=0;i<=n;i++)
{
u[i]=x[i];
v[i]=log(y[i]);
}
break;
default:printf("不合法的模型号!\n");
break;
}
for(i=0;i<=n;i++)
{
e=e+u[i];
f=f+v[i];
g=g+u[i]*u[i];
l=l+u[i]*v[i];
m=m+v[i]*v[i];
}
e=e/(n+1);
f=f/(n+1);
g=g-(n+1)*e*e;
l=l-(n+1)*e*f;
m=m-(n+1)*f*f;
r=sqrt(g*m);
r=l/r;
c=l/g;
d=f-c*e;
switch(model_n)
{
case 1:
case 6:
case 7:
    a=d;
    b=c;
    break;
case 2:
case 3:
case 4:
case 5:
    a=exp(d);
    b=c;
    break;
case 8:
    a=exp(d);
    b=exp(c);
    break;
default:
    printf("非法模型号！\n");
    break;
}
for(i=0;i<=n;i++)
{
switch(model_n)
{
case 1:
    p[i]=a+b*x[i];
    break;
case 2:
    p[i]=100*exp(-a*pow(x[i],b));
    break;
case 3:
    p[i]=a*pow(x[i],b); 
    break;
case 4:
    p[i]=a*exp(b*x[i]); 
    break;
case 5:
    p[i]=a*exp(b/x[i]); 
    break;
case 6:
    p[i]=a+b*log10(x[i]); 
    break;
case 7:
    p[i]=1/(a+b*exp(-x[i])); 
    break;
case 8:
    p[i]=a*pow(b,x[i]); 
    break;
default:
    printf("非法模型号!\n");
    break;
}
}
for(i=0;i<=n;i++)
{
q=q+(y[i]-p[i])*(y[i]-p[i]);
}
sm=sqrt(q/(n-2));
printf("a=%f b=%f 标准差=%f\n",a,b,sm);
printf("相关系数R=%f\n",r);
printf(" ***********************************\n");
printf(" x  y  y的估计  y-(y的估计)\n");
for(i=0;i<=n;i++)
{
printf(" %f  %f  %f  %f\n",x[i],y[i],p[i],y[i]-p[i]);
}


    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}