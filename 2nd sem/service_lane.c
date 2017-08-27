#include <stdio.h>

int main()
{
    int n,t;
    scanf("%d %d", &n,&t);
    int width[n];
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &width[i]);
    for(int i = 0 ; i < t ; i++)
    {
        int a,b; scanf("%d %d", &a,&b);
        int min = 3;
        for(int j = a ; j <= b ; j++)
        {
            if(width[j] < min)
                min = width[j];
        }
        printf("%d\n", min);
    }
}