#include "BST.h"
#include "TreeNode.h"
#include "FileIO.h"

int main(int argc, char const *argv[]) {
  BST bst;

  bst.insert(5);
  bst.printTree();

  cout << endl;
  bst.insert(6);
  bst.printTree();

  cout << endl;

  bool object;
  object = bst.contains(5);
  cout << object << endl;

  bst.deleteRec(5);
  object = bst.contains(5);

  bst.printTree();

  cout << endl;

  return 0;
}
