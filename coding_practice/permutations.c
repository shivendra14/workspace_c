#include<string.h>
#include<stdio.h>

struct link_list
{
char a;
struct link_list *next;
};
typedef struct link_list Node;

int fact(int f)
{
if (f==0) return 1;
else return f*fact(f-1);
}

void insert(Node* first,Node* to_ins,int pos)
{
int i=1; Node *prev=first;
while(i!=pos)
{
prev=prev->next;
i++;
}
to_ins->next=prev->next;
prev->next=to_ins;
}

void display(Node* first)
{
 if(first!=0)
 {
 printf("%c",first->a);
 display(first->next);
 }
}

main()
{
char arr[30];
printf("Enter the word whose permutations is to be found --> ");
scanf("%s",arr);
int len=strlen(arr);
int k=fact(len);
Node* perm[k];
int i,j;
for(i=0;i<k;i++)
{
perm[i]=malloc(sizeof(Node));
perm[i]->next=0;
}


for(j=0;j<len;j++)
{
 int count=1;
 for(i=0;i<k;i++)
 {
 Node* temp=malloc(sizeof(Node));
 temp->a=arr[j];
 temp->next=0;

 insert(perm[i],temp,count);
 count++;
 if(count==j+2)
 count=1;
 }
}

for(i=0;i<k;i++)
{
printf("\n%d\t",i+1);
display(perm[i]->next);
}
getch();
}
