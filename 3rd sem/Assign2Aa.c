/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To Count the number of odd digits using recursion*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void count(int index,char s[],int* p)
{
	if(index > strlen(s))//base condition
	return;
	if((int)s[index]%2 == 1)
	*p = *p + 1;//increasing tot
	count(index+1,s,p);//next inductive call
}
int main()
{
	char* num;
	num = (char*)malloc(100);//allocating memory
	printf("Enter the number - "); scanf("%s", num);	
	int tot = 0;	
	count(0,num,&tot);
	free(num);//freeing the memeory
	printf("%d odd digits are present in the number\n", tot);
}
