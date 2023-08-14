#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
    int n; // 变量n用于存储比赛的堆数
    while (~scanf("%d",&n)) // 当输入的堆数不为负数时，继续循环
    {
        int a=0,b=0; // 变量a用于存储异或运算的结果，变量b用于存储每一堆的火柴数量
        for (int i = 0; i < n; i++) // 循环n次，读取每一堆的火柴数量
        {
            scanf("%d",&b); // 读取每一堆的火柴数量
            a^=b; // 使用异或运算更新变量a的值
        }
        printf("%s\n",a?"Yes":"No");
        //printf("%s\n",a?"先玩的玩家能赢得比赛":"先玩的玩家不能赢得比赛"); 
        // 根据变量a的值判断先玩的玩家是否能赢得比赛，并输出相应的结果
    }   
}
