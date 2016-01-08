#include<stdio.h>
struct bin_tree
{
 int num;
 struct bin_tree *left;
 struct bin_tree *right;
};
typedef struct bin_tree Node;

int depth(Node *tree)
{
    if(tree==0)
    return 0;
    else
    {
        int dl=depth(tree->left);
        int dr=depth(tree->right);
        return 1+(dl>=dr?dl:dr);
    }
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
        /*code snippet to find depth*/
        printf("The deptth of the tree is %d ",depth(first));
        getch();
  }
