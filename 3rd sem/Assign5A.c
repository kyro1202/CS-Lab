/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE - To analyse the performance of quicksort*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t c1,c2;
double runtime;
void swap(unsigned int* a,unsigned int* b)//normal swapping function
{
	unsigned int temp = *a;
	*a = *b;
	*b = temp; 
}
void quicksort(unsigned int* a,int start,int last,int type)//function for quicksort, type == method of selecting pivot
{
	if(start < last)
	{
		int i = start-1,j,index;
		int n = last - start;
		if(type == 0)//first
			index = start;
		else if(type == 1)//random
			index = rand()%(n+1) + start;
		else if(type == 2)//median of 0 n/2 n-1
		{
			if(a[start] >= a[start+(n+1)/2] && a[start] <= a[last])
				index = start;
			else if(a[last] >= a[start] && a[last] <= a[start+(n+1)/2])
				index = last;
			else
				index = start+(n+1)/2;
		}
		else//median of n/4 n/2 3*n/4
		{
			int t1 = start+(n+1)/4,t2 = start+(n+1)/2,t3 = start+3*(n+1)/4;
			if(a[t1] >= a[t2] && a[t1] <= a[t3])
				index = t1;
			else if(a[t2] >= a[t1] && a[t2] <= a[t3])
				index = t2;
			else
				index = t3; 		
		}
		swap(a+index,a+last);//swapping with the last element
		for(j = start ; j <= last-1 ; j++)
		{
			if(a[last] >= a[j])//if element comes to the left of pivot
			{
				i++;
				swap(a+i,a+j);
			}
		}
		i++;
		swap(a+i,a+last);//pivot now at its position
		quicksort(a,start,i-1,type);//quicksort on left half
		quicksort(a,i+1,last,type);//quicksort on right half
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int i = 0,j; int n; 
	printf("Performance of quicksort\n\nn\t		Pivot type\t		Random		Sorted		Almost Sorted\n");
	for(n = 10000 ; n <= 10000000 ; n *= 10)//for every n
	{
		printf("--------------------------------------------------------------------------------\n");
		for(j = 0 ; j < 4 ; j++)//for every type of pivot selecting method
		{
			if(n < 10000000)
			printf("%d\t\t", n);
			else
			printf("%d\t", n);
			if(j == 0) printf("FIRST\t\t\t\t");
			else if(j == 1) printf("RANDOM\t\t\t\t");
			else if(j == 2) printf("MEDIAN OF THREE 1\t");
			else printf("MEDIAN OF THREE 2\t");
			unsigned int* a = (unsigned int*)malloc(n*sizeof(unsigned int));
			for(i = 0 ; i < n ; i++)
				a[i] = rand()%100000000;//array of random numbers
			c1 = clock();
			quicksort(a,0,n-1,j);//now array is sorted
			c2 = clock();
			runtime = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;        
			printf("%lf\t", runtime);
			if(n >= 1000000 && j == 0)
				printf("  VS*  \t\t");//to avoid cases with n >= 10^6
			//O(n^2) for 10^6 gives approx 10^4 seconds !!!!!
			else
			{
				c1 = clock();
				quicksort(a,0,n-1,j);//passing the sorted array
				c2 = clock();
				runtime = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;         
				printf("%lf\t", runtime);
			}
			for(i = 0 ; i < n/100 ; i++)//for k = n/100 times
			{
				int t1 = rand()%n;
				int t2 = rand()%n;
				swap(a+t1,a+t2);//swapping random numbers
			}
			c1 = clock();
			quicksort(a,0,n-1,j);//passing almost sorted array
			c2 = clock();
			runtime = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;         
			printf("%lf\n", runtime);
			free(a);
		}
	}
	printf("\n*VS = Very Slow !!!\n");
}
