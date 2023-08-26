 #include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;  //可以通过自然溢出省去取模运算
const long long b = 1e9 + 7;
ULL power[1000005], h1, h2[1000005];  //power存储b^k，h1表示子串的哈希值，h2是母串前k位的哈希值
char s1[10005], s2[1000005];  //子串和母串
int main(void)
{
    int t;
    power[0] = 1;  //任何数0次幂等于1
    for(int i = 1; i < 1000005; i++)
        power[i] = power[i - 1] * b;   //求b^k
    cin >> t;
    int len1, len2;  //两个字符串的长度
    while(t--)
    {
        int ans = 0;  //结果
        cin >> s1 + 1 >> s2 + 1;  //字符串向后偏移一位
        len1 = strlen(s1 + 1);
        len2 = strlen(s2 + 1);
        h2[0] = 0;  //两个字符串的哈希值每次都要初始化
        h1 = 0;
        for(int i = 1; i <= len1; i++)
            h1 = h1 * b + (ULL)(s1[i] - 'A' + 1);  //求子串哈希值
        for(int i = 1; i <= len2; i++)
            h2[i] = h2[i - 1] * b + (ULL)(s2[i] - 'A' + 1);   //求母串哈希值
        for(int i = 0; i <= len2 - len1; i++)
        {
            if(h1 == h2[i + len1] - h2[i] * power[len1])  //是否匹配
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

