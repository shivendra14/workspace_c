#include <stdio.h>
struct link_list
{
    int num;
    struct link_list *next;
};
typedef struct link_list Node;

Node *rev_first;

 Node* getNode ()
 {
     return (Node*)malloc(sizeof(Node));
 }

 Node* reverse (Node *list)
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

main ()
{
    int input;
    Node *first=getNode();
    Node *list=first;
    printf("Enter the elements for the list\n");
    while(scanf("%d",&input)==1)
    {
        Node *temp=getNode();
        temp->num=input;
        temp->next=0;
        list->next=temp;
        list=temp;
    }
    list=first->next;
    while (list!=0)
    {
        printf("%d \n",list->num);
        list=list->next;
    }
    reverse(first->next);
    list=rev_first;
    int n=0;
    while (list!=0)
    {   n++;
        printf("%d \n",list->num);
        list=list->next;
    }

    list=rev_first;

    int i,j;
    for (i=0;i<n;i++)
    {

        for(j=0;j<n-1-i;j++)

        {
            if (list->num>list->next->num)
            {
           int temp=list->next->num;
           list->next->num=list->num;
           list->num=temp;
            }
            list=list->next;
        }
    list=rev_first;
    }

    list=rev_first;
    while (list!=0)
    {
        printf("%d \n",list->num);
        list=list->next;
    }
}
