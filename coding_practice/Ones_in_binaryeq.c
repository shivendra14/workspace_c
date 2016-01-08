#include<stdio.h>
main()
{
      int x,count=0;
      printf("Input:\n");
      scanf("%d",&x);
      while(x!=0)
      {
                 count++;
                 x=(x&(x-1));
      }
      printf("\nOutput:\n");
      printf("%d",count);
      getch();
}
