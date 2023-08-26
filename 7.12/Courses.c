#include <stdio.h>
#include <string.h>
#define MaxN 310
int a[MaxN][MaxN], match[MaxN];
int T, p, n;
int vis[MaxN];
int dfs(int x)
{
    for(int y = 1; y <= n; ++y)
    {
        if(!a[x][y] || vis[y])
            continue;
        vis[y] = 1;
        if(!match[y] || dfs(match[y]))
        {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int k, stu;
    scanf("%d", &T);
    while(T--)
    {
        memset(a, 0, sizeof a);
        memset(match, 0, sizeof match);
        scanf("%d%d", &p, &n);
        for(int i = 1; i <= p; ++i)
        {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j)
            {
                scanf("%d", &stu);
                a[i][stu] = 1;
            }
        }
        if(p > n)
        {
            printf("NO\n");
            continue;
        }
        int ans = 0;
        for(int i = 1; i <= p; ++i)
        {
            memset(vis, 0, sizeof vis);
            if(dfs(i))
                ans++;
        }
        if(ans == p)
            printf("YES\n");    
        else
            printf("NO\n");
        
    }
    return 0;
}