/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE - To implement an order n sorting algorithm*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int count[100000];
void initialise()//function to inititalise the count array
{
	int i;
	for(i = 0 ; i < 100000 ; i++)
	count[i]= 0;
}
typedef struct node//structure of a node for storing players information
{
	int runs;
	char name[20];
}player;
void countingsort(player* s)//counting sort algorithm
{
	initialise();
	player output[n];
	int i;
	for(i = 0 ; i < n ; i++)// O(n)
	{
		count[s[i].runs]++;
	}
	for(i = 1 ; i < 100000 ; i++)// constant time
	{
		count[i] += count[i-1];
	}
	for(i = n-1 ; i >= 0 ; i--)// O(n) loop from n-1 down to 0 to make stable sort
	{
		output[count[s[i].runs]-1] = s[i];
		count[s[i].runs]--;
	}
	for(i = 0 ; i < n ; i++)// O(n)
		s[i] = output[i];
}
void countingsortlex(player* s,int index)//counting sort for strings
{
	initialise();
	player output[n];
	int i;
	for(i = 0 ; i < n ; i++)
	{
		if(strlen(s[i].name) < index+1)//if the string is smaller then it has highest priority i.e. 64, 'A' = 65
			count[64]++;
		else
			count[(int)s[i].name[index]]++;
	}
	for(i = 1 ; i < 100000 ; i++)
	{
		count[i] += count[i-1];
	}
	for(i = n-1 ; i >= 0 ; i--)
	{
		if(strlen(s[i].name) < index+1)//output taken from count[64]
		{
			output[count[64]-1] = s[i];
			count[64]--;
		}
		else//output taken from the respective index
		{
			output[count[s[i].name[index]]-1] = s[i];
			count[s[i].name[index]]--;
		}
	}
	for(i = 0 ; i < n ; i++)
		s[i] = output[i];
}
void sortbyname(player* s,int len) // radix sort O(len*n) == O(n)
{
	int i;
	for(i = len-1 ; i >= 0 ; i--)// O(len) radix sort algorithm
	{
		countingsortlex(s,i);// O(n)
	}
}
void sortbyruns(player* r,int len)
{
	sortbyname(r,len);//sort by name O(n)
	countingsort(r);//counting sort O(n)
}
int main()
{
	printf("Enter the number of cricketers - "); scanf("%d", &n);
	int i;
	player list[n];
	int maxlen;
	printf("Enter the name of the player followed by his runs (separated by a space) -\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%s %d", list[i].name,&list[i].runs);
		if(strlen(list[i].name) > maxlen)
			maxlen = strlen(list[i].name);//to keep track of the maximum length of names
	}
	sortbyruns(list,maxlen); // overall complexity O(2*n) == O(n)
	printf("Players in the sorted order are -\n");
	for(i = 0 ; i < n ; i++)
		printf("%d %s\n", list[i].runs,list[i].name);
}
