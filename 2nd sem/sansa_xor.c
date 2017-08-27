#include <stdio.h>

int main()
{
    int test; scanf("%d", &test);
    for(int t_i = 0 ; t_i < test ; t_i++)
    {
        unsigned long int n; scanf("%ld", &n);
        printf("%ld\n", ~n + 4294967296);
    }
}