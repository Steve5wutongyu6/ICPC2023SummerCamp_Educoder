#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define uint unsigned int
void solve(int n) {
    char name[30];
    scanf("%s", name);
    printf("%s\n", name);
    if (--n){
        scanf("%s", name);
        if (--n)
            solve(n);
        printf("%s\n", name);
    }
}
int main(){
    int n, t = 0;      
    while (scanf("%d",&n) , n) {
        printf("SET %d\n", ++t);
        solve(n);
    }
    return 0;
}