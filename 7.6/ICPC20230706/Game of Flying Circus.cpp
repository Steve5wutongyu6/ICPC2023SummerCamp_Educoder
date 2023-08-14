#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        double T, v1, v2;
        cin >> T >> v1 >> v2;
        if (v1 == v2) // 第一段相遇
        {
            printf("Case #%d: Yes\n", cas);
            continue;
        }
        if (300.0 * sqrt(2) / v1 < 600.0 / v2) // 第二段相遇
        {

            double l = 0, r = 300;
            for (int i = 0; i < 100; i++)
            {
                double mid = (l + r) / 2.0;
                double len = mid * mid + 300 * 300;
                len = sqrt(len);
                double t1 = len / v1;
                double t2 = 300 / v2 + mid / v2;
                if (t1 > t2)
                    l = mid;
                else
                    r = mid;
            }
            double t1, t2;
            t1 = sqrt(l * l + 300 * 300) / v1 + l / v1 + 2 * 300 / v1;
            t2 = T + 3 * 300 / v2;
            if (t1 <= t2)
                printf("Case #%d: Yes\n", cas);
            else
                printf("Case #%d: No\n", cas);
        }
        else if (300.0 / v1 < 900.0 / v2)
        {
            double l = 0, r = 300;
            for (int i = 0; i < 100; i++)
            {
                double mid = (l + r) / 2.0;
                double len = mid * mid + 300 * 300;
                len = sqrt(len);
                double t1 = len / v1;
                double t2 = (900 - mid) / v2;
                if (t1 > t2)
                    r = mid;
                else
                    l = mid;
            }
            double t1, t2;
            t1 = sqrt(300 * 300 + l * l) / v1 + sqrt(300 * 300 + (300 - l) * (300 - l)) / v1 + 3 * 300 / v1;
            t2 = T + 300 * 4 / v2;
            if (t1 <= t2)
                printf("Case #%d: Yes\n", cas);
            else
                printf("Case #%d: No\n", cas);
        }
        else
            printf("Case #%d: No\n", cas);
    }
}