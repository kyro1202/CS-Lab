/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To implement search by dividing the array into 3 parts*/
#include <stdio.h>
#include <stdlib.h>

int A[100000];//global variables
int n,key,found,pos;

void search(int a,int b)//search is performed between a and b both included
{
	int i;
	if(found == 1)//if key is already found, return
	return;
	if((b - a + 1) < 5)//if size is less then 5
	{		
		for(i = a ; i <= b ; i++)
		{		
			if(A[i] == key)
			{
				found = 1; pos = i; return;//if key is found, return
			}
		}
	}
	else
	{
		int temp = (b-a+1)/5;//length of first segment will be 2 times temp and rest will be in the second segment
		int start = a; int end;
		if(found != 1)
		{
			end = (a + 2*temp - 1)	< a ? a : (a + 2*temp - 1);//to check if end is out of bound		
			search(a,end);
		}
		if(found != 1)
		{
			end = (a + 2*temp) > b ? b : (a+2*temp);//to check if start is out of bound			
			search(end,b);
		}
	}
}
int main()
{
	printf("Enter the number of elements in the list - "); scanf("%d", &n);
	printf("\nEnter the elements in sorted order - ");
	int i;
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d", &A[i]);
	}
	found = 0;
	printf("\nEnter the element to be searched - "); scanf("%d", &key);
	search(0,n-1);//calling the search function
	if(found != 1)
	printf("List doesn't contain the key\n");
	else
	printf("Key found at index %d\n", pos);
}
