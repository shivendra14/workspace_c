#include <stdio.h>

int main(void) {

	int** a= (int** )malloc(sizeof(int*) *5);
	int i=0,j=0;
	int* b;
	b= (int*)malloc(sizeof(int)*50);
	for (i=0;i<5;i++)
	{
	a[i]=b+10*i;


	for (j=0;j<10;j++)
	a[i][j]=i+j+1;
	}


	for(i=0;i<5;i++)
	{
	 for (j=0;j<10;j++)
	 printf("%d  ",a[i][j]);
	 printf("\n");
	}


	return 0;
}
