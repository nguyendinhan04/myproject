#include <stdio.h>

int map[9][9];


int check(int row, int col, int num)
{
    int cout1, cout2;
    for (cout1 = 0; cout1 < 9; cout1++)
    {
        if(cout1 == col) continue;
        if (map[row][cout1] == num)
        {
            // printf("\nsai 1__%d__grid[%d][%d]",num,row,cout1);
            return 0;
        }
    }

    for (cout1 = 0; cout1 < 9; cout1++)
    {
        if(cout1 == row) continue;
        if (map[cout1][col] == num)
        {
            // printf("\nsai 2__%d__grid[%d][%d]",num,cout1,col);
            return 0;
        }
    }
    // printf("\n%d %d",col,row);
    // printf("\n%d %d",(col/3)*3,(row/3)*3);

    for (cout1 = (col / 3) * 3; cout1 < (col / 3) * 3 + 3; cout1++)
    {
        for (cout2 = (row / 3) * 3; cout2 < (row / 3) * 3 + 3; cout2++)
        {
            if(cout1 == col || cout2 == row) continue;
            if (map[cout2][cout1] == num)
            {
                // printf("\nsai 3__%d__grid[%d][%d]",grid[cout2][cout1],cout2,cout1);
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    int m;
    int i, j;
    int flag;
    for (m = 1; m <= t; m++)
    {
        flag = 0;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                map[i][j] = 0;
            }
        }
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                scanf("%d", &map[i][j]);
                if (check(i, j, map[i][j]) == 0)
                {
                    flag = 1;
                    // printf("sai %d,%d",i,j);
                    // break;
                }
            }
        }
        if (flag == 0)
            printf("1\n");
        else
            printf("0\n");
    }
}