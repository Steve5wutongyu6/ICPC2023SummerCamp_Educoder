#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define sd(n) scanf("%d",&n)
#define sdd(n,m) scanf("%d%d",&n,&m)
#define sddd(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define pd(n) printf("%d\n", n)
#define pc(n) printf("%c", n)
#define pdd(n,m) printf("%d %d", n, m)
#define pld(n) printf("%lld\n", n)
#define pldd(n,m) printf("%lld %lld\n", n, m)
#define sld(n) scanf("%lld",&n)
#define sldd(n,m) scanf("%lld%lld",&n,&m)
#define slddd(n,m,k) scanf("%lld%lld%lld",&n,&m,&k)
#define sf(n) scanf("%lf",&n)
#define sc(n) scanf("%c",&n)
#define sff(n,m) scanf("%lf%lf",&n,&m)
#define sfff(n,m,k) scanf("%lf%lf%lf",&n,&m,&k)
#define ss(str) scanf("%s",str)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mem(a,n) memset(a, n, sizeof(a))
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mod(x) ((x)%MOD)
#define gcd(a,b) __gcd(a,b)
#define lowbit(x) (x&-x)
#define pii map<int,int>
#define mk make_pair
#define rtl rt<<1
#define rtr rt<<1|1
#define Max(x,y) (x)>(y)?(x):(y)
#define int long long


typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll mod = 10007;
const double eps = 1e-9;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
//const int inf = 0x3f3f3f3f;
inline int read(){int ret = 0, sgn = 1;char ch = getchar();
while(ch < '0' || ch > '9'){if(ch == '-')sgn = -1;ch = getchar();}
while (ch >= '0' && ch <= '9'){ret = ret*10 + ch - '0';ch = getchar();}
return ret*sgn;}
inline void Out(int a){if(a>9) Out(a/10);putchar(a%10+'0');}
int qpow(int m, int k, int mod){int res=1%mod,t=m%mod;while(k){if(k&1)res=res*t%mod;t=t*t%mod;k>>=1;}return res;}
ll gcd(ll a,ll b){if(b > a) swap(a,b); return b==0?a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll inv(ll x,ll mod){return qpow(x,mod-2,mod)%mod;}

const int N = 3e6+15;
signed prime[N],mark[N],pcnt;

// 如果变量名都相同的话,就不用传参了
//void getPrimes(int prime[],int N,int &pcnt)
void getPrimes()
{
    memset(mark,0,sizeof(mark));
    mark[0] = mark[1] = 1;
    pcnt = 0;
    for(int i = 2; i < N ; i ++)
    {
        if(!mark[i])
        	prime[pcnt++] = i;
        for(int j = 0 ; (ll)i*prime[j] < N && j < pcnt ; j ++)
        {
            mark[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}

signed res[N];

signed main()
{
    getPrimes();
    int t = 1,cas = 1;
    //cin>>t;
    for(int i = 0 ; i < (int)1e6+7 ; i ++)
    {
        if(!mark[3*i+7])
            res[i] = 1;
        else
            res[i] = 0;
    }
    for(int i = 2 ; i < (int)1e6+7 ; i ++)
        res[i] += res[i-1];
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;

    }
}

