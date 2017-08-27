#include <stdio.h>

int main()
{
    int n;
    scanf("%d%*c", &n);
    int arr_a[n];
    int d,i;
    scanf("%d%*c", &d);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr_a[i]);
    }
    int mark = 0;
    for ( i = 0; i < n-2 ; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if( (arr_a[j] - arr_a[i]) == d)
            {
                for(int k = j+1 ; k < n ; k++)
                {
                    if ((arr_a[k] - arr_a[i]) == 2*d)
                    {
                        mark++;
                    }
                }
            }
        }
    }

printf("%d", mark);

}