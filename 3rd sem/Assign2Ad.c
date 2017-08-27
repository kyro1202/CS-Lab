/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To sort the given list recursively using recusive max min finder*/
#include <stdio.h>
#include <stdlib.h>
int n;
typedef struct node//structure of a node
{
    int min,minindex,max,maxindex;
}node;
void minmax(int b[],int s,int e,node* t)//function to find max and min value of a array in a given range
{
    if(s > e)//base condition
    return;
    if(b[s] < t->min)
    {
        t->min = b[s]; t->minindex = s;//updating min
    }
    if(b[s] > t->max)
    {
        t->max = b[s]; t->maxindex = s;//updating max
    }
    minmax(b,s+1,e,t);//recursive call
}
void swap(int ar[],node t,int b,int e)
{
    int check = 0;
    if(t.maxindex == b)//if max element is present at starting position check is raised to 1
    {
        check = 1;
    }
    ar[t.minindex] = ar[b];//starting element and min element are swapped
    ar[b] = t.min;
    if(check)//if check is 1
    t.maxindex = t.minindex;//max element is at min index so max index is updated    
    ar[t.maxindex] = ar[e];//end element and max element are swapped
    ar[e] = t.max;
}
void sort(int a[],int b,int e)
{
    if(b >= e)//base condition
    return;
    node temp; temp.min = 1000000; temp.max = 0; minmax(a,b,e,&temp);//to find max min
    swap(a,temp,b,e);//to set max min at right and left ends
    sort(a,b+1,e-1);//next call with increased left and decreased right end
}
int main()
{
    printf("Enter the number of elements in the list - "); scanf("%d", &n);
    printf("Enter the elements of the list - ");
    int arr[n];
    int i;
    for(i = 0 ; i < n ; i++)
    {    
        scanf("%d", &arr[i]);
    }
    sort(arr,0,n-1);
    printf("Sorted list is - ");
    for(i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}