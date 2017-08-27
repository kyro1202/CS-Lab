#include <stdio.h>
#include <stdlib.h>

int check(i,j,k)
{
    if(i >= (j + k) )
        return 1;
    else
        return 0;    
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n,flag = 0; scanf("%d", &n);
    int ar[n];
    for (int i = 0 ; i < n ; i++ )
    {
        scanf("%d", &ar[i]);
    }
    qsort(ar,n,sizeof(int),cmpfunc);
    for (int i = n - 1 ; i > 1 ; i--)
    {
        for (int j = n - 1 ; j > 0; i++)
        {
            for(int k = n - 2 ; j >= 0 ; j++)
            {
                flag = check(i,j,k);
                if(flag == 1)
                {
                    printf("%d %d %d", &k,&j,&i); return 0;
                }
                else
                {
                    flag = 0;
                }
            }
        }
    }
    printf("-1"); return 0;
}