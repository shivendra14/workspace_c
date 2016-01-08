/* This program finds max sequential sum possible in an array of integers.
 This code is recurrsive and fails if the maxi sum of left and right half become equals at any instant.*/

#include<stdio.h>
struct pack
{
       int left;
       int right;
       int sum;
};
typedef struct pack cell;

int sum(int arr[],int s,int e)
{
    if(s==e)
    return arr[e];
    else if(s<e)
    return arr[s]+arr[e]+sum(arr,s+1,e-1);
    else
    return 0;
}

cell* contisum(int arr[],int start,int end)
{
     cell* max=(cell*)malloc(sizeof(cell));
     if(start==end)
     {
      max->left=start;
      max->right=end;
      max->sum=arr[start];
      }
      else
      {
          cell *mlhalf,*mrhalf;
          mlhalf=(cell*)malloc(sizeof(cell));
          mrhalf=(cell*)malloc(sizeof(cell));
          int mid=(start+end)/2;  /*right half has lesser terms */
          mlhalf=contisum(arr,start,mid);
          mrhalf=contisum(arr,mid+1,end);
                    
          int s=0;
          if(mlhalf->sum > mrhalf->sum)
          {
           max->sum=mlhalf->sum;     max->left=mlhalf->left;    max->right=mlhalf->right;
           int k;
           int lresidue=sum(arr,mlhalf->right+1,mid);
           for(k=mid+1;k<mrhalf->left;k++)
           {
            s+=arr[k];
            if(s+lresidue>=0)
            {
             max->sum=mlhalf->sum+lresidue+s;     max->right=k;
            }
           }
           if(max->right==mrhalf->left-1 && mrhalf->sum>=0)
           {
            max->sum+=mrhalf->sum;       max->right=mrhalf->right;
           }
           else if(s==0 && lresidue+mrhalf->sum>=0)
           {
            max->sum+=lresidue+mrhalf->sum;   max->right=mrhalf->right;
           }
          }
          else if(mlhalf->sum < mrhalf->sum)
          {
           max->sum=mrhalf->sum;     max->left=mrhalf->left;    max->right=mrhalf->right;
           int k;
           int rresidue=sum(arr,mid+1,mrhalf->left-1);
           for(k=mid;k>mlhalf->right;k--)
           {
            s+=arr[k];
            if(s+rresidue>=0)
            {
             max->sum=mrhalf->sum+rresidue+s;     max->left=k;
            }
           }
           if(max->left==mlhalf->right+1 && mlhalf->sum>=0)
           {
            max->sum+=mlhalf->sum;       max->left=mlhalf->left;
           }
           else if(s==0 && rresidue+mlhalf->sum>=0)
           {
            max->sum+=rresidue+mlhalf->sum;   max->left=mlhalf->left;
           }
          } 
      }
      return max;
}

main()
{
      int arr[50],i=-1;  /*i store position of last element*/
      printf("Enter the array of integers (ended by any character) in which you want to find maximum continuous sum.\n");
      while(scanf("%d",&arr[++i])!=0);
      char qe;
      scanf("%*s %c",&qe);
      int qw;
      scanf("%d",&qw);
      printf("%c %c",qe,qw);
      getch();
      /*while(i!=4)
      {
      int k =scanf("%d",&arr[i++]);
      printf("%d\n",k);
      }*/
      cell* max=contisum(arr,0,i-1);
      printf("The maximum sum is %d in range of left limit %d and right limit %d.\n",max->sum,max->left,max->right);
      getch();
}
