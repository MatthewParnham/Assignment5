#ifndef GENTREENODE_H
#define GENTREENODE_H


#include <iostream>
using namespace std;

//template class================================================================
template <class T>
class GenTreeNode
{
  public:
    GenTreeNode();
    GenTreeNode(T k);
    ~GenTreeNode();

    T key;
    GenTreeNode *left;
    GenTreeNode *right;
};

//template functions============================================================
template <class T>
GenTreeNode<T>::GenTreeNode()
{
    key = 0;
    left = NULL;
    right = NULL;
}

template <class T>
GenTreeNode<T>::GenTreeNode(T k)
{
  key = k;
  left = NULL;
  right= NULL;
}

template <class T>
GenTreeNode<T>::~GenTreeNode()
{
  delete right;
  delete left;
}


#endif
