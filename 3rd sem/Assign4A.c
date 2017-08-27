/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To implement priority queue*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char doc[30];//to store the doctor's name

typedef struct node//structure of one patient
{
	char name[30];//name of the patient
	int sim;//similarity with the doctor's name
	float time;//time of arrival
}node;

node pri_queue[50],arr[50];//priority queue and normal array
int curr_size = 0;//stores the size of priority queue
int compare(const void* a,const void* b)//function for sorting the array according to the arrival time
{
	const node *ap = a;
    const node *bp = b;
    if( ap->time < bp->time )
        return -1;
    else if( ap->time > bp->time )
        return 1;
    else
        return 0;
}
int res(char* a,char* b)//to compare similarities with the doctor's name
{
	int i,val = 0;
	int count1[26] = {0},count2[26] = {0};
	for(i = 0 ; i < strlen(a) ; i++)
	{
		int temp = a[i];
		if(a[i] < 'a')//if a[i] is upper case
			temp = a[i] + 'a'-'A';
		count1[temp-'a']++;//count of that alphabet is incremented
	}
	for(i = 0 ; i < strlen(b) ; i++)//same as string a
	{
		int temp = b[i];
		if(b[i] < 'a')
			temp = b[i] + 'a'-'A';
		count2[temp-'a']++;
	}
	for(i = 0 ; i < 26 ; i++)
	{
		if(count1[i] && count2[i])//if alphabet is present in both strings
			val++;//val is incremented
	}
	return val;
}
void percup()//compares the curr node with its parent to satisfy the heap property
{
	int i = curr_size;
	while(i > 0)
	{
		if(pri_queue[i].sim > pri_queue[i/2].sim)//if heap property is not satisfied
		{
			node temp = pri_queue[i];//swapped
			pri_queue[i] = pri_queue[i/2];
			pri_queue[i/2] = temp;
		}
		else if(pri_queue[i].sim == pri_queue[i/2].sim)
		{
			if(pri_queue[i].time < pri_queue[i/2].time)//sorting wrt time of arrival
			{
				node temp2 = pri_queue[i];
				pri_queue[i] = pri_queue[i/2];
				pri_queue[i/2] = temp2;
			}
		}
		i = i/2;
	}
}
void insert(node temp)//inserting a node in the priority queue and calling percup
{
	temp.sim = res(temp.name,doc);
	pri_queue[curr_size] = temp;
	percup();
}
int max(int test)//returns the max of the children of a node  
{
	if(test*2 + 2 >= curr_size)
		return test*2 + 1;
	if(pri_queue[test*2+1].sim > pri_queue[test*2+2].sim)
		return test*2 + 1;
	else
		return test*2 + 2;
}
void percd()//compares the node with its maximum child to satisfy heap property
{
	int i = 0;
	while(i < curr_size/2)
	{
		int max_child = max(i);
		if(pri_queue[i].sim < pri_queue[max_child].sim)//if heap property is not satisfied
		{
			node temp = pri_queue[i];//swapping with the max child(max child is already greater than its sibling)
			pri_queue[i] = pri_queue[max_child];
			pri_queue[max_child] = temp;
		}
		else if(pri_queue[i].sim == pri_queue[max_child].sim)
		{
			if(pri_queue[i].time > pri_queue[max_child].sim)//according to the time of arrival
			{
				node temp = pri_queue[i];
				pri_queue[i] = pri_queue[max_child];
				pri_queue[max_child] = temp;
			}
		}
		i = max_child;
	}
}
node extract()//returns max node
{
	node val = pri_queue[0];
	pri_queue[0] = pri_queue[curr_size-1];//last node is now at the 0 position
	curr_size--;//size of priority queue is decreased
	percd();
	return val;//returns the node
}
int main()
{
	printf("Enter the doctor's name - "); scanf("%s", doc);
	int n;
	printf("Enter the number of patients - "); scanf("%d", &n);
	int i;
	int mark = 0;
	for(i = 0 ; i < n ; i++)
	{
		node temp;
		printf("Enter the name of the patient - "); scanf("%s", temp.name);
		printf("Enter the arrival time (in 24 hour format) - "); scanf("%f", &temp.time);
		if(temp.time <= 8.00)//if time of arrival is before 8 am then it is inserted in the priority queue
		{
			insert(temp);
			curr_size++;
		}
		else//else inserted in the array arr
		{
			arr[mark] = temp;
			mark++;
		}
	}
	printf("The order in which the patients visited the doctor is -\n");
	while(curr_size > 0)//printing the priority queue
	{
		node res = extract();
		printf("%s who arrived at %.2f\n", res.name,res.time);
	}
	qsort(arr,mark,sizeof(node),compare);//sorting the array wrt to time of arrival of patients
	for(i = 0 ; i < mark ; i++)//printing the array
	{
		printf("%s who arrived at %.2f\n", arr[i].name,arr[i].time);
	}
}	 
