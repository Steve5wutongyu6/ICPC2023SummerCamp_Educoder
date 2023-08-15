#include <cstdio>
#include <cmath>
#include <cstring>

const int N = 1000010;
bool isprime[N]; // 存储每个数是否为素数
int prime[N];    // 存储素数

void get_primes() // 预处理素数表
{
    memset(isprime, 1, sizeof isprime); // 初始化 isprime 数组为 true
    int cnt = 0;                        // 初始化素数个数为 0
    for (int i = 2; i <= sqrt(N); i++)  // 枚举每个数
    {
        if (!isprime[i]) // 如果该数不是素数，跳过
            continue;
        prime[cnt++] = i;                   // 将该数存入 prime 数组中
        for (int j = i * 2; j <= N; j += i) // 将该数的倍数标记为非素数
            isprime[j] = false;
    }
}

int main()
{
    get_primes(); // 预处理素数表

    int n;
    while (scanf("%d", &n) && n) // 循环读入 n 的值
    {
        bool flag = false;                   // 初始化标记为 false
        for (int i = 2; i <= n / 2 + 1; i++) // 枚举每个数
        {
            if (isprime[i] && isprime[n - i]) // 如果 i 和 n-i 都是素数
            {
                flag = true;                           // 标记为 true
                printf("%d = %d + %d\n", n, i, n - i); // 输出结果
                break;
            }
        }
        if (!flag) // 如果标记为 false，输出 "Goldbach's conjecture is wrong."
            puts("Goldbach's conjecture is wrong.");
    }
    return 0;
}