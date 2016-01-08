#include<stdio.h>
#include<stdlib.h>


main()
{
    int a,b;
    int x [3][3][2]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
    printf("%d ", *(*(*x+0)+2)+1);

    int arr[]= {89,34,54,68,98};
    printf("%u %u\n", arr+1, &arr+1);

    char str1[]="h";
    char str2[]="h";
    if (str1==str2) printf("e");
    else printf("u");

    char str[13]="the word is";
    str[13]='b';
    printf("%s\n",str);
    char c ='a';
    //for(b=0;b<26;b++,c++)
 printf("%c   %u \n", c, (int)c-97);
}

