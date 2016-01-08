/*Code to check wheather a given tree is a BST or not.
Algoritm;
1. Null tree is a BST.
2. Verify the condition of BST with left node and conditonally,
3. Verify the condition with right node.
4. Now if both above sttements are true return 1 else return 0.
*/
#include<stdio.h>
struct bin_tree
{
 int num;
 struct bin_tree *left;
 struct bin_tree *right;
};
typedef struct bin_tree Node;

int inorder(Node *tree)
 {
      int temp;
      if (tree==0)
      return 1;
      
      if (tree->left!=0 && tree->left->num>tree->num)
      return 0;
      else
      temp=inorder(tree->left);
      
      if(temp==1)
      {
      if (tree->right!=0 && tree->right->num<tree->num)
      return 0;
      else
      temp=inorder(tree->right);
      }
      
      return temp;
      
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
        
        /*Code snippet to check wheather the given tree is a BST or not.*/
        int temp=inorder(first);
        if(temp==0)
        printf("The given tree is not a BST.");
        else
        printf("The given tree is a BST.");
        getch();
  }
