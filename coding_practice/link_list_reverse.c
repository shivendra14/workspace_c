/* Code to input 5 no. in a link list and then revese the list recursively.
Algorithm:
1. If the list has 1 element return the rev_first as list itself.
2. If the list has 2 elements then swap the elements and return the rev_first as address of second element
3. If list has greater than 2 elements the reverse the list from 2nd element recurrsively,
   and then swap 1st node with 2nd node using step 2 logic.*/
#include<stdio.h>
#include<stdlib.h>
struct link_list
{
int num;
struct link_list *next;
};
       typedef struct link_list Node;
       Node* rev_first;
       
void reverse(Node* list)
{
      if (list->next==0)
      {
      rev_first=list;
      return ;
      }
      
      if((list->next)->next==0)
      {
      rev_first=list->next;
      (list->next)->next=list;
      list->next=0;
      }
      else
      {
      reverse(list->next);
      (list->next)->next=list;
      list->next=0;
      }
}

void display(Node *list)
       {
            while(list!=0)
            {
            printf("%d \n",list->num);
            list=list->next;
            }
            getch();
       }
main()
{
      int i=0;
      Node *first,*list,*prev;
      first=(Node*)malloc(sizeof(Node));
      list=first;
      printf("Enter five numbers to be stored in a link list to be reversed.\n");
      for(i=0;i<5;i++)
      {
            scanf("%d",&list->num);
            list->next=(Node*)malloc(sizeof(Node));
            prev=list;
            list=list->next;
      }
        prev->next=0; free(list);
        printf("The linked list is : \n");
        display(first);
        reverse(first);
        printf("The  reversed linked list is : \n");
        display(rev_first);
}
