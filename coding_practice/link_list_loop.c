/* Code to test if a link list is cyclic or not. Eg. used are test1 cyclic, and test2 non cyclic lists.*/
#include<stdio.h>
#include<stdlib.h>
struct link_list
{
int num;
struct link_list *next;
};
  typedef struct link_list Node;

    int isListCircular(Node* list)
    {
     if(list==NULL)
     return 0;
     Node *fast=list, *slow=list;
     while(fast!=0 && fast->next!=0)
     {
          if((fast->next)->next==slow)
          return 1;
          fast=fast->next->next;
          slow=slow->next;
     }
    return 0;
    }

 main()
 {
  Node* test1=(Node*)malloc(sizeof(Node));
  test1->next=test1;
  Node* test2=(Node*)malloc(sizeof(Node));   
  test2->next=0;
  int check1=isListCircular(test1);
  int check2=isListCircular(test2);
  printf("%Result of test1 %d \n",check1);      
  printf("%Result of test2 %d \n",check2);
  getch();  
 }       
