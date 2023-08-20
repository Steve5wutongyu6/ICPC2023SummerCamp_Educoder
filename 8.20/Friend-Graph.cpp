//C - Friend-Graph HDU - 6152 
//引用自https://blog.csdn.net/Bookerbobo/article/details/126713575
#include <iostream>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<queue>
#include<bitset>
#include<vector>
#include<map>
#include<unordered_map>
#define int long long
#define endl '\n'
#define lowbit(x) (x &-x) // lowbit 函数，返回 x 的二进制表示中最低位的 1 所对应的值
#define mh(x) memset(x, -1, sizeof h) // 将数组 x 的所有元素赋值为 -1
#define debug(x) cerr << #x << "=" << x << endl; // 输出变量 x 的值
#define brk exit(0); // 退出程序
using namespace std;
void TLE() { ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); } // 关闭同步流，加速输入输出
const int N = 3e3 + 10; // 定义常量 N
const int M = 2 * N; // 定义常量 M
const int mod = 998244353; // 定义常量 mod
const double esp = 1e-6; // 定义常量 esp
const double pi = acos(-1); // 定义常量 pi
typedef pair<int, int> PII; // 定义类型 PII
typedef long long ll; // 定义类型 ll
bitset<3001>g[N], f[N], init; // 定义 bitset 数组 g, f 和 init
bool tt[N][N]; // 定义 bool 类型的二维数组 tt
void solve() // 定义函数 solve
{
    int n; // 定义变量 n
    cin >> n; // 输入 n
    for (int i = 1;i <= n;i++) // 初始化 bitset 数组 g 和 f
        g[i] = init, f[i] = init;
    for (int i = 1;i < n;i++) // 输入数据
    {
        for (int j = 1;j <= n - i;j++)
        {
            int x;
            cin >> x;tt[i][j] = x;
            if (x == 1) // 如果 x 等于 1
                g[i][j + i] = 1, g[j + i][i] = 1; // 将 g[i][j+i] 和 g[j+i][i] 设为 1
            else if (x == 0) // 如果 x 等于 0
                f[i][j + i] = 1, f[j + i][i] = 1; // 将 f[i][j+i] 和 f[j+i][i] 设为 1
        }
    }
    for (int i = 1;i < n;i++) // 判断是否存在小团体
    {
        for (int j = 1;j <= n - i;j++)
        {
            if (tt[i][j] == 1) // 如果 tt[i][j] 等于 1
            {
                bitset<3001>res = (g[i] & g[j + i]); // 计算 g[i] 与 g[j+i] 的按位与
                if (res.count() >= 1) // 如果 res 中有至少一个 1
                {
                    cout << "Bad Team!" << endl; // 输出 Bad Team!
                    return; // 返回
                }
            }
            else // 如果 tt[i][j] 不等于 1
            {
                 bitset<3001>res = (g[i] & g[j + i]); // 计算 g[i] 与 g[j+i] 的按位与
                res = (f[i] & f[j + i]); // 计算 f[i] 与 f[j+i] 的按位与
                if (res.count() >= 1) // 如果 res 中有至少一个 1
                {
                    cout << "Bad Team!" << endl; // 输出 Bad Team!
                    return; // 返回
                }
            }
        }
    }
    cout << "Great Team!" << endl; // 输出 Great Team!
}
 
signed main() // 主函数
{
    TLE(); // 调用 TLE 函数
    int T;cin >> T; // 输入 T
    while (T--) // 循环 T 次
        solve(); // 调用 solve 函数
    return 0; // 返回 0
}