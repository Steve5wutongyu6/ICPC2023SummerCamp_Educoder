#include <stdio.h>
#include <string.h>
#include <math.h>
#define ll long long
/*
占一格或者多格
求圆心占得面积除以总面积
*/
const double PI=acos(-1.0);
int main()
{
 double m,n,c,t,ans[4];
 int cnt=1;
 int k;
 scanf("%d",&k);
 while(k--)
 {
     scanf("%lf%lf%lf%lf",&m,&n,&t,&c);
     ans[0]=(t-c)*(t-c)*(m-2)*(n-2)+(t-c/2)*(t-c/2)*4+(t-c/2)*(t-c)*(m*2+n*2-8);
     ans[2]=(c*c-(c/2)*(c/2)*PI)*(m-1)*(n-1);
     ans[3]=(c/2)*(c/2)*PI*(m-1)*(n-1);
     ans[1]=t*t*m*n-ans[0]-ans[2]-ans[3];
     printf("Case %d:\n",cnt++);
        printf("Probability of covering 1 tile  = %.4f%%\n",ans[0]*100.0/(n*m*t*t));
        for(int i=1;i<4;i++)
        {
            printf("Probability of covering %d tiles = %.4f%%\n",i+1,ans[i]*100.0/(n*m*t*t));
        }
        puts("");
 
 }
    return 0;
}
