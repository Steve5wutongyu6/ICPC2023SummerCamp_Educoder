#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100007
#define INF 0x3f3f3f3f
int a[MAX_SIZE];
int b[MAX_SIZE];
int queue[MAX_SIZE];
int front = 0;
int rear = 0;
void enqueue(int x) {
    queue[rear++] = x;
}
int dequeue() {
    return queue[front++];
}
int isQueueEmpty() {
    return front == rear;
}
int bfs(int n, int k) {
    memset(a, 0, sizeof(a));
    memset(b, INF, sizeof(b));
    b[n] = 0;
    
    enqueue(n);
    a[n] = 1;
    
    while (!isQueueEmpty()) {
        int x = dequeue();
        
        if (x == k) {
            return b[x];
        } else {
            if (!a[x + 1] && x + 1 >= 0 && x + 1 <= 100000) {
                enqueue(x + 1);
                a[x + 1] = 1;
                b[x + 1] = b[x] + 1;
            }
            if (!a[x - 1] && x - 1 >= 0 && x - 1 <= 100000) {
                enqueue(x - 1);
                a[x - 1] = 1;
                b[x - 1] = b[x] + 1;
            }
            if (!a[x * 2] && 2 * x >= 0 && 2 * x <= 100000) {
                enqueue(x * 2);
                a[x * 2] = 1;
                b[x * 2] = b[x] + 1;
            }
        }
    }
    
    return 0;
}
int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        printf("%d\n", bfs(n, k));
    }
    
    return 0;
}