#include<stdio.h>

int arr[100000];
int i; int m,nn;

void prime(int n)
{
   if(n<=2)
   { arr[0]=2; i=1;  if(m<=2) printf("2\n");}
   else
   {
       int lower=ceil(sqrt(n));
       prime(lower);
       int j=0;
       if(n==nn && m>lower+1) lower=m-1;
       for(j=lower+1;j<=n;j++)
       {
        int flag=0;
        int k=0;
        int arrprim=sqrt(j);
        for(k=0; k<i && arr[k]<=arrprim ;k++)
        {
         if(j%arr[k]==0)
         { flag=1; break; }
        }
        if(flag==0)
        {
         if(j>=m) printf("%d\n",j);
         arr[i]=j; i++;
        }
       }
   }
}

int main()
{
    int t=0;
    scanf("%d",&t);
    int k=0;
    int arr[11][11];
    while(k!=t)
    {
    scanf("%d",&arr[k][0]);
    scanf("%d",&arr[k++][1]);
    }
    
    for(k=0;k<t;k++)
    {
    m=arr[k][0];
    nn=arr[k][1];
    prime (arr[k][1]);
    printf("\n");
    }
    getch();
}
