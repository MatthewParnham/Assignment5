#include "BST.h"
#include "TreeNode.h"
#include "FileIO.h"

int main(int argc, char const *argv[]) {
  BST bst;

  bst.insert(5);
  bst.insert(6);
  bst.insert(4);
  bst.insert(3);
  bst.insert(2);
  bst.insert(1);
  bst.insert(7);
  bst.insert(8);
  bst.insert(10);
  bst.insert(9);

  bst.printTree();

  bst.deleteRec(5);
  bst.deleteRec(8);
  bst.printTree();

  return 0;
}
