/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To obtain the max and min digits of a number using recursion*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void count(int index,char s[],char* p,char* q)
{
	if(index >= strlen(s))//base condition
	return;
	if(s[index] > *p) *p = s[index];//updating max
	if(s[index] < *q) *q = s[index];//updating min
	count(index+1,s,p,q);//next inductive call
}
int main()
{
	char* num;
	num = (char*)malloc(100);//allocating memory
	printf("Enter the number - "); scanf("%s", num);	
	char max = '0',min = '9';	
	count(0,num,&max,&min);
	free(num);//freeing the memeory
	printf("%c and %c are smallest and largest digits present in the number respectively\n", min,max);
}
