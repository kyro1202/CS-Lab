#include <stdlib.h>
#include <stdio.h>
int a[265][265],b[265][265],output[265][265];
int r;

void mult(int r1,int c1,int r2,int c2,int len)
{
	if(len == 0)
		return;
	if(len == 2)
	{

		output[r1][c2] += a[r1][c1]*b[r2][c2] + a[r1][c1+1]*b[r2+1][c2];
		output[r1][c2+1] += a[r1][c1]*b[r2][c2+1] + a[r1][c1+1]*b[r2+1][c2+1];
		output[r1+1][c2] += a[r1+1][c1]*b[r2][c2] + a[r1+1][c1+1]*b[r2+1][c2];
		output[r1+1][c2+1] += a[r1+1][c1]*b[r2][c2+1] + a[r1+1][c1+1]*b[r2+1][c2+1];
		return;
	}
	else
	{
		len /= 2;
		mult(r1,c1,r2,c2,len);
		mult(r1,c1+len,r2+len,c2,len);
		mult(r1,c1,r2,c2+len,len);
		mult(r1,c1+len,r2+len,c2+len,len);
		mult(r1+len,c1,r2,c2,len);
		mult(r1+len,c1+len,r2+len,c2,len);
		mult(r1+len,c1,r2,c2+len,len);
		mult(r1+len,c1+len,r2+len,c2+len,len);
	}
}
int main()
{
	printf("Enter the number of rows in the matrix - "); scanf("%d", &r);
	if(r <= 0)
	{
		printf("INVALID INPUT !!!\n");
		return 0;
	}
	printf("Enter the elements of first matrix (row wise) - ");
	int i,j;	
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < r ; j++)
		{
			scanf("%d", &a[i][j]);
			output[i][j] = 0;
		}
	}
	printf("Enter the elements of second matrix (row wise) - ");
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < r ; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	if(r == 1)
	{
		printf("The matrix multiplication product is - %d\n", a[0][0]*b[0][0]);
		return 0;
	}
	mult(0,0,0,0,r);
	printf("The matrix multiplication product is - \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%8d ", output[i][j]);
		}
		printf("\n");
	}
}
