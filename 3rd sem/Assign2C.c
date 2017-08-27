/*SHASHANK SAXENA
  1601CS42*/
#include <stdio.h>
#include <stdlib.h>

int inp,count;//global variables

void recurse()
{
	if(inp%2 == 0)//if inp is even
	inp /= 2;
	else//else inp is odd
	inp = 3*inp + 1;
	count++;//increasing count of number of steps
	if(inp == 1)//base condition to return
		return;
	printf("Next value is %d\n", inp);
	recurse();
}
int main()
{
	count = 0;
	do//simple do while loop to check if inp is valid or not
	{
		printf("Enter the input value - "); scanf("%d", &inp);
		if(inp < 1)
			printf("Error !!! Try again\n");
	}while(inp < 1);
	printf("Initial value is %d\n", inp);
	if(inp == 1)
	{
		printf("Final value 1, number of steps 0\n"); return 0;
	}
	recurse();
	printf("Final value 1, number of steps %d\n", count);
}	
