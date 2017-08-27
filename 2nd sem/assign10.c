/* SHASHANK SAXENA 1601CS42 28/03/2017
   Objective : To perform basic arithmetic operations on big integers using linked list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node//structure of a node 
{
	int data;
	struct node* leftLink;
	struct node* rightLink;
}node;

node* get_int(void)//finction to get number from the user
{
	node* header1;int checkneg = 0;//checkneg is for checking whether the num is negative or not
	char* num1 = (char*)malloc(1000*sizeof(char));
	printf("Enter the number : ");
	scanf("%s", num1); int m;
	if(num1[0] == '-')//for negative integers
	{
		checkneg = 1;
		for(m = 0 ; m < strlen(num1) - 1 ; m++)//shifting string
		{
			num1[m] = num1[m+1];
		}
		num1[strlen(num1)-1] = '\0';	
	}
	header1 = (node*)malloc(sizeof(node));
	header1->data = (strlen(num1) % 5 == 0) ? strlen(num1)/5 : strlen(num1)/5 + 1;//appropriate number of nodes required
	node* curr = header1;
	int i,k,j = strlen(num1) - 5,prevmax = strlen(num1);
	for(i = 0 ; i < header1->data ; i++)
	{
		if(strlen(num1) < 6)//if only one node is required
		{
			node* p = (node*)malloc(sizeof(node));
			p->data = atoi(num1);
			curr->rightLink = p; p->leftLink = curr; curr = curr->rightLink;
			break;
		}	
		node* p = (node*)malloc(sizeof(node));
		char* temp = (char*)malloc(sizeof(char)*5); int index  = 0;
		if( i == header1->data - 1)//for the last node
		{
			int size;
			if(strlen(num1)%5 == 0)
				size = 5;
			else
				size = strlen(num1)%5;	
			char* temp2 = (char*)malloc(sizeof(char)*size);
			for(k = 0 ; k < size ; k++)
			{
				temp2[index] = num1[k];
				index++;
			}
			p->data = atoi(temp2); free(temp2);
			curr->rightLink = p; p->leftLink = curr; curr = curr->rightLink;
			index = 0;
			break;
		}		
		while(j < prevmax && i != header1->data - 1)//copying values from string to temp
		{
			temp[index] = num1[j];
			j++; index++;
		}
		prevmax = j - 5;
		j = j - 10;
		p->data = atoi(temp);//temp to node
		free(temp);
		curr->rightLink = p;//proper connections in a linked list
		p->leftLink = curr;
		curr = curr->rightLink;
	}
	curr->rightLink = header1; header1->leftLink = curr;
	
	if(checkneg)//if num is negative 
		header1->data *= -1;

	return header1;//returns header pointer	
}

int num_digits(int a)//function to calculate number of digits in a int using basic mathematics
{
	if(a / 1 == 0)
		return 0;
	else if(a / 10 == 0)
		return 1;	
	else if(a / 100 == 0)
		return 2;	
	else if(a / 1000 == 0)
		return 3;	
	else if(a / 10000 == 0)
		return 4;
	else if(a / 100000 == 0)
		return 5;		
}

void sub(node* h1,char* s1,node* h2,char* s2);//prototypes
int compare(node* h1,char* s1,node* h2,char* s2);

void add(node* h1,char* s1,node* h2,char* s2)//function to add numbers
{
	int i = 0,j; node* curr; node* curr1 = h1->rightLink; node* curr2 = h2->rightLink;int check = 0;
	if((h1->data)*(h2->data) < 0)//if polarities are inverse we call Subtraction function
	{	check = compare(h1,s1,h2,s2);
		if(check == 1)
		{	h2->data *= -1; sub(h1,s1,h2,s2);	}
		else
		{	h1->data *= -1; sub(h2,s2,h1,s1);	}
		return; }
	int a,b;
	node* hs = (node*)malloc(sizeof(node));
	curr = hs;
	while(i < abs(h1->data) || i < abs(h2->data) )
	{
		node* p = (node*)malloc(sizeof(node));
		if(curr1 != h1)//a gets the value in the node
		{	a = curr1->data; curr1 = curr1->rightLink; }
		else
			a = 0;// if repeated a = 0	
		if(curr2 != h2)//same as a
		{	b = curr2->data; curr2 = curr2->rightLink; }
		else
			b = 0;
		p->data = a + b;//direct addition of a and b to a new node
		curr->rightLink = p; p->leftLink = curr; curr = curr->rightLink;
		i++;
	}
	curr->rightLink = hs; hs->leftLink = curr;
	curr = hs->rightLink;
	while(curr->rightLink != hs)
	{
		if( curr->data / 100000 != 0)//if data overflows
		{
			curr->rightLink->data += curr->data/100000;//carry forward
			curr->data -= (curr->data/100000)*100000;//new data in the node
		}
		curr = curr->rightLink;
	}
	curr = hs->leftLink;
	
	if( h1->data < 0 && h2->data < 0)//printing sum
		printf("-");//for negative answer
	while(curr != hs)
	{
		i = num_digits(curr->data);
		for(j = 0 ; j < 5 - i ; j++)
			printf("0");
		printf("%d ", curr->data);
		curr = curr->leftLink;
	}
	printf("\n");
}

void sub(node* h1,char* s1,node* h2,char* s2)//function for subtraction h1 - h2
{
	int i = 0,j,check = 0; node* curr; node* curr1 = h1->rightLink; node* curr2 = h2->rightLink;
	check = compare(h1,s1,h2,s2);
	if(!check)
	{
		printf("0\n"); return;
	}

	if( (h1->data)*(h2->data) < 0 )//if polarities are reverse calling addition
	{	
		if(check == 1)
		{	h2->data *= -1; add(h1,s1,h2,s2); return;   }
		else
		{	h2->data *= -1; add(h1,s1,h2,s2); return;	}
	}
	node* hs = (node*)malloc(sizeof(node));
	curr = hs;
	int a,b;
	int temp1 = h1->data,temp2 = h2->data;//temp will store the sign of the number
	if(temp1 < 0)
		h1->data *= -1;//to compare the absolute values of numbers
	if(temp2 < 0)
		h2->data *= -1;	
	check = compare(h1,s1,h2,s2);
	if(check == 0)
	{	printf("0"); return ;}
	else if(check == 1)
	{
		while( i < abs(h1->data) || i < abs(h2->data) )
		{
			node* p = (node*)malloc(sizeof(node));
			if(curr1 != h1)//similar to that in addition
			{	a = curr1->data; curr1 = curr1->rightLink; }
			else
				a = 0;	
			if(curr2 != h2)
			{	b = curr2->data; curr2 = curr2->rightLink; }
			else
				b = 0;
			if( a - b < 0)//if a < b
			{
				curr1->data -= 1;//borrow from nearby node
				a += 100000;
			}
			p->data = a - b;
			curr->rightLink = p; p->leftLink = curr; curr = curr->rightLink;
			i++;	
		}
		curr->rightLink = hs; hs->leftLink = curr;
	}
	else if(check == 2)//if h2 > h1
	{
		while( i < abs(h1->data) || i < abs(h2->data) )
		{
			node* p = (node*)malloc(sizeof(node));
			if(curr1 != h1)
			{	a = curr1->data; curr1 = curr1->rightLink; }
			else
				a = 0;	
			if(curr2 != h2)
			{	b = curr2->data; curr2 = curr2->rightLink; }
			else
				b = 0;
			if( b - a < 0)
			{
				curr2->data -= 1;
				b += 100000;
			}
			p->data = b - a;
			curr->rightLink = p; p->leftLink = curr; curr = curr->rightLink;
			i++;	
		}
		curr->rightLink = hs; hs->leftLink = curr;
	}
	curr = hs->leftLink;
	if(temp1 > 0 && temp2 > 0)//checking for appropriate sign of the difference
	{
		if(check == 2)
			printf("-");
	}
	if(temp1 < 0 && temp2 < 0)
	{
		if(check == 1)
			printf("-");
	}
	while(curr != hs)//printing result
	{
		i = num_digits(curr->data);
		for(j = 0 ; j < 5 - i ; j++)
			printf("0");
		printf("%d ", curr->data);
		curr = curr->leftLink;
	}
	printf("\n");		
}	
int compare(node* h1,char* s1,node* h2,char* s2)//to compare
{
	int i;
	if( (h1->data) > (h2->data) )//comparing size
	{	return 1; }
	else if( (h1->data) < (h2->data) )
	{	return 2; }
	node* curr = h1->leftLink; node* curr2 = h2->leftLink;
	while(curr != h1)//comparing individual nodes
	{
		if( curr->data > curr2->data )
			return ( (h1->data) < 0 ) ? 2 : 1 ;
		if( curr->data < curr2->data )
			return ( (h1->data) < 0 ) ? 1 : 2 ;
		curr = curr->leftLink;	curr2 = curr2->leftLink;
	}
	return 0;
}			

int main()
{
	node* header1; node* header2; char* num1; char* num2; int checkneg = 0;
	char choice = 'q';
	while(1)//a simple switch case statement
	{
		printf("Comparison(c) or Addition (a) or Subtraction (s) or Exit (x): "); 
		scanf("%c", &choice);
		switch(choice)
		{
		case 'c': header1 = get_int(); header2 = get_int();//asking for integers and calling various functions
				  checkneg = compare(header1,num1,header2,num2);
				  if(checkneg == 1)
				  printf("First number is larger\n");
				  else if(checkneg == 2)
				  printf("Second number is larger\n");
				  else
				  printf("Numbers are equal\n");
				  break;
		case 'a': header1 = get_int(); header2 = get_int(); printf("Sum is : \n");add(header1,num1,header2,num2); break;
		case 's': header1 = get_int(); header2 = get_int(); printf("Difference is : \n");sub(header1,num1,header2,num2);  break;
		case 'x': return 0;
		default : printf("Invalid choice. Try again !!"); break;
		}
		scanf("%*c");
	}	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
				
		
		
				
