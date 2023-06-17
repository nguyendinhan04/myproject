#include<stdio.h>

// int grid[9][9];
int sol=0;

int check(int row,int col,int num,int grid[9][9])
{
    int cout1,cout2;
    for(cout1=0;cout1<9;cout1++)
    {
        if(cout1 == col) continue;
        if(grid[row][cout1]==num) 
        {
            // printf("\nsai 1__%d__grid[%d][%d]",num,row,cout1);
            return 0;
        }
    }

    for(cout1=0;cout1<9;cout1++)
    {
        if(cout1 == row) continue;
        if(grid[cout1][col]==num) 
        {
            
            // printf("\nsai 2__%d__grid[%d][%d]",num,cout1,col);
            return 0;
        }
    }
    // printf("\n%d %d",col,row);
    // printf("\n%d %d",(col/3)*3,(row/3)*3);

    for(cout1=(col/3)*3;cout1 < (col/3)*3 +3;cout1++)
    {
        for(cout2=(row/3)*3;cout2 < (row/3)*3 +3;cout2++)
        {
            if(cout1 == col || cout2 == row) continue;
            if(grid[cout2][cout1]==num) 
            {
                // printf("\nsai 3__%d__grid[%d][%d]",grid[cout2][cout1],cout2,cout1);
                return 0;
            }
            
        }
    }
    return 1;
    
}


void solve(int row,int col,int grid[9][9])
{
    if(row==8 && col ==9) 
    {
        // printf("YES %d",sol);
        sol=sol +1;
        return;
    }

    else if(col == 9 && row != 8)
    {
        solve(row+1,0,grid);
    }
    else
    {
        if(grid[row][col]>0) solve(row,col+1,grid);
        else
        {
            int cout;
            for(cout=1;cout<=9;cout++)  
            {
                if(check(row,col,cout,grid)==1)
                {   
                    grid[row][col] = cout;
                    solve(row,col+1,grid);

                }
                grid[row][col] = 0;
            }
        }
    }


}


int main()
{   
    int grid[9][9];
    // int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    //                    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    //                    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    //                    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    //                    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    //                    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    //                    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    //                    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    //                    { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
     int i,j;
     for(i=0;i<9;i++)
     {
        for(j=0;j<9;j++)
        {
            scanf("%d",&grid[i][j]);
        }
     }
        solve(0,0,grid);
        printf("%d",sol);
    // for(i=0;i<9;i++)
    // {
    //     for(j=0;j<9;j++)
    //     {
    //         printf("%d ",grid[i][j]);
    //     }
    //     printf("\n");
    // }
}
