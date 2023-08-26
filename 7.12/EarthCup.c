#include<stdio.h>
#include<stdlib.h>
#define maxn 55555
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        long long sum = 0;
        int *a = (int*)malloc((n+1) * sizeof(int));
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
        {
            sum += a[i];
            if(sum < 1ll * i * (i - 1) / 2)
            {
                printf("The data have been tampered with!\n");
                free(a);
                break;
            }
            if(i == n && sum != 1ll * n * (n - 1) / 2)
            {
                printf("The data have been tampered with!\n");
                free(a);
                break;
            }
            if(i == n)
            {
                printf("It seems to have no problem.\n");
                free(a);
            }
        }
    }
    return 0;
}