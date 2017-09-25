/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To find the shotest path in a matrix*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf (int)1e9//for initialising the array
int m,n;
char answer[500];//to store the direction of moves
int dp[101][101];
int min(int a,int b)//returns the minimum of a and b
{
	return ( a < b ) ? a : b ;
}
int main()
{
	printf("Enter the number of rows and columns - "); scanf("%d %d", &m,&n);
	int cost[m][n];
	int i,j;
	memset(dp,inf,sizeof(dp));
	memset(answer,'\0',sizeof(answer));
	printf("Enter the cost of entering each room - \n");
	for(i = 0 ; i < m ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	/*BOTTOM UP APPROACH FOR THE DP*/
	for(i = 0 ; i < n ; i++)//for the first row we can only go rightward
	{
		if(i==0)
			dp[0][i] = cost[0][0];
		else
			dp[0][i] = dp[0][i-1] + cost[0][i];
	}
	for(i = 1 ; i < m ; i++)//for the first column we can only go downward
	{
		dp[i][0] = dp[i-1][0] + cost[i][0];
	}
	for(i = 1 ; i < m ; i++)//for every other case we have to check the minimum cost of travelling to that box(subproblem)
	{
		for(j = 1 ; j < n ; j++)
		{
			dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + cost[i][j];
		}
	}
	int ans = 0; int mark = 0;
	int moves[500];
	int x = m-1,y = n-1;
	//kind of tail recursion to get the answer
	while(x != 0 || y != 0)
	{
		if(x == 0)//in first row can go left only
		{
			answer[mark] = 'r';
			moves[mark] = cost[x][y-1];
			y--;
			mark++;
			continue;
		}
		else if(y == 0)//first column can go up only
		{
			answer[mark] = 's';
			moves[mark] = cost[x-1][y];
			x--;
			mark++;
			continue;
		}
		int temp = min(min(dp[x-1][y],dp[x][y-1]),dp[x-1][y-1]);//else checking for every possible option
		if(temp == dp[x-1][y-1])
		{
			answer[mark] = 'd';
			moves[mark] = cost[x-1][y-1];
			x--; y--;
		}
		else if(temp == dp[x][y-1])
		{
			answer[mark] = 'r';
			moves[mark] = cost[x][y-1];
			y--;
		}
		else
		{
			answer[mark] = 's';
			moves[mark] = cost[x-1][y];
			x--;
		}
		mark++;
	}
	printf("Minimum cost of travelling - ");//printing the final answer
	for(i = mark-1 ; i >= 0 ; i--)
	{
		printf("%d+", moves[i]);
	}
	printf("%d=%d\nMoves : ", cost[m-1][n-1],dp[m-1][n-1]);
	for(i = mark-1 ; i >= 0 ; i--)
	{
		if(i != mark-1)
			printf(",");
		if(answer[i] == 'd')
			printf("diagonal");
		else if(answer[i] == 'r')
			printf("rightward");
		else
			printf("downward");
	}
	printf("\n");
}
