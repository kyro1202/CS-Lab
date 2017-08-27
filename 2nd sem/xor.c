#include <stdio.h>

void max(int* a,int* b)
{
    int temp;
    if(*a > *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int a,b,max = 0;
    scanf("%d", &a); scanf("%d", &b);
    max(&a,&b);
    for (int i = a ; i <= b ; i++)
    {
        for(int j = a ; j <= b ; j++)
        {
            if( i ^ j > max )
                max = i ^ j ;
        }
    }
    printf("%d", max);
}