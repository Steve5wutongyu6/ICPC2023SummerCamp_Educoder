#include<stdio.h>
#include<string.h>
#define MAXN 0x3f3f3f3f3f3f3f3f
const int N = 1005;
int e[N][N];
int book[N];
int match[N];
int n, m;
int dfs(int u) {
  for (int i = 1; i <= m; i++) {
    if (!book[i] && e[u][i] == 1) {
      book[i] = 1;
      if (match[i] == 0 || dfs(match[i])) {
        match[i] = u;
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  int k;
  while (scanf("%d%d%d", & n, & m, & k) != EOF) {
    memset(e, 0, sizeof(e));
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= k; i++) {
      int a, b;
      scanf("%d%d", & a, & b);
      e[a][b] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      memset(book, 0, sizeof(book));
      if (dfs(i)) ans++;
    }
    printf("%d\n", m + n - ans);
  }
  return 0;
}