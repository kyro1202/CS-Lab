#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
    int n;
    char word[100];
    scanf("%d%*c",&n);
    for (int i = 0 ; i < n ; i++)
    {
        int l = 16;
        for ( int j = 0 ; j < l ; j++)
        {
            scanf("%c", word[j]);
        }
        if ( l > 10)
        {
            printf("%c%d%c", word[0],l-2,word[l-1]);
        }
        else
        {
            for (int k = 0 ; k < l ; k++)
            {
                printf("%c", word[k]);
            }
        }
        printf("\n");
    }
}

