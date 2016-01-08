#include<string.h>
#include<stdio.h>

int fact(int f)
{
if (f==0) return 1;
else return f*fact(f-1);
}

[][]char recurse(char arr[])
{
int len=strlen(arr);
char combo[fact(len)][len];
if(len==1)
{
combo[0][0]==arr[0];
combo[0][1]=='\0';
return combo;
}
else
{
    char small[fact(len-1)][len-1];
    small=recurse(arr+1);
    char c=arr[0]; int i,j,k,p,m=0;

    printf("%d %c %s \n ",len,c,small);

    for(i=0;i<fact(len-1);i++)
    {
     if(m==len)
     m=0;
     for(j=0;j<fact(len);j++)
     {
      for(k=0,p=0;k<len;k++,p++)
      {
       if(p==m)
       {
        combo[j][p]==c; k--; continue;
       }
       combo[j][p]==small[i][k];
      }
      printf("%s",combo[j]);
      getch();
      m++;
     }
    }
    return(combo);
}
}
main()
{
      char arr[30];
      printf("Enter the word whose permutations is to be found --> ");
      scanf("%s",arr);
      char** final=recurse(arr);
      printf("The possible permutations are :\n");
      int i,len=fact(strlen(arr));
      for(i=0;i<len;i++)
      {
       printf("%d\t%s\n",i+1,final[i]);
      }
}
