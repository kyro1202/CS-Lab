#include <stdio.h>

int check(char* , int , int  );

int main()
{
    int n; scanf("%d", &n);
    char grid[n][n]; int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &grid[i][j]);    
        }
    }
    for(int i = 1 ; i < n - 1 ; i++)
    {
        for(int j = 1 ; j < n - 1 ; j++)
        {
            flag = check(&grid[0][0],i,j);
            if(flag == 1)
                grid[i][j] = 'X';
            else
                flag = 0;
        }
    }
    for (int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int check(char* grid,int a,int b)
{
    if((int)grid[a][b] > (int)grid[a+1][b] && (int)grid[a][b] > (int)grid[a-1][b] && (int)grid[a][b] > (int)grid[a][b+1] && (int)grid[a][b] > (int)grid[a][b-1])
        return 1;
    else
        return 0;    
}