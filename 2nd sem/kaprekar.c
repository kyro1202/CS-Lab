#include <stdio.h>
#include <math.h>

long int power(long int a,long int b)
{
    int temp = 1;
    for(int i = 0 ; i < b ; i++)
    {
        temp *= a;
    }
    return temp;
}

int size(long int a)
{
    int i;
    for (i = 0 ; ; i++)
    {
        if(a / power(10, i) == 0)
        return i ;
    }
}

int main()
{
    long int a,b; long int size_num,size_sqr,first,second; int count = 0;unsigned long long int sqr;
    scanf("%d %d", &a,&b);
    for( long int num = a ; num <= b ; num++)
    {
    sqr = num*num;
    printf("%lld ", sqr);
    size_num = size(num);
    printf("%d ", size_num);
    first, second;
    first = sqr / (power(10, size_num));
    second = sqr - (first*(power(10, size_num)));
    long int sum = first + second;
    printf("%d", sum);
    if (sum == num)
    { printf("%d ", num); count++; }
    if(count == 0)
    printf("INVALID RANGE");
    }
}
