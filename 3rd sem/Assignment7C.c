/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE - To get familiar with the concepts of dynamic programming*/
#include <stdio.h>
#include <stdlib.h>

int n;
int dp[100000];//to store the previous calculated values
int min(int a,int b)//function to return the minimum of two
{
    return (a < b) ? a : b ; 
}
int ways(int left)
{
    if(left <= 0)//if it is impossible return very large value
        return -1000000;
    if(left == 1)//no further action is needed
        return 0;
    if(dp[left] != -1)//if it is repeated subproblem
        return dp[left];
    int ret = 1000000;//to temporarily store the ans
    if(left%2 == 0)
        ret = min(ret,ways(left/2) + 1);
    if(left%3 == 0)
        ret = min(ret,ways(left/3) + 1);
    if(left%5 == 0)
        ret = min(ret,ways(left/5) + 1);
    if(left%7 == 0)
        ret = min(ret,ways(left/7) + 1);
    ret = min(ret,ways(left-1) + 1);
    return dp[left] = ret;//updating the dp table and returning the ans
}
int main()
{
    printf("Enter the number - "); scanf("%d", &n);
    int i;
    for(i = 0 ; i <= n ; i++)//initialising the dp table
        dp[i] = -1;
    printf("Number of steps used in reduction of %d are %d\n", n, ways(n));
}