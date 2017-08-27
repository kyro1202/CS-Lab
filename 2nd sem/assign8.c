/* SHASHANK SAXENA 1601CS42 14/03/2017
   Objective : TO GET FAMILIAR WITH LINKED LIST */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structing a node of the list
typedef struct node
{
	char roll[5];
	float cpi;
	float attendance;
	struct node* next;
}node;

//global declarartion of head
node* head;

//function to print list
void printlist()
{
	node* cursor;
	cursor = head;//cursor gets the value of head
	printf("The list of elements in the linked list is\n");
	while(cursor->next != NULL)//traversing cursor to seconf last node to ignore the last comma
	{
		printf("<%s, %f, %f>,", (cursor->roll) , (*cursor).cpi , (*cursor).attendance );
		cursor = cursor->next;
	}
	printf("<%s, %f, %f>", (cursor->roll) , (*cursor).cpi , (*cursor).attendance );//printing the last node	
}	

//function to swap nodes
void swap(char* s,char* t)
{

	node* cursor = head; node* prev = NULL; 
	while(cursor != NULL && strcmp(cursor->roll,s) != 0)
	{
		prev = cursor;
		cursor = cursor->next;
	}
	//cursor points to node containing s and prev to a node before it	
	node* temp ;
	
	node* cursor2 = head; node* prev2 = NULL;

	while(cursor != NULL && strcmp(cursor2->roll,t) != 0)
	{
		prev2 = cursor2;	
		cursor2 = cursor2->next;
	}
	//cursor2 points to node containing t and prev2 to a node before it

	if(cursor == NULL || cursor2 == NULL)//elements not in the list
	{
		printf("Number not in the list\n");
		return;
	}
	
	//cursor == head
	if(prev != NULL)
		prev->next = cursor2;
	else
		head = cursor2;//the new head is cursor2

	//cursor2 == head	
	if(prev2 != NULL)
		prev2->next = cursor;
	else
		head = cursor;//the new head is cursor

	temp = cursor->next; cursor->next = cursor2->next; cursor2->next = temp;//interchanging the next pointers of cursor and cursor2		
}

//function to reverse a linked list
void reverse(int n)
{
	int i;
	node* cursor;
	node* temp1; node* temp2;
	for(i = 0 ; i < n/2 ; i++)
	{
		int j = 0,k = 0;
		cursor = head;
		while(j < i)
		{
			cursor = cursor->next; j++;
		}
		//now cursor has the pointer to i'th node
		temp1 = cursor;
		cursor = head;//for second node cursor must be rassigned the value head
		while(k < n - i - 1)
		{
			cursor = cursor->next; k++;
		}
		temp2 = cursor;//giving value of count - i'th node to temp2
		swap(temp1->roll,temp2->roll);//swapping i'th and count - i'th nodes
	}
	printf("Reverse operation is successfully done. \n");
}

int main()
{	
	head = NULL;node* crr;
	char c;
	int count = 0;

	node* p = (node*)malloc(sizeof(node));//allocating sufficient memory to p
	head = p; crr = p;	 		

	//to scan values
	printf("Enter the elemnts of the node\nEnter the roll = "); scanf("%s", p->roll); p->roll[4] = '\0';
	printf("Enter the cpi = "); scanf("%f", &p->cpi);
	printf("Enter the attendance = "); scanf("%f", &p->attendance);
	printf("\nAny more node (y/n): "); scanf("%*c%c", &c); printf("\n");
	count++;//count to calculate total no. of nodes	

	while(c == 'y')
	{
		node* temp = (node*)malloc(sizeof(node));
		printf("Enter the elemnts of the node\nEnter the roll = "); scanf("%s", temp->roll); temp->roll[4] = '\0';
		printf("Enter the cpi = "); scanf("%f", &temp->cpi);
		printf("Enter the attendance = "); scanf("%f", &temp->attendance);
		printf("\nAny more node (y/n): "); scanf("%*c%c", &c); printf("\n");
		count++;
		crr->next = temp;//traersing crr to next
		crr = temp;
		if(c != 'y' && c != 'n')
		{
			printf("Invalid command\n"); return 1;
		}
	}

	crr->next = NULL;//to denote the last node
	
	int action;

	do//simple do while loop which calls various functions according to the choice made
	{
		printf("Enter 1 for print,2 for swap,3 for reverse,0 for exit : "); scanf("%d", &action);

		if(action == 1)
			printlist();
		else if(action == 2)
		{
			char s[5],t[5];
			printf("Enter roll of first node to be swapped: "); scanf("%s", s);
			printf("Enter roll of second node to be swapped: "); scanf("%*c%s", t);
			swap(s,t);
			printf("Swap successful\n");
		}
		else if(action == 3)
			reverse(count);
		else if(action != 0)//if the input given is niether 1 nor 2,3 or 0
		{
			printf("Invalid command\n"); return 2;
		}		
		printf("\n");
	}while(action != 0);
	printf("Program ends.\n");
}







