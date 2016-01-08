/* Code for Quick Sort of an array.
Algorithm:
1. find the correct position of 1st element.
 i. this can be done by exchanging the element from a smaller no. on right, and
 ii.exchanging the number with a greater number on the left repetedly till the position is optimum.
2. divide the rest of the array in two parts from this correct poition.
3. quick sort the 2 left and right arrays recurrsively.
*/
#include<stdio.h>

 void sort(int arr[], int start, int end)
 {
      int  scount=start,ecount=end;
      while(scount<ecount)
      {
 
      while(arr[scount]<arr[ecount])
       ecount--;

       int t=arr[scount];
       arr[scount]=arr[ecount];
       arr[ecount]=t;
       
      while(arr[ecount]>arr[scount])
       scount++;

       t=arr[scount];
       arr[scount]=arr[ecount];
       arr[ecount]=t;
      }
      
      if(scount!=start)
      sort(arr,start,scount-1);
      
      if(ecount!=end)
      sort(arr,ecount+1,end);
 }
 
 main()
{
        int n,i;
        printf("Enter the number of entries to be made in the array.");
        scanf("%d",&n);
        int arr[n];
        printf("Enter the numbers :\n");
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        sort(arr,0,n-1);
        printf("The sorted array is :\n");
        for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
        getch();
 }
