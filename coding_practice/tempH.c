/* Code to solve the problem of tower of hannoi.
Algorithm:
1. This code shifts n-1 elements to an auxillary array
2. Then shift the nth element to final array
3. Then swaps the initial and the auxillary array and repeat the procedure.

* Here for ease of list starting location handling(as it change frequently) 
  I have used an extra element at the starting of each list pointing to the main
  starting of the lists.*/

#include<stdio.h>
#include<stdlib.h>
struct link_list
{
int num;
struct link_list *next;
};
       typedef struct link_list Node;
       
       void push(Node *first,int num)
       {
             Node* temp=(Node*)malloc(sizeof(Node));
             temp->num=num;
             temp->next=first->next;
             first->next=temp;
             }
       
       int pop(Node *first)
       {
             Node* prev=first->next;
             first->next=(first->next)->next;
             int pop=prev->num;
             free(prev);
             return pop;
             }
             
       void display(Node *first)
       {
            Node* list=first->next;
            while(list!=0)
            {
            printf("%d \n",list->num);
            list=list->next;
            }
            getch();
       }

       void toh(Node *a,Node *b, Node *c, int n)
       {
            while(n!=1)
            {
             toh(a,c,b,n-1);
             
             int p=pop(a);
             push(b,p);
             n--;
             Node* temp=c;
             c=a;  a=temp;
            }
            if(n==1)
            {
            int p=pop(a);
            push(b,p); 
            }
       }
       
       main()
       {
          Node *a,*b,*c;
          a=(Node*)malloc(sizeof(Node));
          b=(Node*)malloc(sizeof(Node));
          c=(Node*)malloc(sizeof(Node));                     
          a->next=b->next=c->next=0;
          
          int n,k;
          scanf("%d %d",&n,&k);
          int i=0,j=0,flag=0;
          int arr[3][40];
          while(i!=2)
          {
                     for (temp=0;temp<n;temp++)
                     scanf("%d",&arr[i][temp]);
          i++;
          }
    
    
          for(q=n;q>=1;q--)
          {
           switch(arr[0][q])
           {
            case 1:   push(a,q); break;
            case 2:   push(b,q); break;
            case 3:   push(c,q); break;
            }
          }
          
          toh(a,b,c,j);
          display(b);
       }
