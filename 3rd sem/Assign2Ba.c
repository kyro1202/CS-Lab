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
	if((b - a + 1) < 3)//if size is less then 3
	{
		for(i = 0 ; i < (b-a+1) ; i++)//loop runs max 2 times
		{
			if(A[a+i] == key)
			{
				found = 1; pos = a+i; return;//if key is found return
			}
		}
	}
	else
	{
		int temp = (b-a+1)/3;//to store length of each segment
		temp = ((b-a+1)%3 == 0) ? temp - 1 : temp;//adjusting temp according to divisibility of size by 3
		int start = a; int end;
		for(start = a ; start < b+1 ; start += (temp+1))
		{
			if(found == 1)
			return;
			end = start + temp;
			end = (end <= b) ? end : b;//if end is greater than the array size
			search(start,end);
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
