# include <stdio.h>

int main ()
{
 int T=0,n=0,id=0;
 double p=0;
 scanf("%d",&T);
 while (T--)
 {
 scanf("%d%lf%d",&n,&p,&id);
 double q = 1-p;
 double tmp = 1; //修改
 for (int i=1;i<id;i++)
 {
 tmp *= q;
 }
 //tmp *= q; //删除
 double a=q; //修改
 for (int i=1;i<n;i++)
 {
 a *= q; //修改
 }
 printf("%.4lf\n",p==0?0:(tmp*p)/(1-a));
 }
 return 0;
}
