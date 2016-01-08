#include<stdio.h>
struct pack
{
       int left;
       int right;
       int sum;
};
typedef struct pack cell;

main()
{
      int arr[50],i=0;
      printf("Enter the array of integers in which you want to find maximum continuous sum.\n");
   /*   while(scanf("%d",&arr[i++])!=EOF){} */
        
      while(i!=4)
      {
      int k=scanf("%d",&arr[i++]);
      printf("%d",k);
      }
      
      cell *max,*tmax;
      int i;
      tmax=(cell*)malloc(sizeof(cell));
      tmax->sum=0;
      for(i=0;i<arr.length;i++)
      {
       tmax->sum+=arr[i];
       if(tmax->sum < max->sum)
       (
       max->sum=tmax->sum-arr[i];
       max->right=k;
       max->left=
       }
       else
       
       
