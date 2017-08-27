/* SHASHANK SAXENA 1601CS42 04/04/2017
   Objective: To get acquainted with binary tree*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node//structure of a node
{
	int data;
	struct node* left ;
	struct node* right ;
	struct node* parent ;
}node;

node* root = NULL;//global declaration of root
int min_level = 100001,max_level = 0,min_leaf = 100001,max_leaf = 0;//global declarations for calculation of min and max leaf

node* search(int val,node* curr,node* prev)//function to search parent of a given value
{
	if(curr == NULL)
		return prev;
	if(curr->data < val)
	{
		prev = curr;
		curr = curr->right; search(val,curr,prev);
	}
	else
	{
		prev = curr;
		curr = curr->left; search(val,curr,prev);
	}			
}

void printparent(node* curr)//function to print parents of given node
{
	if(curr == NULL)
		return;
	
	if(curr == root)
	printf("%d------No parent\n", curr->data);
	else
	printf("%d------%d\n", curr->data, curr->parent->data);
	
	printparent(curr->left);//to traverse the cursor
	printparent(curr->right);
}	

int level(node* ptr)//to calculate the level of a given node
{
	node* temp = ptr;
	int l = 0;
	while(temp->parent != NULL)//untill it reaches the root node
	{
		l++; temp = temp->parent;
	}
	return l;	
}

void findleaf(node* curr)
{

	if(curr == NULL)
		return;
		
	if(curr->left == NULL && curr->right == NULL)//if curr represents a leaf
	{
		int l = level(curr);
		if(l < min_level)//if level is less than the min level
		{
			min_level = l;
			min_leaf = curr->data;
		}
		else if(l == min_level && curr->data < min_leaf)//comparing leaves at the same level
		{
			min_leaf = curr->data;
		}
		if(l > max_level)
		{
			max_level = l; max_leaf = curr->data;
		}
		else if(l == max_level && curr->data > max_leaf)
			max_leaf = curr->data;
	}
	
	findleaf(curr->left); findleaf(curr->right);//to traverse						
}

int main()
{
	int n; scanf("%d%*c", &n);
	int num[n]; int i = 0; 
	for(i = 0 ; i < n ; i++)
	{
		int temp; scanf("%d", &num[i]); temp = num[i];
		node* curr = search(temp,root,NULL);
		node* p = (node*)malloc(sizeof(node));
		if(curr == NULL)//if it is the first node
		{
			root = p; p->data = temp;
			p->parent = NULL; p->left = p->right = NULL;
		}
		else
		{
			p->parent = curr;//assigning the parent node at the same time
			p->data = temp;	
			if(curr->data < temp)
			{
				curr->right = p; p->left = p->right = NULL;
			}
			else
			{
				curr->left = p; p->left = p->right = NULL;	
			}
		}
	}
	
	if(root == NULL)//empty tree
			printf("Empty tree\n");
	else		
	{ printf("Node------Parent\n");
	printparent(root); }
	
	
	findleaf(root);//calling function
	
	printf("Largest leaf from maximum level: element %d of level %d \n", max_leaf,max_level);
	printf("Smallest leaf from minimum level: element %d of level %d \n", min_leaf,min_level);
	
	return 0;			
}		





	
