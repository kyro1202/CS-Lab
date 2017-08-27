/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE - To divide an array into two lists and find pallindromes in them*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node//structure of a node
{
    char initial;//to store the initial of the name
    struct node* next;//pointer to next element
}node;
int check;//flaf to check if there are any pallindromes printed or not
int isvowel(char test)//function to check whether a char is a vowel or not
{
    if(test == 'A' || test == 'E' || test == 'I' || test == 'O' || test == 'U')
        return 1;
    return 0;
}
void palindrome(char a[])//function to check whether a string is a pallindrome or not
{
    int len = strlen(a);
    int i;
    for(i = 0 ; i < len/2 ; i++)
    {
        if(a[i] != a[len-i-1])
        return;
    }
    for(i = 0 ; i < len ; i++ )
    {
        check = 1;
        printf("%c", a[i]);
        if(i != len - 1)
        printf("->");
    }
    printf("\n");
}
int main()
{
    check = 0;//resetting the value of check
    printf("Enter the no. of students - "); int n; scanf("%d", &n);
    char ar[n][20];
    printf("Enter the names of students (separated by space) - \n"); scanf("%*c");
    int i;
    for(i = 0 ; i < n ; i++)
    {
        scanf("%s", ar[i]);
    }
    node* head1; node* p; p = (node*)malloc(sizeof(node));//head pointer for the first list
    head1 = p;
    for(i = 0 ; i < n/2 ; i++)//inserts only vowels in the list
    {
        if(isvowel(ar[i][0]))
        {
            node* t; t = (node*)malloc(sizeof(node)); 
            t->initial = ar[i][0];
            p->next = t;
            p = t;
        }
    }
    for(i = 0 ; i < n/2 ; i++)//inserts only conconants in the list
    {
        if(!isvowel(ar[i][0]))
        {
            node* t; t = (node*)malloc(sizeof(node));
            t->initial = ar[i][0];
            p->next = t;
            p = t;
        }
    }
    p->next = NULL;
    head1 = head1->next;//to ignore the extra empty block
    node* head2; node* q; q = (node*)malloc(sizeof(node));//head pointer for second list
    head2 = q;
    for(i = n/2 ; i < n ; i++)
    {
        if(isvowel(ar[i][0]))
        {
            node* t; t = (node*)malloc(sizeof(node));
            t->initial = ar[i][0];
            q->next = t;
            q = t;
        }
    }
    for(i = n/2 ; i < n ; i++)
    {
        if(!isvowel(ar[i][0]))
        {
            node* t; t = (node*)malloc(sizeof(node));
            t->initial = ar[i][0];
            q->next = t;
            q = t;
        }
    }
    q->next = NULL;
    head2 = head2->next;
    node* temp1 = head1;//temperary head pointers
    node* temp2 = head2;
    while(head1 != NULL)//for printing the list
    {
        printf("%c", head1->initial); head1 = head1->next;
        if(head1 != NULL)
        printf("->");
    }
    if(n > 1)
    printf(" and ");
    while(head2 != NULL)
    {
        printf("%c", head2->initial); head2 = head2->next;
        if(head2 != NULL)
        printf("->");
    }
    printf("\nThe Pallindromes are -\n");
    char m[n]; int j,k; int pos,count; char c;
    /* algo to check every possible pallindrome O(n^3) for every element it makes strings with other elements and pass
        it to the palindrome function*/
    for(i = 0 ; i < n/2 - 1; i++)
    {
        memset(m,'\0',n);
        for(j = i+1 ; j < n/2; j++)
        {
            pos = 0; memset(m,'\0',n); 
            for(k = i ; k <= j ; k++)
            {   
                count = 0; node* new = temp1;
                while(new != NULL)
                {
                    c = new->initial;
                    new = new->next;
                    if(count == k)
                    break;
                    count++;
                }
                m[pos] = c; pos++;
            }
            palindrome(m);
        }
    }
    for(i = 0 ; i < n - n/2 - 1; i++)
    {
        memset(m,'\0',n);
        for(j = i+1 ; j < n - n/2; j++)
        {
            pos = 0; memset(m,'\0',n); 
            for(k = i ; k <= j ; k++)
            {   
                count = 0; node* new = temp2;
                while(new != NULL)
                {
                    c = new->initial;
                    new = new->next;
                    if(count == k)
                    break;
                    count++;
                }
                m[pos] = c; pos++;
            }
            palindrome(m);
        }
    }
    if(!check)//to print none if no palindromes are found
    printf("None\n");
}