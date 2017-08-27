#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    int ar[101] = {0};
    for(int i = 0 ; i < n ; i++)
    {
        int a; scanf("%d", &a);
        ar[a]++;
    }
    for(int i = 0 ; i < 101 ; i++)
    {
        if(ar[i] == 1)
        {
            printf("%d", i);
            break;
        }
    }
}