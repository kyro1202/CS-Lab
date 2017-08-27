/*SHASHANK SAXENA
  1601CS42
  OBJECTIVE : To implement karatsuba multiplication*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void to_binary(long long int num,char* des)//function to convert lld into binary
{
    int i = 0;
    while(num > 0)
    {
        des[i] = num%2+'0';
        i++;
        num = num/2;
    }
    int j = 0;
    for( j = 0 ; j < i/2 ; j++)//reversing the characters
    {
        char c = des[j];
        des[j] = des[i-j-1];
        des[i-j-1] = c;
    }
    des[i] = '\0';
}
void getequal(char* a,char* b)//make both strings of equal length
{
    int i;
    if(strlen(a) > strlen(b))
    {
        int diff = strlen(a) - strlen(b);
        char temp[64]; int mark = 0;
        strcpy(temp,b);
        for(i = 0 ; i < diff ; i++)//inserting zeroes
            b[i] = '0';//padding
        for(i = diff ; i < strlen(a) ; i++)//the original string
        {
            b[i] = temp[mark]; mark++;
        }
        b[strlen(a)] = '\0';
        a[strlen(a)] = '\0';
    }
    else
    {
        int diff = strlen(b) - strlen(a);
        char temp[64]; int mark = 0;
        strcpy(temp,a);
        for(i = 0 ; i < diff ; i++)
            a[i] = '0';
        for(i = diff ; i < strlen(b) ; i++)
        {
            a[i] = temp[mark]; mark++;
        }
        a[strlen(b)] = '\0';
        b[strlen(b)] = '\0';
    }
}
void add(char* a,char* b,char* res)//function to add two numbers
{
    getequal(a,b);//make strings of equal length
    int mark = 0,i,carry = 0;
    for(i = strlen(a) - 1 ; i >= 0 ; i--)
    {
        int x = a[i]-'0',y = b[i]-'0';
        int sum = (x^y^carry) + '0';//1^1 = 0, 0^0 = 0, 1^0 = 1
        res[mark] = (char)sum;
        mark++;
        carry = ( (x&y) | (y&carry) | (x&carry) );//if two ones were present
    }
    if(carry)//in case of overflow
    {
        res[mark] = '1'; mark++;
    }
    for(i = 0 ; i < mark/2 ; i++)//reversing the characters
    {
        char c = res[i];
        res[i] = res[mark-i-1];
        res[mark-i-1] = c;
    }
    res[mark] = '\0';
}
long long int multiply(char* f,char* s)//function to multiply two numbers
{
    getequal(f,s);
    if(strlen(f) == 0)//base case
        return 0;
    if(strlen(f) == 1)
        return (f[0]-'0')*(s[0]-'0');//one bit multiplication
    int in = strlen(f)/2;//floor of length
    int la = strlen(f) - in;//ceil of length
    char fl[64],fr[64],sl[64],sr[64],fa[64],sa[64];
    strcpy(fr,f+in); strcpy(sr,s+in);
    fr[la] = '\0'; sr[la] = '\0';//fr and sr contains right halves of first and second strings
    strncpy(fl,f,in); strncpy(sl,s,in);
    fl[in] = '\0'; sl[in] = '\0';//fl and sl contains left halves of first and second strings
    long long int p1 = multiply(fl,sl);//karatsuba multiplication algorithm
    long long int p2 = multiply(fr,sr);
    add(fr,fl,fa); add(sr,sl,sa);
    long long int p3 = multiply(fa,sa);
    return p1*(1<<2*la)+(p3-p2-p1)*(1<<la)+p2;    
}
int main()
{
    long long int a,b;
    printf("Enter the two numbers to be multiplied - "); scanf("%lld %lld", &a,&b);
    int minus = 0;
    if(a < 0 && b > 0 || a > 0 && b < 0)//if the product will be negative
    minus = 1;
    if(a < 0)//making a and b positive
    a *= -1;
    if(b < 0)
    b *= -1;
    if(a == 0 || b == 0)
    {
        printf("The product is 0\n");
        return 0;
    }
    char first[64],second[64];
    to_binary(a,first);//converting into binary
    to_binary(b,second);
    long long int ans = multiply(first,second);
    if(!minus)
    printf("The product is %lld\n", ans);
    else
    printf("The product is -%lld\n", ans);    
}