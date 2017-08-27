#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k; scanf("%d %d", &n,&k);
    int* pages = (int*)malloc(n*sizeof(int));
    int* questions = (int*)malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &pages[i]);
    for(int i = 0 ; i < n ; i++)
    {
        int count = pages[i]/k;
        
    }    
}