#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int ll;

void exgcd(ll a, ll b, ll* d, ll* x, ll* y)
{
    if(!b){
        *d = a, *x = 1, *y = 0;
    }else{
        exgcd(b, a % b, d, y, x);
        *y -= *x * (a / b);
    }
}

void cal(ll a, ll b, ll c)
{
    ll gcd, x, y;
    int isswap = 0;
    if(b > a){
        ll temp = a;
        a = b;
        b = temp;
        isswap = 1;
    }
    exgcd(a, b, &gcd, &x, &y);
    x = x * (c / gcd);
    y = y * (c / gcd);
    int k1 = b / gcd;
    int k2 = a / gcd;
    int t = y * gcd / a;
    int min = fabs(x) + fabs(y), num1 = fabs(x), num2 = fabs(y);
    for(int i = -10; i <= 10; ++i){
        int temp = t + i;
        if(min > fabs(x + k1 * temp) + fabs(y - k2 * temp)){
            min = fabs(x + k1 * temp) + fabs(y - k2 * temp);
            num1 = fabs(x + k1 * temp);
            num2 = fabs(y - k2 * temp);
        }
    }
    if(isswap){
        ll temp = num1;
        num1 = num2;
        num2 = temp;
    }
    printf("%d %d\n", num1, num2);
}

int main()
{
    ll a, b, c;
    while(scanf("%d %d %d", &a, &b, &c)){
        if(a == 0 && b == 0 && c == 0) break;
        cal(a, b, c);
    }
    return 0;
}