/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To convert a given number into its binary representation*/
#include <stdio.h>
#include <stdlib.h>
void binary(int a[],int* p,long long int* n)//function to convert a number in binary
{
	if(*n == 0)//base case
	return;
	a[*p] = (*n)%2; *n /= 2;//if num is odd 1 is inserted in the array otherwise 0 is inserted
	*p = *p + 1;//pos at which 1 || 0 must be inserted is increased	
	binary(a,p,n);//recursive call
}
int main()
{
	long long int num; printf("Enter the number - "); scanf("%lld", &num);
	if(num == 0)
	{
		printf("Binary representation of the number is - 0\n"); return;
	}
	num = (num < 0) ? num * -1 : num ;	
	int s[100]; int pos = 0;
	binary(s,&pos,&num);
	printf("Binary representation of the number is - ");
	int i;
	for(i = pos - 1 ; i >= 0 ; i--)//to print the binary represenation
		printf("%d", s[i]);
	printf("\n");
}
