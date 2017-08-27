#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test; scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int n,count5 = 0,count3 = 0; scanf("%d", &n);
        count5 = n/3;
        for(;;)
        {
            n -= count5*3;
            if(n%5 == 0)
                break;
            else
                count5--;
            if(count5 < 0)
            {
                printf("-1"); goto label;
            }        
        }
        for(int i = 0 ; i < count5*3 ; i++)
            printf("5");
        for(int i = count5*3 ; i < n ; i++)
            printf("3");    
label: printf("\n");
    }
}