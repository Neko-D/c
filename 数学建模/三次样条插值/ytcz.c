#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n=10,i=0,j=0,m=0;
    float e=0,e1=0,ff=0,f1=0,h1=0,p=0;
    printf("请输入数据组数\n");
    scanf("%d",&n);
    printf("请输入 待插值点个数 和 间隔\n");
    scanf("%d %f",&m,&p);
    float x[n],y[n],a[n],b[n],c[n],d[n],h[n],beta[n],z[m+1],f[m+1];
    n=n-1;
    for(i=0;i<=n;i++)
    {
    printf("请依次输入浮物累计产率和密度\n");
    scanf("%f %f",&x[i],&y[i]);
    }
    for(i=1;i<=m;i++)//从z[1]开始存数据而非z[0]开始存，为的是符合后续f[]的计算
    {
        z[i]=(i-1)*p;
    }
    for(i=1;i<=n;i++)
    {
    h[i-1]=x[i]-x[i-1];
    }
    for(i=1;i<=n-1;i++)
    {
        a[i]=h[i-1]/(h[i-1]+h[i]);
        b[i]=3*((1-a[i])*(y[i]-y[i-1])/h[i-1]+a[i]*(y[i+1]-y[i])/h[i]);
    }
    a[0]=1;
    a[n]=0;
    b[0]=3*(y[1]-y[0])/h[0];
    b[n]=3*(y[n]-y[n-1])/h[n-1];
    for(i=0;i<=n;i++)
    {
        d[i]=2;
    }
    for(i=1;i<=n;i++)
    {
        c[i]=1-a[i];
    }
    for(i=1;i<=n;i++)
    {
        if(fabs(d[i])<=0.000001)
        {
            printf("Fail!!!\n");
            exit(1);
        }
        a[i-1]=a[i-1]/d[i-1];
        b[i-1]=b[i-1]/d[i-1];
        d[i]=a[i-1]*(-c[i])+d[i];
        b[i]=-c[i]*b[i-1]+b[i];
    }
    beta[n]=b[n]/d[n];
    for(i=1;i<=n;i++)
    {
        beta[n-i]=b[n-i]-a[n-i]*beta[n-i+1];
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(z[i]<=x[j])
            {
                j=j-1;
                break;
            }
        }
        e=x[j+1]-z[i];
        e1=e*e;
        ff=z[i]-x[j];
        f1=ff*ff;
        h1=h[j]*h[j];
        f[i]=(3*e1-2*e1*e/h[j])*y[j]+(3*f1-2*f1*ff/h[j])*y[j+1];
        f[i]=f[i]+(h[j]*e1-e1*e)*beta[j]-(h[j]*f1-f1*ff)*beta[j+1];
        f[i]=f[i]/h1;
    }
    printf(" ***********************************\n");
    printf("   No     累计产率     密度   \n");
    for(i=1;i<=m;i++)
    {
        printf("%4d    %8.3f   %8.3f\n",i,z[i],f[i]);
    }
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
