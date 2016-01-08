#include<stdio.h>
int main()
{
    int t=0;
    scanf("%d",&t);
    int i=0,j=0,k=0,flag=0;
    int arr[11][11];
    while(i!=t)
    {
    scanf("%d",&arr[i][0]);
    scanf("%d",&arr[i++][1]);
    }
    
    int arr1[1000];

        
    for(i=0;i<t;i++)
    {
                    
    for(j=0 ; j<arr[i][1] ; j++)
    arr1[j]=j;
    
     int c=0;
     for(k=2;k*k<=arr[i][1];k++)
     {
      
      if(arr1[k]!=-1)
      {
       int mul=3;
       for(j=k*2 ; j*j<=arr[i][1];j=k*mul++)
       arr1[j]=-1;
       mul=(int)(arr[i][0]/k)+1; if(mul==1) mul++;
       for(j=k*mul;j<=arr[i][1]; j=k*mul++)
       arr1[j]=-1;
      }
     }
     for(j=arr[i][0];j<=arr[i][1];j++)
     if(arr1[j]!=-1 && j!=1)
     printf("%d\n",j);
    
    printf("\n");
    }

      
     
     /*while(c<=arr[i][1]-arr[i][0])
     {
      k=arr1[c++];
      if(k<=1) continue;
      flag=0;
      for(j=2;(j*j)<=k;j++)
      {
       if(k%j==0)
       {
       flag=1;
       break;
       }
      }
       if(flag==0)
       {
       printf("%d\n",k);
       int w=k-arr[i][0] , mul=2;
       
       while(w<=arr[i][1]-arr[i][0])
        { arr1[w]=-1; w=k*mul-arr[i][0]; mul++;}
       }
     }
     printf("\n");
    }*/getch();
    return 0;
}
