/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE - To compute the maximum sum of elements with no two being consecutive !*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//function to return maximum of the two
int max(int a,int b)
{
    return ( a > b ) ? a : b ;
}
//recursive function to determine the max digit in the ans
char largedigit(char str[],int index)
{
    int temp = index;
    if((strlen(str) - temp) == 1)//base condition
        return str[temp];//returning that character if size is 1 i.e only one character is left
    /*recursion step : checks if the current character is greater than the max char of the string ahead, if not it calls the 
      function on the string again with increased index*/
    return ( str[temp] >= largedigit(str,++temp)) ? str[index] : largedigit(str,temp);
}
int main()
{
    int n; printf("Enter the no. of boxes - "); scanf("%d", &n); printf("\n");
    int boxes[n];
    int i;
    char s[100];
    printf("Enter the no. of chocolates in each box ex. (7 8 15 1 4 23) - ");
    for(i = 0 ; i < n ; i++)
        scanf("%d", &boxes[i]);
    printf("\n");
    int dp[n]; dp[0] = boxes[0];//base case for the dp table if only one element is there, it has to be selected
    if(n >= 2)
    {
        dp[1] = max(boxes[0],boxes[1]);//if two elements are there max of the two must be selected
        for(i = 2 ; i < n ; i++)
        {
            dp[i] = max(dp[i-2] + boxes[i],dp[i-1]);//for i^th index we cann't choose the (i-1)^th index so taking maximum of choosing(i-1)^th element and i^th element and choosing (i-1)^th element 
        }
    }
    int ans = ( n == 1 ) ? dp[0] : max(dp[n-2],dp[n-1]);
    printf("Max Chocolates = %d\n", ans);
    sprintf(s,"%d",ans);//converting ans into string to be passed on the function
    printf("Largest digit = %c\n", largedigit(s,0));
}