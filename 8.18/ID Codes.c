#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 用于比较两个字符的大小，用于排序
int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int main()
{
    char code[55];
    while (scanf("%s", code) == 1 && code[0] != '#')
    {
        int len = strlen(code);
        // 从后往前找到第一个降序的字符
        int i;
        for (i = len - 2; i >= 0; i--)
        {
            if (code[i] < code[i + 1])
            {
                break;
            }
        }
        if (i < 0)
        {
            // 如果没有找到，则说明已经是最后一个，输出 No Successor
            printf("No Successor\n");
        }
        else
        {
            // 从后往前找到第一个比 code[i] 大的字符
            int j;
            for (j = len - 1; j > i; j--)
            {
                if (code[j] > code[i])
                {
                    break;
                }
            }
            // 交换 code[i] 和 code[j]
            char temp = code[i];
            code[i] = code[j];
            code[j] = temp;
            // 对 i 后面的字符进行排序
            qsort(code + i + 1, len - i - 1, sizeof(char), cmp);
            printf("%s\n", code);
        }
    }
    return 0;
}