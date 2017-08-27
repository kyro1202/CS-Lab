/* SHASHANK SAXENA 1601CS42 11/04/2017
   Objective : To construct binary tree from inorder and postorder */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;	

char* inorder; //global variables
char* postorder;
FILE* fo;//pointer to open output file

//initial input = 0 , index - 1 and index - 1
node* buildtree(int start,int end,int *postindex)
{
	if( start > end )//base case
		return NULL;
	node* p = (node*)malloc(sizeof(node));
	p->data = postorder[*postindex];//forming new node
	if( *postindex == -1 )//condition to check if tree can be made
	{
		printf("Tree can't be made\n");
		exit(0);
	}	
	(*postindex)--;//next recursive call will take second from right element in postorder
	if( start == end )//leaf node
		return p;
	int i = 0;
	while( inorder[i] != postorder[(*postindex)+1])//search for element in inorder
		i++;
	p->right = buildtree(i+1,end,postindex);//recursive call to build right and left sub tree of the node p
	p->left = buildtree(start,i-1,postindex);
	return p;		
}

void printpre(node* curr)//printing tree in fo along preorder
{
	if(curr == NULL)
		return;
		
	fprintf(fo,"%c ", curr->data);
		
	printpre(curr->left);
	printpre(curr->right);
}

int main()
{
	inorder = (char*)malloc(sizeof(char)*1001);//memory allocation
	postorder = (char*)malloc(sizeof(char)*1001);
	
	FILE* fp;//pointer to open file to read input
	fp = fopen("ipseq.txt","r");//opening file to read
	fo = fopen("1601CS42.txt","w");//opening file to print
	
	if(fp == NULL)//if file doesn't exist
	{
		printf("Error while opening the file.\n");
		return 1;
	}
	
	char temp = fgetc(fp); int index = 0;	
	while( temp != '\n')//till new line
	{
		inorder[index] = temp; index++;
		temp = fgetc(fp);
		if( temp == ' ')//to ignore ' ' character	
			temp = fgetc(fp);
	}
	index = 0; temp = fgetc(fp);//reasigning the value of index to zero
	while( temp != EOF )
	{		
		postorder[index] = temp; index++;
		temp = fgetc(fp);
		if( temp == ' ')
			temp = fgetc(fp);
	}
	index--;//decreasing index to ignore the last new line character in postorder string
	int  postindex = index - 1;
	node* root = buildtree(0,index-1,&postindex);
	
	printpre(root);
	fclose(fo); fclose(fp);//closing both files
	free(inorder); free(postorder);//to free the memory
}			
					
