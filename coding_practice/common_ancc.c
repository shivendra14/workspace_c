/*Write a function to find the comoon ancestor of two given nodes of binary tree.*/
#include<stdio.h>
struct bin_tree
{
 int num;
 struct bin_tree *left;
 struct bin_tree *right;
};
typedef struct bin_tree Node;

int postOrderToFindLCA(Node *tree, int a, int b)
{
 if(tree==0)
 return 0;
 int lpresent=postOrderToFindLCA(tree->left,a,b);
 int rpresent=postOrderToFindLCA(tree->right,a,b);
 if(lpresent+rpresent==2)
 {
  printf("The common ancesstor of given nodes is : %d ",tree->num);
  return 0;
 }
 if(tree->num==a || tree->num==b)
 return 1;
 
 return lpresent+rpresent;
}
      
 main()
 {
  /* Code snippet to insert elements  in a BST.*/
      Node* first=0;
      Node* tree=0;
      int store=0;
      while(1)
      {
       printf("Enter the number to be inserted in the binary search tree.  ");
       scanf("%d",&store);
       if(store==-99)
       break;
       Node* temp=(Node*)malloc(sizeof(Node));
       temp->num=store;
       temp->left=0;
       temp->right=0;
       if(first==0)
       {first=temp; tree=first; continue; }
       tree=first;
      while(tree!=0)
      {
       if(store<tree->num )
         if(tree->left==0)
         {tree->left=temp; break;}
         else
         tree=tree->left;
       else if (store>tree->num )
        if(tree->right==0)
        {tree->right=temp; break;}
        else
        tree=tree->right;
       else
       {
       printf("Number already preasant.\n");
       getch();
       free(temp);
       return;    
       }
      }
    }             
    printf("Enter the numbers whose nearest common ancesstor is to be found.\n");
    int a,b;
     scanf("%d %d",&a,&b);
     /*code snippet to find common ancesstor*/
       int dummy=postOrderToFindLCA(first,a,b);
       getch();
  }
