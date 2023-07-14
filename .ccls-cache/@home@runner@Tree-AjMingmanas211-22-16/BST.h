#ifndef bst_h
#define bst_h

#include "node.h"

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  void kill(TreeNodePtr);
  void insert_node(int);
  void print_all(int = 3);
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr, int);
  int get_height(TreeNodePtr);
};

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNodePtr new_node, tmp;
  
  new_node = new TreeNode(value);
  if (new_node) {
    if (!rootPtr) {
      rootPtr = new_node;
    }
    else{
      tmp = rootPtr;
      while(!inserted){
        if(value <= tmp->get_value()){
          if(tmp->move_left()){
            tmp = tmp->move_left();
          }
          else{
            tmp->set_left(new_node);
            inserted = 1;
          }
        }
        else{
          if(tmp->move_right()){
            tmp = tmp->move_right();
          }
          else{
            tmp->set_right(new_node);
            inserted = 1;
          }
        }
      }
    }
    ++size;
  }
}

BST::BST() {
  rootPtr = nullptr;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
    kill(rootPtr);
}

void BST::inOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    inOrder(treePtr->move_left());
    cout << treePtr->get_value() << " ";
    inOrder(treePtr->move_right());
  }
}

void BST::printTree(TreeNodePtr treePtr, int l) { 
  
  if (treePtr) {
    if(treePtr->move_right()){
      printTree(treePtr->move_right() , l + 4);
    }
    if(l){
      cout << setw(l) << " ";
    }
    if(treePtr->move_right()){
      cout << " /\n" << setw(l) << " ";
    }
    cout << treePtr->get_value() << "\n";

    if(treePtr->move_left()){
      cout << setw(l) << " " <<" \\\n";
      printTree(treePtr->move_left(), l + 4);
    }
  }    
}

void BST::postOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    postOrder(treePtr->move_left());
    postOrder(treePtr->move_right());
    cout << treePtr->get_value() << " ";
  }
}

void BST::kill(TreeNodePtr treePtr) {
  if (treePtr) {
    kill(treePtr->move_left());
    kill(treePtr->move_right());
    delete treePtr;
  }
}

void BST::preOrder(TreeNodePtr treePtr) {
  if(treePtr){
    cout << treePtr->get_value() << " ";
    preOrder(treePtr->move_left());
    preOrder(treePtr->move_right());
  }
}

void BST::print_all(int option) {
   switch(option){
    case 0: 
      cout << "inorder" << "\n";
      inOrder(rootPtr);
      cout << "\n";
      break;
    case 1: 
      cout << "preorder" << "\n";
      preOrder(rootPtr);
      cout << "\n";
      break;
    case 2:
      cout << "postorder" << "\n";
      postOrder(rootPtr);
      cout << "\n";
      break;
    default: 
      cout << "inorder" << "\n";
      inOrder(rootPtr);
      cout << "\n";
      cout << "preorder" << "\n";
      preOrder(rootPtr);
      cout << "\n";
      cout << "postorder" << "\n";
      postOrder(rootPtr);
      cout << "\n";
      cout << "Tree" << "\n";
      printTree(rootPtr, 1);
      cout << "\n";
      break;
    }
}

int BST::get_height(TreeNodePtr treePtr){
  if(!treePtr){
    return 0;
  }
  else {
    return 1 + max(get_height(treePtr->move_left()), get_height(treePtr->move_right()));
  }
}

#endif