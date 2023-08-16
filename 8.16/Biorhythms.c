#include <stdio.h>

int main() {
    int p, e, i, d, case_num = 0; // 声明变量，case_num表示测试用例编号
    while (scanf("%d%d%d%d", &p, &e, &i, &d) == 4 && p != -1) { // 循环读入测试用例
        int k = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252; // 计算下一个三重峰值的天数
        if (k == 0) k = 21252; // 如果k为0，说明当前就是三重峰值，下一个三重峰值就是21252天后
        printf("Case %d: the next triple peak occurs in %d days.\n", ++case_num, k); // 输出结果
    }
    return 0;
}