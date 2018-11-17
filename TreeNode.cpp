#include "TreeNode.h"

TreeNode::TreeNode()
{
    key = 0;
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode(int k)
{
  key = k;
  left = NULL;
  right= NULL;
}

TreeNode::~TreeNode()
{
  delete right;
  delete left;
}
