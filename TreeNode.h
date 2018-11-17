#ifndef TREENODE_H
#define TREENODE_H


#include <iostream>
using namespace std;

class TreeNode
{
  public:
    TreeNode();
    TreeNode(int k);
    ~TreeNode();

    int key;
    TreeNode *left;
    TreeNode *right;
};

#endif
