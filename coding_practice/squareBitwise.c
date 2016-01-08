#include<stdio.h>
int noOfOnes(int n)
{
    int count=0;
    while (n!=0)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}

int square (int n)
{
 int m=n,sq=0;
 while (m!=0)
 {
   sq += ( n << noOfOnes( ( m & ~(m-1) ) - 1) );
   m=m&(m-1);
 }
 return sq;
}

int main ()
{
int n;
scanf("%d",&n);
printf("%d",square(n));
return 0;
}


/*
3*3 = 3(2 +1 )
5*5 = 5(4 +1)

11 01  01  3*2 +
11 10  10
10 10  10  3*4

*/

no. of digits in  a no. = floor (log(n)/log 2  + 1);
