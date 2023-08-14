#include <stdio.h>
#include <string.h>
#define MAX 99999999
struct coin{
    int p,w;                                  //p价值 w为该币值的硬币的体积
}co[505];
int main() {
    int t,v,n,dp[100000];                     //背包体积为v  n种硬币
    scanf("%d",&t);
    while(t--){
        int e,f;
 
        scanf("%d %d",&e,&f);
        v=f-e;
        scanf("%d",&n);
        for(int i=0;i<=v;i++){
            dp[i]=MAX;
        }
        dp[0]=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&co[i].p,&co[i].w);   //存储n种硬币
        }
 
        for(int i=0;i<n;i++){
            for(int j=co[i].w;j<=v;j++){
                dp[j]=dp[j]<dp[j-co[i].w]+co[i].p?dp[j]:dp[j-co[i].w]+co[i].p;
            }
        }
        if(dp[v]==MAX){
            printf("This is impossible.\n");
        } else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
        }
 
    }
    return 0;
}