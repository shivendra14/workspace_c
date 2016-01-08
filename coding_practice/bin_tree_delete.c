#include<stdio.h>
struct bin_tree
{
 int num;
 struct bin_tree *left;
 struct bin_tree *right;
};
typedef struct bin_tree Node;

void tree_delete(Node* tree)
{
     Node* prev;
     int del,cas;
     printf("Enter the number to be deleted from the binary search tree.");
     scanf("%d",&del);
     prev=tree;
     while(tree!=0)
     {
      if(del<tree->num)
       if(tree->left==0)
       printf("Number not presant!!!.");
       else
       {prev=tree; tree=tree->left; cas=1;}
      else if(del>tree->num)
       if(tree->right==0)
       printf("Number not presant!!!.");
       else
       { prev=tree; tree=tree->right; cas=2;}
      else
      {
          if(tree->left==0 && tree->right==0)
          {
           switch(cas)
           { case 1: prev->left=0; break;
             case 2: prev->right=0; break;
           }
           }
          else if(tree->left==0)
          {
           switch(cas)
           { case 1: prev->left=tree->right; break;
             case 2: prev->right=tree->right; break;
           }
           }
          else if (tree->right==0)
          {
           switch(cas)
           { case 1: prev->left=tree->left; break;
             case 2: prev->right=tree->left; break;
           }
           }
          else
          {
              Node* pre_sucess=0;
              Node* sucessor=tree;
              Node* temp=tree->right;
              while(temp!=0)
              {
               pre_sucess=sucessor;
               sucessor=temp;
               temp=temp->left;
               }
               if(pre_sucess!=tree)
               pre_sucess->left=sucessor->right;
               else
               pre_sucess->right=sucessor->right;
               
            switch(cas)
            { case 1:sucessor->right=tree->right;
                     sucessor->left=tree->left;
                     prev->left=sucessor;
                     break;
              case 2: sucessor->right=tree->right;
                      sucessor->left=tree->left;
                      prev->right=sucessor;
                      break;
            } 
           }
      } 
     }
}
