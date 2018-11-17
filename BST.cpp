#include "BST.h"
#include "TreeNode.h"
using namespace std;

BST::BST()
{
  root = NULL;
}

BST::~BST()
{

}

void BST::printTree()
{
  recPrint(root); //A B S T R A C T I O N . . . . .
}

bool BST::isEmpty()
{
  return root == NULL;
}

void BST::recPrint(TreeNode *node)
{
  if(node == NULL)
  {
    return;
  }

  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

void BST::insert(int value)
{
  // check for duplicates

  TreeNode *node = new TreeNode(value);

  if(isEmpty())
  {
    root = node;
  }

  else //not an empty TreeNode, find insertion point
  {
    TreeNode *curr = root;
    TreeNode *par; //empty TreeNode

    while(true) //while par == null;  begin search for insertion point
    {
      par = curr;
      if(value < curr->key) //go left
      {
        curr = curr->left;
        if(curr == NULL) //we found the insertion point
        {
          par->left = node;
          break;
        }
      }

      else //go right
      {
        curr = curr->right;
        if(curr == NULL) //we found the insertion point
        {
          par->right = node;
          break;
        }
      }
    }
  }
}

//search method
bool BST::contains(int value)
{
  if(isEmpty())
  {
    return false;
  }
  else //not empty continue search
  {
    TreeNode *curr = root;

    while(curr->key != value)
    {
      if(curr == NULL)
      {
        return false;
      }

      if(value < curr->key)
      {
        curr = curr->left;
      }

      else
      {
        curr = curr->right;
      }
    }
  }
  return true;
}

bool BST::deleteRec(int k) //figure out exactly how node is deleted (garbage collected)
{
  //use contains method
  if(!contains(k))
  {
    return false;
  }

  //let's proceed to find the TreeNode
  TreeNode *curr = root; //curr
  TreeNode *par = root; //par
  bool isLeft = true;

  //let's look for the TreeNode
  while(curr->key != k)
  {

    par = curr;

    if(k < curr->key) //go left
    {
      isLeft = true;
      curr = curr->left;
    }
    else
    {
      isLeft = false;
      curr = curr->right;
    }

    if(curr == NULL) //in the event you do not use contains
    {
      return false;
    }
  }
  //at this point we found the node to be deleted

  //let's check whether a leaf or not

  if(curr->left == NULL && curr->right == NULL) //then it's a leaf
  {

    if(curr == root)
    {
      delete curr;
      root = NULL;
    }

    else if(isLeft)
    {
      par->left == NULL;
    }
    else
    {
      par->right == NULL;
    }
  }


  //check if has one child
  else if(curr->right == NULL) //no right child, must be isLeft
  {
    if(curr == root)
    {
      root = curr->left;
    }
    else if(isLeft)
    {
      par->left = curr->left;
    }
    else //right child
    {
      par->right = curr->left;
    }
  }

  else if(curr->left == NULL) //no left child, must be right child
  {
    if(curr == root)
    {
      root = curr->right;
    }
    else if(isLeft)
    {
      par->left = curr->right;
    }
    else //right child
    {
      par->right = curr->right;
    }
  }

  else //it has two children, at this point we begin to cry and take a long nap
  {
    TreeNode *success = getSuccessor(curr);

    if(curr == root)
    {
      root = success;
    }
    else if(isLeft)
    {
      par->left = success;
    }
    else
    {
      par->right = success;
    }

    success->left = curr->left;
  }

  return true;
}

//d is the node we are deleting
TreeNode* BST::getSuccessor(TreeNode *d) //find node to replace d
{
  TreeNode *sp = d;
  TreeNode *success = d;
  TreeNode *curr = d->right;

  while(curr != NULL)
  {
    sp = success;
    success = curr;
    curr = curr->left;
  }

  if(success != d->right) //descendant of right child, left most of right
  {
    sp->left = success->right;
    success->right = d->right;
  }

  return success;
}
