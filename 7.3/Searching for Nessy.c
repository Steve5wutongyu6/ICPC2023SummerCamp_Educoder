// 尼斯湖水怪
//  Created by 五桶鱼 on 2023/7/3.
#include <stdio.h>

int main()
{
    int t = 0, m = 0, n = 0;
    scanf("%d", &t);
    while (t > 0)
    {
        scanf("%d %d", &m, &n);
        printf("%d\n", (m / 3) * (n / 3));
        t--;
    }
}
