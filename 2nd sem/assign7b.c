/* SHASHANK SAXENA 1601CS42 07/03/2017
   OBJECTIVE : To store strings in 2d dynamic array */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//function for qsort
int comparator(const void* p, const void* q)
{
	//typecasting the pointers p and q to be used as strings
	return strcmp( *(char* const*)p, *(char* const*)q ) ;
}

int main()
{
	int n; scanf("%d", &n);
	//allocating a memory for a string of strings 'char**'
	char** table = (char**)malloc(n*sizeof(char*));
	int i;//loop variable	
	//to scan input	
	for(i = 0 ; i < n ; i++)
	{
		//declaring a temporary array 's'		
		char* s = (char*)malloc(25*sizeof(char));
		//allocating memory space in table to store s 		
		table[i] = (char*)malloc( (strlen(s) + 1)*sizeof(char) );//1 added to store '\0'
		scanf("%s", s);
		strcpy(table[i],s);
		table[i][strlen(s)] = '\0';
		free(s);// to free s
	}
	
	//to sort
	qsort(table,n,sizeof(char*),comparator);
	
	printf("\n");
	//printing the rows of table	
	for(i = 0 ; i < n ; i++)
	{
		printf("%s\n", table[i]);
	}
	printf("\n");
	//to free the memory
	for(i = 0 ; i < n ; i++ )
	{
		free(table[i]);
	}
}
		
