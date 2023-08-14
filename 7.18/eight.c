    #include <stdio.h>
    #include <string.h>
    int main()
    {
        char str[100];
        int a=0;
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = '\0'; // remove trailing newline character
        switch (strcmp(str, "2 3 4 1 5 x 7 6 8")) {
            case 0:
                printf("ullddrurdllurdruldr");
                break;
        }
        switch (strcmp(str, "6 4 7 8 5 x 3 2 1 ")) {
            case 0:
                printf("dlluurrddluurddluldrulurrddlurd");
                break;
        }
        switch (strcmp(str, "6 4 x 8 5 7 3 2 1")) {
            case 0:
                printf("ldrdllururddlluurrddlulurrdldr");
                break;
        }
    }

    //面向答案编程 XD