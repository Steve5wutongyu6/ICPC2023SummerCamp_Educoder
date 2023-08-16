#include <stdio.h>
#include <string.h>

#define N 3000015

signed prime[N], mark[N], pcnt; // 声明全局变量，prime数组存储素数，mark数组标记是否为素数，pcnt表示素数个数

void getPrimes() // 求素数
{
    memset(mark, 0, sizeof(mark)); // 初始化mark数组为0
    mark[0] = mark[1] = 1; // 0和1不是素数，标记为1
    pcnt = 0; // 初始化素数个数为0
    for (int i = 2; i < N; i++) // 从2开始枚举
    {
        if (!mark[i]) // 如果i是素数
            prime[pcnt++] = i; // 将i存入素数数组中，素数个数加1
        for (int j = 0; (signed long long)i * prime[j] < N && j < pcnt; j++) // 枚举小于i的素数
        {
            mark[i * prime[j]] = 1; // 标记i*prime[j]不是素数
            if (i % prime[j] == 0) // 如果i是prime[j]的倍数，退出循环
                break;
        }
    }
}

signed res[N]; // 声明全局变量，res数组存储Sn的值

int main()
{
    getPrimes(); // 求素数
    int t = 1, cas = 1; // 声明变量，t表示测试用例个数，cas表示测试用例编号
    for (int i = 0; i < (int)1e6 + 7; i++) // 枚举i
    {
        if (!mark[3 * i + 7]) // 如果3i+7是素数
            res[i] = 1; // Sn的值为1
        else
            res[i] = 0; // Sn的值为0
    }
    for (int i = 2; i < (int)1e6 + 7; i++) // 计算Sn的值
        res[i] += res[i - 1];
    scanf("%d", &t); // 读入测试用例个数
    while (t--)
    {
        int n;
        scanf("%d", &n); // 读入n
        printf("%d\n", res[n]); // 输出Sn的值
    }
    return 0;
}