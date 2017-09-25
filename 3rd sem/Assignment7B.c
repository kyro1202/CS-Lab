/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE - To find the maximum possible sum using pairs of elements*/
#include <stdio.h>
#include <stdlib.h>

int n,m;
int arr[100000];

typedef struct pair//structure of a pair
{
    int a; int ai;//a stores value and ai stores its index
    int b; int bi;//b stores value and bi stores its index
    int c;//c stores sum of a and b
}pair;

pair val[100000];

int compare(const void * a , const void * b)//function for quicksort
{
  return (*(int*)a - *(int*)b);
}
int main()
{
    printf("Enter the number of elements - "); scanf("%d", &n);
    int i;
    printf("Enter the elements - ");
    for(i = 0 ; i < n ; i++)
        scanf("%d", &arr[i]);
    printf("Enter the value of m - "); scanf("%d", &m);
    qsort(arr,n,sizeof(int),compare);//for maximum value of pairs we start from the end of the sorted array
    int j; int mark = 0;
    for(i = n-1 ; i > 0 ; i--)//storing the possible pairs in the array val
    {
        if(arr[i] - arr[i-1] <= m)
        {
            val[mark].a = arr[i]; val[mark].ai = i;
            val[mark].b = arr[i-1]; val[mark].bi = i-1;
            val[mark].c = arr[i] + arr[i-1];
            mark++;
        }
    }
    int tot = 0;
    int flag[mark];//array to mark which pairs we used
    for(i = 0 ; i < mark ; i++)//initialising
        flag[i] = 0;
    flag[0] = 1;//taking the first element
    tot = 1;
    int prev = val[0].bi;//to ignore the already used elements
    for(i = 1 ; i < mark ; i++)
    {
        if(tot > n/2)//if we have enough pairs
            break;
        if(val[i].ai != prev)//if its not being used again
        {
            flag[i] = 1;
            prev = val[i].bi;
            tot++;
        }
    }
    int ans = 0;
    for(i = 0 ; i < mark ; i++)//printing the pairs
    {
        if(flag[i])
        {
            ans += val[i].c;
            printf("(%d,%d) ", val[i].a,val[i].b);
        }
    }
    printf("with sum = %d\n", ans);
}