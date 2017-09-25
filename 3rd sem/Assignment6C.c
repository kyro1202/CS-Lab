/*SHASHANK SAXENA 
  1601CS42
  OBJECTIVE : To distribute a set into two disjoint subsets evenly*/
#include <stdio.h>
#include <stdlib.h>
#define inf 1e9//max value
int n;
int sum = 0;
int elements[1000];//to store the main set
int dp[10000];//to store the sum obtainable
int sol[10000];//for reconstruction of path
int diff = inf;
int func(const void * a, const void * b)//to sort the set
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
	printf("Enter the number of elements - "); scanf("%d", &n);
	int i,j;
	printf("Enter the elements - ");
	for(i = 0 ; i < n ; i++)
	{	
		scanf("%d", &elements[i]);
		sum += elements[i];//to store the value of maximum obtainable sum taking every element exacly once
	}
	qsort(elements,n,sizeof(int),func);//sorting the set
	for(i = 0 ; i < 10000 ; i++)//initialising the dp
		dp[i] = -1;
	dp[0] = 0;//0 is obtainable (empty set)
	int rem[1000]; int ind = 0;
	for(i = 0 ; i < n ; i++)
	{
		ind = 0;
		for(j = elements[i] ; j <= sum ; j++)
		{
			if(dp[j-elements[i]] != -1 && dp[j] != 1)//if we can obtain sum of 'x' and we have element 'y' then we can obtain sum of 'x'+'y'
			{
				rem[ind] = j;//to avoid repetetion
				ind++;
			}
		}
		for(j = 0 ; j < ind ; j++)
		{
			dp[rem[j]] = 1;//updating the dp
			sol[rem[j]] = i;//storing the index of the element used in obtaining this sum
		}
	}
	int ans;
	for(i = 0 ; i <= sum ; i++)//to check which subset gives the minimum difference of subset sum
	{
		if(dp[i] != -1)
		{
			if(abs(sum - 2*i) < diff)
			{
				ans = i;//storing the sum
				diff = sum - 2*i;
			}
		}
	}
	printf("Sum of set 1 = %d\nSum of set 2 = %d\n",ans,sum-ans);
	printf("Set 1 is - ");
	int x = ans;
	int index[100],mark = 0;
	while(x > 0)
	{
		printf("%d ", elements[sol[x]]);//printing the last element used to obtain sum x
		index[mark] = sol[x];//storing its index
		mark++;
		x -= elements[sol[x]];//moving a level up in the dp (next sum)
	}
	printf("\nSet 2 is - ");
	for(i = 0 ; i < n ; i++)
	{
		int found = 0;
		for(j = 0 ; j < mark ; j++)//to ignore the elements used in set1
		{
			if(i == index[j])
			{
				found = 1;
				break;
			}
		}
		if(found)
			continue;
		printf("%d ", elements[i]);//printing the set2 elements
	}
	printf("\n");
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
