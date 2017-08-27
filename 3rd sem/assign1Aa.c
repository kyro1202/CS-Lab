/*SHASHANK SAXENA 
  1601CS42
  OBJECTIVE - To sort the names is lexicographic order and store their abbreviations too*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node//structure of a node in linked list
{
    char name[20];//full name
    char nick[20];//abbreviation
    struct node* next;//pointer to next object
}node;

int main()
{
    printf("Enter the no. of students - "); int n; scanf("%d", &n);
    char ar[n][20];//array to store full names
    printf("Enter the names of students (separated by space) - \n"); scanf("%*c");
    int i;
    for(i = 0 ; i < n ; i++)
    {
        scanf("%s", ar[i]);
    }
    int swapped = 0;//sorting the names
    do//untill there are no swaps required
    {
        swapped = 0;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            if(strcmp(ar[i],ar[i+1]) > 0)
            {
                char* temp; temp = (char*)malloc(20);
                strcpy(temp,ar[i]);
                strcpy(ar[i],ar[i+1]);
                strcpy(ar[i+1],temp);
                swapped = 1;
            }
        }
    }while(swapped);
    node* p; p = (node*)malloc(sizeof(node));//the head node
    node* head = p;
    char m[20]; char o[20];//temperary strings
    for(i = 0 ; i < n ; i++)
    {
        memset(m,'\0',20);//resetting the strings to null
        memset(o,'\0',20);
        node* t = (node*)malloc(sizeof(node));
        strcpy(t->name,ar[i]);//storing the full name
        if(n == 1)//for one element only
        {
            t->nick[0] = ar[0][0];
        }
        else if(i == 0)//starting element is compared with right neighbour only
        {
            int len = strlen(ar[i]) < strlen(ar[i+1]) ? strlen(ar[i]) : strlen(ar[i+1]) ;
            int j; int pos = 0;
            for(j = 0 ; j < len ; j++)
            {
                m[j] = ar[i][j];
                if(ar[i][j] != ar[i+1][j])
                break;
            }
            strcpy(t->nick,m);
        }
        else if(i == n - 1)//last element is cmopared with left neighbour only
        {
            int len = strlen(ar[i]) < strlen(ar[i-1]) ? strlen(ar[i]) : strlen(ar[i-1]) ;
            int j; int pos = 0;
            for(j = 0 ; j < len ; j++)
            {
                m[j] = ar[i][j];
                if(ar[i][j] != ar[i-1][j])
                break;
            }
            strcpy(t->nick,m);    
        }
        else//all other elements are compared with left and right both neighbours 
        {
            int len = strlen(ar[i]) < strlen(ar[i-1]) ? strlen(ar[i]) : strlen(ar[i-1]) ;
            int j; int pos = 0;
            for(j = 0 ; j < len ; j++)
            {
                m[j] = ar[i][j];
                if(ar[i][j] != ar[i-1][j])
                break;
            }
            for(j = 0 ; j < len ; j++)
            {
                o[j] = ar[i][j];
                if(ar[i][j] != ar[i+1][j])
                break;
            }
            //string with larger length is selected for uniqueness
            strlen(o) > strlen(m) ? strcpy(t->nick,o) : strcpy(t->nick,m);
        }
        p->next = t;//for connecting linked list
        p = t;
    }
    p->next = NULL;//to represent the end of list
    head = head->next;//to skip the empty head node
    while(head != NULL)
    {
        if(head->next != NULL)
        printf("%s,", head->name);
        else
        printf("%s", head->name);
        head = head->next;//traversing to the next pointer
    }
}
