/* Code to place 8 Queens on chess board without crossing anyones path.
Algorithm:
Place each queen 1 by one and keep on restricting area by it.
If at the end you are able to place 8 queens the solution is correct otherwise,
correct the position of immediately previous queen placed and continue to find solution.
*/
#include<stdio.h>
int arr[8][8];

void display()
{
     int i,j;
     for(i=0;i<8;i++)
     {
       for (j=0;j<8;j++)
        if(arr[i][j]==-1)
        printf("Q    ");
        else
        printf(".    ");
       printf("\n");
     }
     printf("\n");
     getch();
}

int chess(int qp,int i,int j)
{
    
    for(i=0;i<8;i++)
    {
      for(j=0;j<8;j++)
      {
        if(arr[i][j]==0)
        {
          qp++;  
          arr[i][j]=-1;        
          if(qp==8)          /*return 1 if all 8 are placed*/
          return 1;         
               
                  int m,n;                  /* restricting area*/
                  for(m=0;m<8;m++)
                  {
                  if(arr[i][m]!=-1)
                  arr[i][m]++;
                  if(arr[m][j]!=-1)
                  arr[m][j]++;
                  }
                  m=i; n=j;
                  while(m>=0 && n>=0)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]++;
                    m--; n--;
                  }
                  m=i; n=j;
                  while(m>=0 && n<=7)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]++;
                    m--; n++;
                  }
                  m=i; n=j;
                  while(m<=7 && n>=0)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]++;
                    m++; n--;
                  }
                  m=i;n=j;
                  while(m<=7 && n<=7)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]++;
                    m++; n++;
                  }
          int q=chess(qp,i,j);
          
          if(q==1)
          return 1;
          
          else if(q==0)
          {
           qp--;
                  for(m=0;m<8;m++)           /* derestricting area*/
                  {
                  if(arr[i][m]!=-1)
                  arr[i][m]--;
                  if(arr[m][j]!=-1)
                  arr[m][j]--;
                  }
                  m=i; n=j;
                  while(m>=0 && n>=0)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]--;
                    m--; n--;
                  }
                  m=i; n=j;
                  while(m>=0 && n<=7)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]--;
                    m--; n++;
                  }
                  m=i; n=j;
                  while(m<=7 && n>=0)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]--;
                    m++; n--;
                  }
                  m=i;n=j;
                  while(m<=7 && n<=7)
                  {
                    if(arr[m][n]!=-1)
                    arr[m][n]--;
                    m++; n++;
                  }
           arr[i][j]=0;
          }
        }
      }
    }
    
    if(i==8 && j==8)   /*shows no possible position found for the queen.*/
    return 0;
}

void main()
{
     int i,j;
     for(i=0;i<8;i++)
      for (j=0;j<8;j++)
       arr[i][j]=0;
     int res=chess(0,0,0);
     if(res!=0)
     display();       
}
