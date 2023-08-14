#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

typedef struct {
    char name[25]; // 考号
    int num;       // 解决题目数
    int sum;       // 分数
} Student;

// 比较函数，用于排序
int cmp(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;

    if (studentA->sum == studentB->sum) {
        return strcmp(studentA->name, studentB->name);
    } else {
        return studentB->sum - studentA->sum;
    }
}

void process_exam() {
    Student students[MAX_N]; // 存储考生信息的数组
    int n, m, g; // 考生数量、题目数量、及格分数线

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        scanf("%d %d", &m, &g);

        int scores[m]; // 存储每道题目的分数

        // 输入每道题目的分数
        for (int i = 0; i < m; i++) {
            scanf("%d", &scores[i]);
        }

        // 输入每个考生的信息
        for (int i = 0; i < n; i++) {
            scanf("%s", students[i].name);
            scanf("%d", &students[i].num);

            students[i].sum = 0;
            // 计算每个考生的总分
            for (int j = 0; j < students[i].num; j++) {
                int problem;
                scanf("%d", &problem);
                students[i].sum += scores[problem - 1];
            }
        }

        // 按照题目要求进行排序
        qsort(students, n, sizeof(Student), cmp);

        int count = 0; // 不低于分数线的考生人数
        for (int i = 0; i < n; i++) {
            if (students[i].sum >= g) {
                count++;
            } else {
                break;
            }
        }

        // 输出结果
        printf("%d\n", count);
        for (int i = 0; i < count; i++) {
            printf("%s %d\n", students[i].name, students[i].sum);
        }
    }
}

int main() {
    process_exam();
    return 0;
}
