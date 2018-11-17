#ifndef BST_H
#define BST_H

#include "TreeNode.h"

class BST
{
  public:
    BST();
    ~BST();

    void insert(int value);
    bool contains(int value);
    //bool deleteNode(int value);
    //bool deleteRec(TreeNode *node);
    bool deleteRec(int k);
    bool isEmpty();

    TreeNode* getSuccessor(TreeNode *d);

    void printTree();
    void recPrint(TreeNode *node); //in-order traversal

  private:
    TreeNode *root;
};

#endif
