#ifndef GENBST_H
#define GENBST_H

#include "GenTreeNode.h"
#include <fstream>

using namespace std;

//template class================================================================
template <class T>
class GenBST
{
  public:
    GenBST();
    ~GenBST();

    void insert(T value);
    bool contains(T value);
    //bool deleteNode(int value);
    //bool deleteRec(GenTreeNode *node);
    bool deleteRec(T k);
    bool isEmpty();

    GenTreeNode<T>* search(T key);
    GenTreeNode<T>* search(int key);

    GenTreeNode<T>* getSuccessor(GenTreeNode<T> *d);

    void printTree();
    void recPrint(GenTreeNode<T> *node); //in-order traversal
    void saveTree(ofstream& os, GenTreeNode<T> *node);

    GenTreeNode<T>* getRoot();

  private:
    GenTreeNode<T> *root;
};

//template functions============================================================
template <class T>
GenBST<T>::GenBST()
{
  root = NULL;
}

template <class T>
GenBST<T>::~GenBST()
{
  delete root;
}

template <class T>
 void GenBST<T>::printTree()
{
  recPrint(root); //A B S T R A C T I O N . . . . .
}

template <class T>
bool GenBST<T>::isEmpty()
{
  return root == NULL;
}

template <class T>
GenTreeNode<T>* GenBST<T>::getRoot()
{
  return root;
}

template <class T>
void GenBST<T>::recPrint(GenTreeNode<T> *node)
{
  if(node == NULL)
  {
    return;
  }

  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

template <class T>
void GenBST<T>::saveTree(ofstream& os, GenTreeNode<T> *node) {
  if(node == NULL)
  {
    return;
  }

  os << node->key << endl;
  saveTree(os, node->left);
  saveTree(os, node->right);
}

template <class T>
void GenBST<T>::insert(T value)
{
  // check for duplicates

  GenTreeNode<T> *node = new GenTreeNode<T>(value);

  if(isEmpty())
  {
    root = node;
  }

  else //not an empty GenTreeNode, find insertion point
  {
    GenTreeNode<T> *curr = root;
    GenTreeNode<T> *par; //empty GenTreeNode

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
template <class T>
bool GenBST<T>::contains(T value)
{
  if(isEmpty())
  {
    return false;
  }
  else //not empty continue search
  {
    GenTreeNode<T> *curr = root;

    while(curr->key != value)
    {
      if(curr == NULL)
      {
        return false;
      }

      //check if leaf
      if(curr->left == NULL && curr->right == NULL)
      {
        return value == curr->key;
      }

      else if(value < curr->key)
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

template <class T>
GenTreeNode<T>* GenBST<T>::search(T key) {
  GenTreeNode<T> *curr = root;
  while(curr != NULL) {
    if(curr->key == key) {
      return curr;
    }
    else {
      if(curr->key > key) {
        curr = curr->left;
      }
      else if(curr->key < key){
        curr = curr->right;
      }
    }
  }
  return curr;
}

template <class T>
GenTreeNode<T>* GenBST<T>::search(int key) {
  GenTreeNode<T> *curr = root;
  while(curr != NULL) {
    if(curr->key == key) {
      return curr;
    }
    else {
      if(curr->key > key) {
        curr = curr->left;
      }
      else if(curr->key < key){
        curr = curr->right;
      }
    }
  }
  return curr;
}

template <class T>
bool GenBST<T>::deleteRec(T k) //figure out exactly how node is deleted (garbage collected)
{
  //use contains method
  if(!contains(k))
  {
    return false;
  }

  //let's proceed to find the GenTreeNode
  GenTreeNode<T> *curr = root; //curr
  GenTreeNode<T> *par = root; //par
  bool isLeft = true;

  //let's look for the GenTreeNode
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
      root = NULL;
    }

    else if(isLeft)
    {
      par->left = NULL;
    }
    else
    {
      par->right = NULL;
    }
    delete curr;
  }


  //check if has one child
  else if(curr->right == NULL) //no right child, must be isLeft
  {
    if(curr == root)
    {
      root = curr->left;
      curr->left = NULL;
      delete curr;
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
    GenTreeNode<T> *success = getSuccessor(curr);

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
template <class T>
GenTreeNode<T>* GenBST<T>::getSuccessor(GenTreeNode<T> *d) //find node to replace d
{
  GenTreeNode<T> *sp = d;
  GenTreeNode<T> *success = d;
  GenTreeNode<T> *curr = d->right;

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

#endif
