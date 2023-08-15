#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef int ll;
void exgcd(ll a, ll b, ll& d, ll& x, ll &y)
{
    if(!b){
        d = a,x = 1,y = 0;
    }else{
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
void cal(ll a, ll b,ll c)
{
    ll gcd,x,y;
    bool isswap = false;
    if(b>a){
        swap(a,b);
        isswap = true;
    }
    exgcd(a,b,gcd,x,y);
    x = x *(c/gcd);
    y = y *(c/gcd);
    int k1 = b /gcd ;
    int k2 = a /gcd ;
    int t = y * gcd / a;
    int min = fabs(x)+ fabs(y),num1 = fabs(x),num2 = fabs(y);
    for(int i = -10; i<=10;++i){
        int temp = t+i;
        if(min>fabs(x+k1*temp) + fabs(y-k2*temp)){
            min = fabs(x+k1*temp) + fabs(y-k2*temp);
            num1 = fabs(x+k1*temp);
            num2 = fabs(y-k2*temp);
        }
    }
    if(isswap) swap(num1,num2);
    printf("%d %d\n",num1,num2);
}
int main()
{
    //freopen("in.txt","r",stdin);
    ll a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)){
        if(a == 0 && b == 0 && c == 0) break;
        cal(a,b,c);
    }
    return 0;
}