/* SHASHANK SAXENA 1601CS42 07/02/2017
   OBJECTIVE : STATISTICAL ANALYSIS OF GUESTS AT A PARTY */

#include <stdio.h>

//GLOBAL VARIABLES - TO BE USED BY VARIOUS FUNCTIONS
int no_guests;
int num[100]; 

//SORTING FUNCTION (BUBBLE SORT)
void sort(int* a)
{
int i,j,temp; int cmin; int pmin;
for(i = 0 ; i < no_guests - 1; i++)
{
cmin = a[i]; pmin = i;
for(j = i ; j < no_guests ; j++)
{
if(a[j] < cmin)
{
cmin = a[j];
pmin = j;
}
}
temp = a[i]; a[i] = cmin ; a[pmin] = temp;
} 
}

//TO PRINT THE SEATING POSITIONS
void display(int* a)
{
int i; int check = 0;
for(i = no_guests - 1 ; i >= 1 ; i--)
{
check++;
//TO MAINTANE SYMMETRY
if(a[i] > 0)
printf("%.2d ,", a[i]);
else
printf("%d ,", a[i]);
//NEW LINE AFTER FIVE ENTRIES
if((check % 5) == 0)
printf("\n");
}
if(a[i] > 0)
printf("%.2d ", a[0]);
else
printf("%d ", a[0]);
}

//FIND THROUGH LINEAR SEARCH (MAX 15 ELEMENTS SO BINARY SORT WILL NOT CAUSE A GREAT EFFECT)
void find(int* a, int b)
{
int i; int flag =  0;
for(i = 0 ; i < no_guests ; i++ )
{
if(b == a[i])
{
printf("\nThe guest with id %d is present in the party and is seated at position %d.", b, no_guests - i);
flag = 1;
break;
}}
if(flag != 1)
printf("\nThe guest with id %d is not present at the party", b);}

//FUNCTION TO CHECK THE GENDER 
void gender(int* a)
{
int males = 0,females = 0; int i; int m[17],f[17];
for(i = 0 ; i < no_guests ; i++)
{
//CHECKS FOR THE CONDITION AND SIMULTANEOUSLY STORE IT IN AN ARRAY TO PRINT
if(a[i] < 0)
{
m[males] = a[i];
males++;
}
else
{
f[females] = a[i];
females++;
}
}
printf("\nThere are %d males and %d females.", males,females);
if (males != 0)
{
printf("\nThe male guest id's are : ");
for(i = 0 ; i < males - 1 ; i++)
{
printf("%d,", m[i]);
}
//NOT TO PRINT THE COMMA AFTER THE LAST ELEMENT
printf("%d", m[males - 1]);
}
if (females != 0)
{
printf("\nThe female guest id's are : ");
for(i = 0 ; i < females - 1 ; i++)
{
printf("%d,", f[i]);
}
printf("%d", f[females - 1]);
}
}
//CHECK FOR COLOR OF THE DRESS (EXACTLY SAME AS THE GENDER FUCTION)
void color(int* a)
{
int i; int r[17],b[17]; int red = 0,blue = 0; 
for(i = 0 ; i <  no_guests ; i++)
{
if((a[i] % 2) == 0)
{
r[red] = no_guests - i;
red++;
}
else
{
b[blue] = no_guests - i;
blue++;
}
}
printf("\nThere are %d guests in red and %d guests in blue dress respectively.", red,blue);
printf("\nThe seating positions of the guests in red dress are : ");
for(i = 0 ; i < red - 1 ; i++)
printf("%d,", r[i]);
printf("%d", r[red - 1]);
printf("\nThe seating positions of the guests in blue dress are : ");
for(i = 0 ; i < blue - 1 ; i++)
printf("%d,", b[i]);
printf("%d", b[blue - 1]);
}


int main()
{
int i = 0; char c;int targ;
printf("Enter the unique ids of the guests : ");
//SCANNING INPUTS UPTILL THE NEW LINE CHAR
while(c != '\n')
{
//INTEGER IN THE ARRAY
scanf("%d", &num[i]);
i++;
//CHARACTER TO CHECK THE CONDITION
scanf("%c", &c);
}
no_guests = i ;
//GUESTS SHOULD BE AT LEAST 10 AND ATMOST 15
if(no_guests < 10 || no_guests > 15)
{
printf("\nNo. of guests should be less than 16 and more than 9");
return 1;
}
printf("Enter the id to be searched : ");
scanf("%d%*c", &targ);
int new;
printf("Enter the unique id of the new guest : ");
scanf("%d%*c", &new); 
//CALLING VARIOUS FUNCTIONS
sort(num);
printf("\nThe seating arrangement is : \n");
display(num);
find(num,targ);
gender(num);
color(num);
//AGAIN CHECKING THE CONDITION FOR GUESTS OVERFLOW 
if(no_guests == 15)
{
printf("\nNo more guests allowed !");
return 2;
}
printf("\nThe new seating arrangement is : \n");
num[no_guests] = new;
no_guests += 1;
sort(num);
display(num);
//THATS ALL FOLKS !!
}









