/*SHASHANK SAXENA 1601CS42 9/3/2017
  OBJECTIVE : To store matrix as a 2D array ans perform operations on it*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n,m;//global variables 
int mino(int** ,int,int,int);//function prototype 

int deter(int** a,int k)//function to determine determinant
{
	int i,value = 0;
	if(k == 1)//terminating condition
		return a[0][0];
	for(i = 0 ; i < k; i++)//expanding determinant along column 1
	{
		value += a[i][0]*(int)pow(-1,i)*mino(a,k,i,0);//calling function minor
	}
	return value;					
}

int mino(int** a,int k,int r,int c)//function to determine the minor of element at r,c
{
	int i,j,index = 0;
	//copying values of a in b 
	int** b = (int**)malloc((k-1)*sizeof(int*));
	int* temp = (int*)calloc((k-1)*(k-1),sizeof(int));
	for(i = 0 ; i < k ; i++)
	{
		for(j = 0 ; j < k ; j++)
		{
			if(i == r || j == c)//ignoring row r and column c
				continue;
			temp[index] = a[i][j]; index++;	
		}
	}
	index = 0;
	for(i = 0 ; i < k -1 ; i++)
	{
		b[i] = (int*)malloc((k-1)*sizeof(int));
		for(j = 0 ; j < k - 1 ; j++)
		{
			b[i][j] = temp[index]; index++;
		}
	}
	free(temp);//to free the memory
	return deter(b,k-1);
	free(b);
}

void swap(int* a,int* b)//function to swap two ints
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void transpose(int** a,int n)//function to convert a into its transpose
{
	int i,j;
	for(i = 0 ; i < n - 1 ; i++)
	{
		for(j = i + 1 ; j < n ; j++)
		{
			swap(&a[j][i],&a[i][j]);
		}
	}
}

int main()
{
	printf("\n");
	int check_square = 0; printf("Enter the size of the matrix (n X m) = "); scanf("%d%*c%d%*c", &n,&m);
	int** matrix = (int**)malloc(n*sizeof(int*));//allocating memory to matrix
	int i,j;//loop variables
	for(i = 0 ; i < n ; i++)///scanning values
	{
		j = 0;
		printf("Enter the elements of row %d = ", i + 1);
		char c = 'a';
		matrix[i] = (int*)malloc(n*sizeof(int));
		while(c != '\n')
		{
			scanf("%d%c", &matrix[i][j],&c); j++;
		}
	}

	
	if(m == n)//to check for square matrix
		check_square = 1;

	int determinant = 0;
	
	if(check_square == 1)//calculate determinant only if matrix is square
		determinant = deter(matrix,n);
		
	if(determinant != 0)
		printf("The entered matrix is invertible. ");
	else
	{
		if(check_square == 1)
			printf("The entered matrix is not invertible.");	
	}
	if(check_square == 1)
	{
		int** inverse = (int**)malloc(n*sizeof(int*)); //allocating memory to inverse to hold the inverse of matrix

		//giving values of minors in place of inverse
		for(i = 0 ; i < n ; i++)
		{
			inverse[i] = (int*)malloc(n*sizeof(int));
			for(j = 0 ; j < n ; j++)
			{
				inverse[i][j] = mino(matrix,n,i,j);
			}
		}

		
		int highest_minorx,highest_minory,highest_minor = 0;

		//for coordinates of highest minor
		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j < n ; j++)
			{
				if(inverse[i][j] > highest_minor)
				{
					highest_minor = inverse[i][j]; 
					highest_minorx = i;
					highest_minory = j;
				}
			}
		}
		if(determinant != 0)//calculate inverse only if matrix is invertible
		{
		transpose(inverse,n);

		//assigning proper signs
		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j < n ; j++)
			{
				if((i + j) % 2 != 0)
					inverse[i][j] *= -1;
			}
		}

		//printing the inverse
		printf("The inverse matrix is: \n");
		for(i = 0 ; i < n ; i++)
		{
			printf("|");
			for(j = 0 ; j < n ; j++)
			{
				if(determinant < 0)
					printf(" %d/%d |", -1*inverse[i][j],-1*determinant);
				else
					printf(" %d/%d |", inverse[i][j],determinant);	
			}
			printf("\n");
		}
		}
		if(check_square == 1 && determinant == 0)
			printf("\n");
		printf("The entered matrix is a square matrix.\nThe position of the element with highest minor is i = %d, j = %d", highest_minorx+1,highest_minory+1);

		for(i = 0 ; i < n ; i++)
			free(inverse[i]);//freeing memory
	}
	else
		printf("The entered matrix is not a square matrix.");
	
	printf("\n");
	for(i = 0 ; i < n ; i++)
	{
		free(matrix[i]);//freeing memory
	}
}
