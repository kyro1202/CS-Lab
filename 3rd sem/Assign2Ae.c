/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To compute the recursice sum of a given number using recursion*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rs(int index,char t[],int* q)//recursive function to calculate the sum of all digits 
{
	if(index >= strlen(t))
	return;
	*q = *q + t[index] - '0';
	rs(index+1,t,q);
}
void count(char s[],int* p)
{
	if(strlen(s) == 1)//base case
	return;	
	*p = 0;//resetting the value of sum
	rs(0,s,p);//*p contains the value of sum of all digits
	sprintf(s,"%d",*p);//writing decimal into string
	printf("%s\n", s);
	count(s,p);//calling the function again
}
int main()
{
	char* num;
	num = (char*)malloc(1000000);//allocating memory
	printf("Enter the number - "); scanf("%s", num);
	if(strlen(num) == 1)
	{
		printf("%c is the recursive sum of the given number\n", num[0]);
		return 0;
	}
	int sum = 0;		
	count(num,&sum);//passing pointer of sum to the function
	free(num);//freeing the memeory
	printf("%d is the recursive sum of the given number\n", sum);
}
