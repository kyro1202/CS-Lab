#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

int main()
{
    int test; scanf("%d", &test);
    for(int k = 0 ; k < test ; k++)
    {
    int n; scanf("%d", &n);
    char = grid[n][n];
    for (int i = 0; i < n ; i++)
    {
        scanf("%s", &grid[i][0]);
    }
    for (int j = 0; j < n ; j++)
    {
        qsort(&grid[i][0],n,sizeof(char),cmpfunc);
    }
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n - 1 ; j++)
        {
            if(grid[i][j] > grid[i][j+1])
            {
                printf("NO\n"); flag = 1; goto label;
            }
        }
    }
    label: printf("YES\n"); 
    }
}