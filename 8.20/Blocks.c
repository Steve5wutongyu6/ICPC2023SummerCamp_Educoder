#include<stdio.h>
#include<string.h>

#define ll long long
#define inf 0x3f3f3f3f

struct mat{
    ll a[5][5];
};

int mod=10007,n,k;

mat operator*(mat x,mat y)
{
    mat ans;
    memset(ans.a,0,sizeof(ans.a));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                ans.a[i][j]+=(ll)x.a[i][k]*y.a[k][j];
                ans.a[i][j]%=mod;
            }
    return ans;
}

mat qmod(mat a,int k)
{
    mat ret;
    memset(ret.a,0,sizeof(ret.a));
    for(int i=0;i<3;i++)
        ret.a[i][i]=1;
    while(k)
    {
        if(k&1)
        {
            ret= ret*a;
        }
        k>>=1;
        a=a*a;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n==0) printf("1\n");
        else
        {
            mat base;
            base.a[0][0] = 2; base.a[0][1]  = 1; base.a[0][2] = 0;
            base.a[1][0] = 2; base.a[1][1]  = 2; base.a[1][2] = 2;
            base.a[2][0] = 0; base.a[2][1]  = 1; base.a[2][2] = 2;
            mat ans = qmod(base, n);
            printf("%lld\n", ans.a[0][0]);
        }
    }
    return 0;
}