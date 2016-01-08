/*Code to insert an element in a binary search tree at the appropriate location.
and Code to traverse a binary tree via preorder, inorder and post order traversals.*/
#include<stdio.h>
struct bin_tree
{
 int num;
 struct bin_tree *left;
 struct bin_tree *right;
};
typedef struct bin_tree Node;

 void preorder(Node *tree)
 {
      if(tree==0)
      return;
      printf("%d\t",tree->num);
      preorder(tree->left);
      preorder(tree->right);     
  }
 void inorder(Node *tree)
 {
      if (tree==0)
      return;
      inorder(tree->left);
      printf("%d\t",tree->num);
      inorder(tree->right);
  }
  
 void postorder(Node *tree)
 {
      if(tree==0)
      return;
      postorder(tree->left);
      postorder(tree->right);
      printf("%d\t",tree->num);
  } 
  
  void tree_delete(Node* tree)
{
     Node* prev;
     int del,cas;
     printf("Enter the number to be deleted from the binary search tree.");
     scanf("%d",&del);
     if(del==-999) return;
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
           break;
      } 
     }
}

 main()
 {
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
    
    tree_delete(first);
    
    printf("Enter the number to be deleted and enter -999 to exit.");
    
    scanf("%d",&store);
    
       printf("\nThe pre order traversel is:\n");
       preorder(first);
       printf("\nThe in order traversel is:\n");
       inorder(first);
       printf("\nThe post order traversel is:\n");              
       postorder(first);
    getch();
 }
