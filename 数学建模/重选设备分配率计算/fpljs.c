#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int flag=0,xg=0,j=0,n=6;
    float dp=0,I=0,E=0,x=0,z=0,e[6],d[6]={1.20,1.35,1.45,1.55,1.70,2.20};
    printf("请选择是否修改各密度级别平均密度？\n");
    printf("(默认各密度级别平均密度分别为 1.20,1.35,1.45,1.55,1.70,2.20)\n");
    printf("1：不修改\n2：修改\n");
    scanf("%d",&xg);
    if(xg==2)
    {
        printf("请输入各密度级别平均密度：\n");
        for(j=0;j<n;j++)
        {
            scanf("%f",&d[j]);
        }
    }
    do
    {
    printf("请选择重选设备类型：\n1：跳汰选\n2：重介选\n(输入对应序号)\n");
    scanf("%d",&flag);
    } 
    while (!(flag==1||flag==2));
    printf("请输入分选密度\n");
    scanf("%f",&dp);
    if(flag==1)
    {
        printf("请输入跳汰分选的不完善度：\n");
        scanf("%f",&I);
    }
    if(flag==2)
    {
        printf("请输入重介分选的可能偏差：\n");
        scanf("%f",&E);
    }
    for(j=0;j<n;j++)
    {
        if(flag==1)
            x=(0.6745*(log(d[j]-1)-log(dp-1)))/log(I+sqrt(I*I+1))/1.4142;
        else
            x=0.6745*(d[j]-dp)/E/1.4142;
        if(fabs(x)<=1.79)
        {
            z=x-pow(x,3)/3+pow(x,5)/10-pow(x,7)/42
            +pow(x,9)/216-pow(x,11)/1320+pow(x,13)/9360
            -pow(x,15)/75600+pow(x,17)/685440;
            e[j]=(0.5+0.5642*z)*100;
        }
        else if(x>1.79)
                e[j]=100;
            else
                e[j]=0;
    }
    printf(" ***********************************\n");
    printf("分选密度: %f\n",dp);
    printf(" ***********************************\n");
    printf("    密度级别        分配率\n");
    printf("      -1.3          %.2f\n",e[0]);
    printf("    1.3~1.4         %.2f\n",e[1]);
    printf("    1.4~1.5         %.2f\n",e[2]);
    printf("    1.5~1.6         %.2f\n",e[3]);
    printf("    1.5~1.8         %.2f\n",e[4]);
    printf("      +1.8          %.2f\n",e[5]);
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
