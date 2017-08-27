/* SHASHANK SAXENA 1601CS42 03/21/2017
   Objective : To perform sort operation on linked lists */
#include <stdio.h>
#include <stdlib.h>

typedef struct node//structure of node
{
	char roll[10];
	int ht;
	int wt;
	struct node* nextht;
	struct node* nextwt;
}node;

typedef node* list;//list can be used in place of node*
void sortht(list L);//prototypes
void sortwt(list L);
node* head; node* head2;//declaring head(for height) and head2(for weight) globally
int n;//number of nodes

void swap(node* a,node* b,int option)//function to swap two pointers in the linked list
{
		
	if(option == 1)//then call for length and use head
	{
		node* curr1 = head; node* prev1 = NULL; node* curr2 = head; node* prev2 = NULL;
		while(curr1 != a)//to locate the particular pointer and corresponding previous
		{
			prev1 = curr1; curr1 = curr1->nextht;
		}
		while(curr2 != b)
		{
			prev2 = curr2; curr2=curr2->nextht;
		}
	if(prev1 != NULL)//if one of them is head
		prev1->nextht = curr2;
	else
		head = curr2;
	if(prev2 != NULL)
		prev2->nextht = curr1;
	else
		head = curr1;

	node* temp = curr2->nextht;//interchanging the next pointers(nextht for height and nextwt for weight)
	curr2->nextht = curr1->nextht;
	curr1->nextht = temp; }
	else//call for weight and to use head2 similar algo as above
	{ 
		node* curr1 = head2; node* prev1 = NULL; node* curr2 = head2; node* prev2 = NULL;
		 while(curr1 != a)//dealing with nextwt instead of nextht
	{
		prev1 = curr1; curr1=curr1->nextwt;
	}
	while(curr2 != b)
	{
		prev2 = curr2; curr2=curr2->nextwt;
	}
	if(prev1 != NULL)
		prev1->nextwt = curr2;
	else
		head2 = curr2;
	if(prev2 != NULL)
		prev2->nextwt = curr1;
	else
		head2 = curr1;

	node* temp = curr2->nextwt;
	curr2->nextwt = curr1->nextwt;
	curr1->nextwt = temp;  }
}

void printNameList(list L,int option)//calls function according to the option 
{
	if(option == 1)
		sortht( L );
	if(option == 2)
		sortwt( L );
}

void sortht(list L)//sort algo (bubble sort)
{
	int i = 0; node* curr2;
	while(i < n-1)//after each turn the smallest ht will be put at the end of the list
	{
		curr2 = head; 
		while(curr2->nextht != NULL)
		{
			if(curr2->ht < curr2->nextht->ht)
			{
				swap(curr2,curr2->nextht,1);//swapping pointers if ht is less than ht of next
			}
			else
			{
				curr2= curr2->nextht;//traversing otherwise
			}
		}
		i++;
	}
	node* curr = head;
	printf("Sort using height : \n");//printing list
	while(curr->nextht != NULL)
	{
		printf("%s,", curr->roll); curr=curr->nextht;
	}
	printf("%s\n", curr->roll);
}

void sortwt(list L)//similar to sortwt but uses head2 and nextwt
{
	int i = 0; node* curr2;
	while(i < n-1)
	{
		curr2 = head2;
		while(curr2->nextwt != NULL)
		{
			if(curr2->wt < curr2->nextwt->wt)
			{
				swap(curr2,curr2->nextwt,2);
			}
			else
			{
				curr2 = curr2->nextwt;
			}
		}
		i++;
	}
	node* curr = head2;
	printf("Sort using weight :\n");
	while(curr->nextwt != NULL)
	{
		printf("%s,", curr->roll); curr=curr->nextwt;
	}
	printf("%s\n", curr->roll);
}

int main()
{
	scanf("%d%*c", &n); int i = 0;
	head = NULL; node* curr = head;
	while(i < n)
	{
		node* p ;
		p = (node*)malloc(sizeof(node));
		scanf("%*c%[^\"]%*c%d%d%*c", p->roll,&p->ht,&p->wt);//scans input till ' " ' and puts it in roll scans ht and wt normally
		if(i == 0)//for assigning head
		{
			head = p;
			curr = p;
		}
		else//traversing curr pointer
		{
			curr->nextht = p; curr->nextwt = p;
			curr = p;
		}
		if(i == n-1)//for assigning NULL to last node
		{
			p->nextht = NULL;
			p->nextwt = NULL;
		}
		i++;
	}
	head2 = head;
	//printNameList can be called with option as given by user hence making it user friendly
	printNameList(head,1);//calling function
	printNameList(head2,2);

	return 0;
}
	 

		

				
















