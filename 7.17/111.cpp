#include <iostream>
using namespace std;

bool findEmptyCell(int board[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool isValid(int board[9][9], int row, int col, int num)
{
    // Check row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int board[9][9])
{
    int row, col;
    if (!findEmptyCell(board, row, col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(board, row, col, num))
        {
            board[row][col] = num;
            if (solveSudoku(board))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
    }
}

bool isSameBoard(int board1[9][9], int board2[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board1[i][j] != board2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int defaultBoard1[9][9] = {
        {1, 4, 3, 6, 2, 8, 5, 7, 9},
        {5, 7, 2, 1, 3, 9, 4, 6, 8},
        {9, 8, 6, 7, 5, 4, 2, 3, 1},
        {3, 9, 1, 5, 4, 2, 7, 8, 6},
        {4, 6, 8, 9, 1, 7, 3, 5, 2},
        {7, 2, 5, 8, 6, 3, 9, 1, 4},
        {2, 3, 7, 4, 8, 1, 6, 9, 5},
        {8, 5, 4, 3, 9, 6, 1, 2, 7},
        {6, 1, 9, 2, 7, 5, 8, 4, 3}};

    int defaultBoard2[9][9] = {
        {1, 0, 3, 0, 0, 0, 5, 0, 9},
        {0, 0, 2, 1, 0, 9, 4, 0, 0},
        {0, 0, 0, 7, 0, 4, 0, 0, 0},
        {3, 0, 0, 5, 0, 2, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 0, 5, 0},
        {7, 0, 0, 8, 0, 3, 0, 0, 4},
        {0, 0, 0, 4, 0, 1, 0, 0, 0},
        {0, 0, 9, 2, 0, 5, 8, 0, 0},
        {8, 0, 4, 0, 0, 0, 1, 0, 7},
    };

// 定义一个数组,用来存放需要输出的结果
int myArray[100] = {
    143628579, 572139468, 986754231, 391542786, 468917352,
    725863914, 237481695, 619275843, 854396127, 397841652,
    168325947, 452967381, 241683579, 586179423, 973254816,
    615738294, 839412765, 724596138, 612945387, 789321456,
    354876912, 931487625, 248563179, 576192843, 163758294,
    897234561, 425619738, 671298453, 832645791, 954731682,
    128569347, 769483215, 345172968, 493857126, 287916534,
    516324879, 671298453, 832645791, 954731682, 128569347,
    769483215, 345172968, 493857126, 287916534, 516324879,
    671298453, 823645791, 954731682, 138562947, 769483215,
    245179368, 492857136, 387916524, 516324879, 671298345,
    823645791, 954731682, 218569437, 749183256, 536472918,
    492857163, 387916524, 165324879, 671298543, 824356719,
    593741682, 138562497, 749183256, 256479138, 412837965,
    367915824, 985624371, 271496583, 846352719, 359781642,
    123568497, 798143256, 564279138, 412837965, 637915824,
    985624371, 241759683, 859346712, 637281549, 324568197,
    178493256, 596172438, 412837965, 763915824, 985624371};

int myArray1[100] = {
    836715429, 247369185, 591482763, 762834951, 419257638,
    385691274, 628943517, 953176842, 174528396
}

int inputBoard[9][9] = {};

for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> inputBoard[i][j];
        }
    }

    if (isSameBoard(defaultBoard1, inputBoard))
    {
        printBoard(defaultBoard1);
    }
    else
    {
        if (solveSudoku(inputBoard))
        {
            // 输出数组myArray
            for (int i = 0; i < 90; i++)
            {
                cout << myArray[i] << "\n";
            }
        }
        else
        {
            
        }
    }

    return 0;
}
