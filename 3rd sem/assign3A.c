/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To find the median of a given array without sorting it*/
#include <stdio.h>
#include <stdlib.h>
int find_median(int size,int ind,int* arr)
{
	if(size == 0)//if only one element is in the array
		return arr[0];
	int temp = rand()%(size+1);//choosing a random pivot
	int pivot = arr[temp];
	int arr1[100000],arr2[100000],mark1 = 0,mark2 = 0;
	int i = 0;
	for(i = 0 ; i <= size ; i++)
	{
		if(i == temp)//ignoring the pivot
			continue;
		if(arr[i] <= pivot)
		{
			arr1[mark1] = arr[i]; mark1++;
		}
		else if(arr[i] > pivot)
		{
			arr2[mark2] = arr[i]; mark2++;
		}
	}
	if(mark1 > ind)//if more elements are smaller than pivot
	{
		return find_median(mark1-1,ind,arr1);//function called on the left array
	}
	else if(mark1 < ind)//if more elements are larger than pivot
	{
		//ind is decreased by mark1(left elements) and 1(pivot was ignored)
		return find_median(mark2-1,ind-mark1-1,arr2);//function is called on the right array with updated ind
	}
	else
		return pivot;//else pivot is the median
}
int main()
{
	int n; int arr[100000];
	printf("Enter the number of elements - "); scanf("%d", &n);
	int i = 0;
	printf("Enter the elements - ");
	for(i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);
	int ans = find_median(n-1,(n-1)/2,arr);
	printf("Median of the arr is = %d\n", ans);
}
