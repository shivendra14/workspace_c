/* Code to insert, delete and display link list.*/
#include<stdio.h>
#include<stdlib.h>
struct link_list
{
int num;
struct link_list *next;
};
       typedef struct link_list Node;
       Node* insert(Node*,int);
       Node* delete1(Node*,int);
       Node* get_node();
       void display(Node*);
       
       main()
       {
             Node *first=0;
             int choice;
             do
             {
             printf("Enter your choice (1 to insert, 2 to delete, 3 to display, -1 to exit) --> ");
             scanf("%d",&choice);
             int pos;
              switch(choice)
              {
               case 1:
                      
                      while(1)
                          {
                           printf("Enter the position of insertion of data --> ");
                           scanf("%d",&pos);
                           if(pos<0) break;
                           first=insert(first,pos);
                           }
                           break;
               case 2:
                      
                      while(1)
                          {
                           printf("Enter the position of deletion of data --> ");
                           scanf("%d",&pos);
                           if(pos<0) break;
                           first=delete1(first,pos);
                           }
                           break;
               case 3: display(first);
                       break;
               default: printf("Exit");
               }
              }
              while(choice!=-1);
       }
                    
       
       Node* insert(Node *first, int pos)
       {
             
            Node *list,*prev;
            int count=1;
            Node *temp=get_node();
            printf("Enter the data to be stored at position %d --> ",pos);
            scanf("%d",&temp->num);
            if(pos==1)
            { temp->next=0;  first=temp; }
            else
            { 
              list=first;
              while(count!=pos)
              {
                 prev=list;
                 list=list->next;
                 count++;
              }
             temp->next=list;
             prev->next=temp;
           }
       return first;
       }
       
       Node* delete1(Node *first, int pos)
       {
            int count=1;
            Node *prev,*list;
            if (pos==1)
            {first=first->next;}
            else
            {  
              list=first;          
              while(pos!=count)
              {
              count++;
              prev=list;
              list=list->next;
              }
             prev->next=list->next;
             free(list);
             }
             return first;
       }
       
       Node* get_node()
       {
             return (Node*)malloc(sizeof(Node));
       }
       
       void display(Node *list)
       {
            printf("The linked list is : \n");
            while(list!=0)
            {
            printf("%d \n",list->num);
            list=list->next;
            }
       }                  
             

