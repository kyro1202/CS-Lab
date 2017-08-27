/* SHASHANK SAXENA 1601CS42 14/02/2017
   Objective: TO PRINT ALL POSSIBLE PERMUTATIONS OF A STRING */

#include <stdio.h>
#include <stdlib.h>

//GLOBAL VARIABLES - TO BE USED BY VARIOUS FUNCTIONS
int n;int curr_num = 1;int total;

//Simple sorting algorithm
void sort(char* s)
{
int i,j,pmin; char cmin;
for(i = 0 ; i < n - 1 ; i++)
{
cmin = s[i] ; pmin = i;
for(j = i ; j < n  ; j++)
{
if(s[j] < cmin)
{
cmin = s[j];
pmin = j;
}
}
char temp = s[i];
s[i] = cmin;
s[pmin] = temp;
}}

//this program prints the lexicographically next permutation so the string must be sorted otherwise it will not print the previous PERMUTATIONS
int next_permutation(char* s)
{

int i = n - 1,j = n -1;
//highest index i such that s[i-1] < s[i]
while(i > 0 && s[i-1] >= s[i])
i--;
//exit program if there is no next permutation
if(i <= 0)
return 1;
//highest index j such that s[j] > s[i-1]
while(s[j] <= s[i-1])
j-- ;
char temp = s[i - 1];
s[i - 1] = s[j];
s[j] = temp;
j = n -1;
//reversing the elements from i to j
while(i < j)
{
temp = s[i];
s[i] = s[j];
s[j] = temp;
i++;j--;
}
//printing comma before next_permutation to avoid the comma after the last permutation
printf(", ");
for(i = 0 ; i < n ; i++)
{
printf("%c", s[i]);
}

//calling itself again
next_permutation(s);
return 1;
}

int main()
{

int i = 0;char c;
printf("Number of letters: ");
scanf("%d%*c", &n);

char s[n];
printf("Enter the letters: ");
//will scan the input untill the new line character
while(c != '\n')
{
scanf("%c", &s[i]);
scanf("%c", &c);
i++;
}
//calling various functions
sort(s);
for(i = 0 ; i < n ; i++)
{
printf("%c", s[i]);
}
next_permutation(s);
}












