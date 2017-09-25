/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To implement a coin exchange dp problem*/
#include <stdio.h>
#include <stdlib.h>
#define inf 1e9//inf to be max
int coins[1000];
int n;
int used[1000];
int dp[100000];
int count[100000];
int main()
{
	printf("Enter the number of coins - "); scanf("%d", &n);
	int i,j;
	for(i = 0 ; i < 1000 ; i++)
	{
		coins[i] = 0;
		used[i] = -1;
	}
	printf("Enter the values of the coins -\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d", &coins[i]);
	}
	for(i = 0 ; i < 100000 ; i++)//initialising dp
	{	
		dp[i] = inf;
		count[i] = 0;
	}
	int s;
	printf("Enter the sum - "); scanf("%d", &s);
	dp[0] = 0;//bottom up approch
	for(i = 0 ; i <= s ; i++)//for every amount
	{
		for(j = 0 ; j < n ; j++)//for every coin
		{
			if(i < coins[j])
				continue;
			if(dp[i-coins[j]] + 1 <= dp[i])//if a better solution is available
			{
				dp[i] = dp[i-coins[j]] + 1;//updating the value of dp
				used[i] = coins[j];//storing the coin used to get to this solution
			}
		}
	}
	if(dp[s] == inf)
		printf("IMPOSSIBLE !!!\n");
	else
	{
		printf("Total number of coins required - %d\n", dp[s]);
		i = 0;
		for(i = s ; i > 0 ; )//counting the coins used
		{
			count[used[i]]++;
			i -= used[i];
		}
		for(i = 0 ; i < 100000 ; i++)
		{
			if(count[i] != 0)
			{
				printf("%d coins of denomination - %d\n", count[i],i);
			}
		}
	}
}
