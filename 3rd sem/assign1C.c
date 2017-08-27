/*SHASHANK SAXENA 
  1601CS42
  OBJECTIVE - To make a program work the aid of library ! */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//global variables - to be used in various functions
int mark;
char* sv;
//structure of a single book
typedef struct node
{
	int S_No;
	char* title; 
	char* author; 
	char* status;
}book;
//array of books - shelf
book shelf[100000];
//function to scan a string till new line character is hit
void scan(char t)
{
	int pos = 0;
	char* tt; char* ta;
	char temp = 'a';
	//allocating app. memory
	tt = (char*)malloc(100);
	ta = (char*)malloc(100);
	sv = (char*)malloc(100);
	if(t == 't')//if the call is for title
	{
		while(temp != '\n')
		{
			temp = getchar();
			if(temp == '\n')
			break;
			tt[pos] = temp;
			pos++;
		}
		shelf[mark].title = tt;
	}
	else if(t == 'a')//if the call is for author
	{
		while(temp != '\n')
		{
			temp = getchar();
			if(temp == '\n')
			break;
			ta[pos] = temp;
			pos++;
		}
		shelf[mark].author = ta;
	}
	else if(t == 'v')//if the call is for view
	{
		while(temp != '\n')
		{
			temp = getchar();
			if(temp == '\n')
			break;
			sv[pos] = temp;
			pos++;
		}
	}
}
//function to make new entry at the shelf
//mark keeps record of the size of shelf	
void makenew()
{
	//allocating memory
	shelf[mark].title = (char*)malloc(100);
	shelf[mark].author = (char*)malloc(100);
	shelf[mark].status = (char*)malloc(100);
	int ts;
	printf("Enter the serial no. - "); scanf("%d", &ts);
	printf("\nEnter the title - "); scanf("%*c"); scan('t');
	printf("\nEnter the author - "); scan('a');
	shelf[mark].S_No = ts; shelf[mark].status = "Not Issued";
	mark++;//updating mark
	printf("New entry successful !!\n");
	return;
}
void view1()//view by serial no.
{
	int s; 
	printf("Enter serial no. - "); scanf("%d", &s);
	int i;	
	for( i = 0 ; i < mark ; i++)
	{
		if(shelf[i].S_No == s)
		{
			printf("Title = %s\nAuthor = %s\nStatus = %s\n", shelf[i].title , shelf[i].author , shelf[i].status);
			return;
		}
	}
	printf("Error !! - Serial no. not found !!!!\n");//error message
}
void view2()//view by title
{
	sv = "";//to clear sv 
	int print = 0;//to reset the printing flag 
	printf("Enter title - "); scanf("%*c");scan('v');
	int i;
	for( i = 0 ; i < mark ; i++)
	{
		if(strcmp(shelf[i].title,sv)==0)
		{
			printf("Serial no. = %d\nAuthor = %s\nStatus = %s\n", shelf[i].S_No , shelf[i].author , shelf[i].status);
			print = 1;
		}
	}
	if(print == 0)
	printf("Error - No book with this title\n");//error message
}
void view3()//view by author
{
	sv = ""; int print = 0;
	printf("Enter author - "); scanf("%*c");scan('v');
	int i;	
	for( i = 0 ; i < mark ; i++)
	{
		if(strcmp(shelf[i].author,sv) == 0)
		{
			printf("Title = %s\nSerial = %d\nStatus = %s\n", shelf[i].title , shelf[i].S_No , shelf[i].status);
			print = 1;
		}
	}
	if(print == 0)
	printf("Error - No book of this author\n");//error message
}
void view()//function to scan the input and then call appropriate function
{
	int c;
	printf("by serial no. - choose 1\nby title - choose 2\nby author - choose 3\nexit - 0\n");
	while(1)	
	{	
		printf("Enter your choice - "); scanf("%d", &c);
		switch(c)
		{
			case 1: 
				view1();
				return;
			case 2:
				view2();
				return;
			case 3:
				view3();
				return;
			case 0:
				return;
			default:
				printf("Wrong choice, Try again "); //error message
		}
	}
}
void show()//function to show list of available books
{
	int i;int print = 0;
	for(i = 0 ; i < mark ; i++)
	{
		if(strcmp(shelf[i].status,"Not Issued") == 0)//if book is not issued
		{	printf("Title = %s\nSerial No. = %d\nAuthor = %s\n%s\n", shelf[i].title , shelf[i].S_No , shelf[i].author,shelf[i].status); print = 1; }
	}
	if(print == 0)
		printf("Sorry , No books at the shelf !!\n");//error message
}
void issue()//function to issue
{
	int s;
	printf("Enter the serial no. - "); scanf("%d", &s);
	int i;
	for(i = 0 ; i < mark ; i++)
	{
		if(shelf[i].S_No == s)
		{
			shelf[i].status = "Issued";
			return;
		}
	}
	printf("No book of this serial no.\n");
}
void returnbook()//function to return a book
{
	int s;
	printf("Enter the serial no. - "); scanf("%d", &s);
	int i;
	for(i = 0 ; i < mark ; i++)
	{
		if(shelf[i].S_No == s)
		{
			shelf[i].status = "Not Issued";
			return;
		}
	}
	printf("No book of this serial no.\n");
}		
int main()//asks for the choice and calls function according to that
{	
	mark = 0;
	char c = 'a';
	while(1)
	{
		printf("a. Make a new entry of book\nb. View Details of a book\nc. Show list of available books\nd. Issue a book\ne. Return a book\nf. Exit\n");
		printf("Enter your choice\n");
		scanf("\n%c", &c);
		if(c == 'a')
		{
			makenew();
		}
		else if(c == 'b')
		{
			view(); 
		}
		else if(c == 'c')
		{
			show(); 
		}
		else if(c == 'd')
		{
			issue(); 
		}
		else if(c == 'e')
		{
			returnbook(); 
		}
		else if(c == 'f')
		{
			break;
		}
		else
		{
			printf("Wrong choice !!! Try again\n");
		}		
	}
}	
