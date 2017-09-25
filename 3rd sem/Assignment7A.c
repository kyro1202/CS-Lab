/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE - To implement linear time algorithm for i^th order statistics*/
#include <stdio.h>
#include <stdlib.h>

int n,key;
int arr[100000];

int compare(const void * a , const void * b)//function for quicksort
{
  return (*(int*)a - *(int*)b);
}
int getmedian(int* a,int n)// O(1)
{
    qsort(a,n,sizeof(int),compare);//sorting the array (max 5 elements - constant time)
    return a[n/2];//return the middle element
}
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int* a,int s,int e,int k)//just like quicksort with pivot is middle element  -- O(n)
{
    //atleast 3n/10 - 6 are smaller than this pivot hence no possibility of worst case running time
    int i;
    for(i = s ; i <= e ; i++)
        if(a[i] == k)
            break;
    swap(a+e,a+i);
    int p = s;
    for(i = s ; i < e ; i++)
    {
        if(a[i] <= a[e])
        {
            swap(a+p,a+i);
            p++;
        }
    }
    swap(a+e,a+p);
    return p;
}
int keysmallestelement(int* a,int s,int e,int k)
{
    if(k > 0 && k <= (e-s+1))//if a valid solution exist
    {
        int n = e-s+1;
        int i,median[(n+4)/5];//array to store the medians of various groups
        for(i = 0 ; i < n/5 ; i++)
            median[i] = getmedian(a+s+i*5,5);//median of every single group
        if(i*5 < n)
        {
            median[i] = getmedian(a+s+i*5,n%5);//for last group
            i++;
        }
        int middle = ( i == 1 ) ? median[0] : keysmallestelement(median,0,i-1,i/2); // recursilvely calculating the median of medians
        int par = partition(a,s,e,middle);
        if(par-s == k-1)//if this is the ans
            return a[par];
        else if(par-s > k-1)//if ans lies left of the par
            return keysmallestelement(a,s,par-1,k);
        else//if ans lies to the right of the par
            return keysmallestelement(a,par+1,e,k-par+s-1);
    }
}
int main()
{
    printf("Enter the number of elements - "); scanf("%d", &n);
    int i;
    printf("Enter the elements - ");
    for(i = 0 ; i < n ; i++)
        scanf("%d", &arr[i]);
    printf("Enter the value of i - "); scanf("%d", &key);
    printf("i^th smallest element in the array is - %d\n", keysmallestelement(arr,0,n-1,key));
}