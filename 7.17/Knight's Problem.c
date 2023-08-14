#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxn 500000
#define prime 999997

int INF = 1e9 + 7;
int n, m, sx, sy, kx, ky, ans, idx;
double A, B, C, s, gg, a, b, c, ss;
int dx[20]; // 题目要求的方向
int dy[20];

struct point
{
    int x, y;
    int step;
};

struct node
{
    int x, y;
    int next;
};

struct node edge[maxn];
int head[prime];

int hash(int x, int y)
{
    return (((x << 15) ^ y) % prime + prime) % prime;
}

int addedge(int key, int x, int y)
{
    for (int i = head[key]; i != -1; i = edge[i].next)
    {
        if (edge[i].x == x && edge[i].y == y)
            return 0;
    }
    edge[idx].x = x;
    edge[idx].y = y;
    edge[idx].next = head[key];
    head[key] = idx++;
    return 1;
}

double dis(int a, int b, int p, int q)
{
    return ((p - a) * (p - a) + (q - b) * (q - b));
}

int check(int xx, int yy)
{
    gg = sqrt(A * A + B * B);
    a = dis(xx, yy, sx, sy);
    b = dis(xx, yy, kx, ky);
    c = dis(sx, sy, kx, ky);
    if (a + c < b) // 背离起点和终点的情况
        return 0;
    else if (b + c < a)
        return 0;
    else
        ss = fabs(A * xx + B * yy + C * 1.0) / gg;
    if (ss <= s)
        return 1;
    return 0;
}

void bfs()
{
    struct point que[maxn];
    int front = 0, rear = 0;
    struct point st = {sx, sy, 0};
    que[rear++] = st;
    ans = -1;
    addedge(hash(sx, sy), sx, sy);
    while (front < rear)
    {
        struct point k = que[front++];
        struct point kk;
        if (k.x == kx && k.y == ky)
        {
            ans = k.step;
            break;
        }
        for (int i = 0; i < m; i++)
        {
            int xx = k.x + dx[i];
            int yy = k.y + dy[i];
            if (check(xx, yy) && addedge(hash(xx, yy), xx, yy))
            {
                kk.x = xx;
                kk.y = yy;
                kk.step = k.step + 1;
                que[rear++] = kk;
            }
        }
    }
}

int main()
{
    int name;
    scanf("%d", &name);
    while (name--)
    {
        memset(head, -1, sizeof(head));
        idx = 0;
        scanf("%d%d%d%d", &sx, &sy, &kx, &ky); // 根据起点终点写出直线方程
        A = sy - ky;
        B = kx - sx;
        C = sx * ky - kx * sy;
        scanf("%d", &m);
        s = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &dx[i], &dy[i]);
            s = fmax(s, sqrt(dx[i] * dx[i] + dy[i] * dy[i])); // 刚开始忘写sqrt了
        }
        bfs();
        if (ans == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}