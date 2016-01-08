/*Code to traverse a binary tree via preorder, inorder and post order traversals*/
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

 main()
 {
       Node* tree=(Node*)malloc(sizeof(Node));
       printf("The pre order traversel is:\n");
       preorder(tree);
       printf("The in order traversel is:\n");
       inorder(tree);
       printf("The post order traversel is:\n");              
       postorder(tree);
  }
