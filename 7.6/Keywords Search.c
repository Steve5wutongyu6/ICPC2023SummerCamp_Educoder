# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main ()
{
    int i=0,N=0;
    scanf("%d",&i);//有多少个测试用例
    for (int j = 0; j < i; j++)
    {
        scanf("%d",&N);//每个测试用例有多少个关键词
        char **keywords = (char **)malloc(N*sizeof(char *));//动态分配内存
        for (int k = 0; k < N; k++)
        {
            keywords[k] = (char *)malloc(100*sizeof(char));
            scanf("%s",keywords[k]);
        }
        char *str = (char *)malloc(100*sizeof(char));
        scanf("%s",str);
        int count = 0;
        for (int k = 0; k < N; k++)
        {
            if (strstr(str,keywords[k])!=NULL)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    
}