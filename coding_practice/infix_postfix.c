/* Code to convert infix(starting and ending with paranthesis) operation into postfix operation using stack.
Algorithm:
1. Readfrom left to right.
2. If '(' occur push in stack.
3. If any variable occur put to postfix from left to right.
4. If any operator occur pop the operators with >= precedence and add to postfix.
    Push the operator in stack.
5. If ')' occur, pop and add to postfix untill '(' is obtained.
6. Repeat The procedure untill the stack is empty.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct link_list
{
char num;
struct link_list *next;
};
       typedef struct link_list Node;
       Node* first=0;
       
       void push(char num)
       {
             Node* temp=(Node*)malloc(sizeof(Node));
             temp->num=num;
             temp->next=first;
             first=temp;
             }
       
       char pop()
       {
             Node*prev=first;
             first=first->next;
             char pop=prev->num;
             free(prev);
             return pop;
             }
             
       void display()
       {
            Node* list=first;
            while(list!=0)
            {
            printf("%c \n",list->num);
            list=list->next;
            }
            getch();
       }
       
       int equi(char c)
       {
           switch(c)
           {
            case '+':
            case '-': return 1;
            case '*':
            case '/': return 2;
            case '^': return 3;
            default: return 0; /*for paranthesis*/
            }
       }
       
       main()
       {
             printf("Enter an infix expression to evaluate its equivalent ppostfix expression.\n");
             char infix[100],postfix[100];
             gets(infix);
             int len=strlen(infix);
             char c='\0';
             int i=0,j=0;
           while(i<len)
           {
             c=infix[i];
             i++;
             if(c=='(')
             {                     
             push(c);
             }
             else if((c>='A' && c<='Z') || (c>='a' && c<='z'))
             {
                  postfix[j]=c;
                  j++;

             }
             else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
             {
                  char popc;
                  while(1)
                  {
                  popc=pop();
                  if(equi(popc)>=equi(c))
                  {
                   postfix[j]=popc; j++;
                  }
                  else
                  break;
                  }
                  push(popc);
                  push(c);
             }
             else if(c==')')
             {
                  while(1)
                  {
                  char popc=pop();
                  if(popc!='(')
                  {
                  postfix[j]=popc;
                  j++;
                  }
                  else
                  break;
                  }
             }
       }
       postfix[j]='\0';
       printf("The equivalent postfix expression is:\n");
       puts(postfix);
       getch();
 }
