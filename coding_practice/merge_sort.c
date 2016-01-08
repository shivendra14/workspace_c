/* Code to merge sort an array (Good for large number of inputs).
Algorithm:
1. Divie the array in two parts and merge sort each part seperately.
2. If there is just one element then return the element itself.
3. Now after sorting the 2 halves merge the 2 sorted arrays to make a single sorted array (It require just On) time.
*/
#include<stdio.h>
#include<stdlib.h>

    void sort(int arr[],int start, int end)
    {
        if(end<=start)
        return;
        else
        {
        int mid=(end+start)/2; /* 1st array has more elements than 2nd*/
        sort(arr,start,mid);
        sort(arr,mid+1,end);
        int j=start,k=mid+1;
        int ma[end-start+1];
        int i;
        for( i=0;i <=(end-start);i++)
        {
            if(j>mid)
            { ma[i]=arr[k]; k++; continue; }
            else if( k>end)
            { ma[i]=arr[j]; j++; continue; }
            
            if(arr[j]<arr[k])
            {
            ma[i]=arr[j];
            j++;
            }
            else if(arr[j]>arr[k])
            {
            ma[i]=arr[k];
            k++;
            }
            else
            {
            ma[i]=arr[j]; ma[i+1]=arr[j];
            j++; k++; i++;
            }
            }
            for(i=0;i<=end-start;i++)
            arr[start+i]=ma[i];
        }
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

