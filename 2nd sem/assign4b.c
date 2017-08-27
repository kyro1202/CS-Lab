/* SHASHANK SAXENA 1601CS42 01/02/2017
   Objective: TO CONVERT DECIMAL NUMBERS INTO BINARY AND HEXAGONAL REPRESENTATIONS */

#include <stdio.h>
#include <math.h>
#include <string.h>

//DECLARING GLOBAL VARIABLES 
int steps;
char store[35];
char num1[35],num2[35];
char base[35];

//FUNCTION TO CONVERT DECIMAL -> BINARY 
int to_binary(unsigned long int a, char b[])
{
    //NO. OF CHARACTERS IN THE BINARY FORM OF THE DECIMAL
    steps = log(a)/log(2);
    
    //POINTER TO THE ARRAY
    char* s; s = store;
    
    //CONVERTING INTO BINARY
    while (a != 0)
    {
        *s = a%2 ; s++ ; a /= 2 ;
    }
    int i; s = &store[steps];
    char* p; p = b;  
    
    //REVERSING THE CHARACTERS OF THE ARRAY
    for ( i = 0; i <= steps ; i++)
    {
       *p  = *s + '0' ;
       p++ ; s-- ;
    }

    //RETURNING THE NUMBER OF CHARACTERS IN THE BINARY FORM
    return steps;
}

//FUNCTION TO MEASURE THE HAMMING DISTANCE
int h_dis(char a[], char b[])
{   
    
    //FOR HAMMING WEIGHT CHAR b[] IS TAKEN AS base[35] which has all entries zero
    int i;
    char* t; t = a;
    char* l; l = b;
    int count = 0;
    for(  ; *t ; )
    {
        //IF THE CHARACTERS ARE DIFFERENT THE COUNT IS INCREASED BY ONE
        if( *t != *l)
        count++;
        t++ ; l++ ;
    }
    //RETURNING COUNT 
    return count;
}

//FUNCTION TO CONVERT DECIMAL -> HEXADECIMAL
void to_hexa(unsigned long int a, char b[])
{
    //SAME AS to_binary
    steps = log(a)/log(16);
    char* s; s = store;
    while (a != 0)
    {
        *s = a%16 ; s++ ; a /= 16 ;
    }
    int i; s = &store[steps];
    char* p; p = b;  
    for ( i = 0; i <= steps ; i++)
    {
       *p  = *s + '0' ;
       //IF THE RESULT IS > 9 
       if((int)*p == 58) *p = 'a';
       else if((int)*p == 59) *p = 'b';
       else if((int)*p == 60) *p = 'c';
       else if((int)*p == 61) *p = 'd';
       else if((int)*p == 62) *p = 'e';
       else if((int)*p == 63) *p = 'f';
       p++ ; s-- ;
    }
}
int main()
{
    //ASSIGNING ALL ENTRIES OF base[] TO BE ZERO
    int j;
    for (j = 0; j < 35; j++)
    {
        base[j] = '0';
    }


    unsigned long int a,b;
    int i;
    //GETTING INPUT
    printf("Enter two decimal integers:");
    scanf("%ld%*c%*c%ld%*c", &a , &b);
    
    int s1 = to_binary(a, num1); 
    
    printf("The binary representation of %ld is:", a);
    //PRINTING NUM1
    for ( i = 0; i <= s1  ; i++)
    {
        printf("%c", num1[i] );
    }
    
    int s2 = to_binary(b, num2);
    
    printf("\nThe binary representation of %ld is:", b);
    //PRINTING NUM2
    for ( i = 0; i <= s2  ; i++)
    {
        printf("%c", num2[i]  );
    }
    
    //CALCULATING AND PRINTING HAMMING WEIGHT
    printf("\nHamming weight for the first string = %d", h_dis(num1,base));
    
    printf("\nHamming weight for the second string = %d", h_dis(num2,base));
    //CALCULATING AND PRINTING HAMMING DISTANCE
    if(s1 == s2)
    printf("\nHamming distance between two strings = %d", h_dis(num1,num2));
    
    //CONVERTING a -> HEXADECIMAL
    to_hexa(a, num1); 
    
    printf("\nThe hexadecimal representation for the first string = ");
    //PRINTING NUM1
    for ( i = 0; i <= steps  ; i++)
    {
        printf("%c", num1[i] );
    }
    //CONVERTING b -> HEXADECIMAL
    to_hexa(b, num2);
    
    printf("\nThe hexadecimal representation for the second string = ");
    //PRINTING NUM2
    for ( i = 0; i <= steps  ; i++)
    {
        printf("%c", num2[i] );
    }
}
