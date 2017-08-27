#include <stdio.h>

int main()
{
    int test; scanf("%d", &test);
    for(int ti = 0 ; ti < test ; ti++)
    {
        int n,c,m; scanf("%d %d %d", &n,&c,&m);
        int count = 0;
        count += n/c ;
        int w = count; int temp;
        while(w >= m)
        {
           temp = w/m ;
           count += temp;
           w = w%m ;
           w += temp;  
        }
        printf("%d\n", count);
    }
}