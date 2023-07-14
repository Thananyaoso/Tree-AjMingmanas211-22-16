#include "node.h"
#include <iostream>
#include <iomanip>

using namespace std;

class BST {
private:
    int size;
    TreeNode* rootPtr;

public:
    BST();
    ~BST();  
    void kill(TreeNode*);
    void insert_node(int);
    void print_all(int = 0);
    void inOrder(TreeNode*);
    void preOrder(TreeNode*);
    void postOrder(TreeNode*);
    int get_height(TreeNode*);
    void printTree(TreeNode*, int);
};

BST::BST() {
    rootPtr = nullptr;
    size = 0;
}

BST::~BST() {
    cout << "Kill BST" << endl;
    kill(rootPtr);
}

void BST::kill(TreeNode* treePtr) {
    if (treePtr) {
        kill(treePtr->move_left());
        kill(treePtr->move_right());
        delete treePtr;
    }
}

void BST::insert_node(int value) {
    int inserted = 0;
    TreeNode* new_node, * t;

    new_node = new TreeNode(value);
    if (new_node) {
        if (!rootPtr) {
            rootPtr = new_node;
        }
        else {
            t = rootPtr;
            while (!inserted) {
                if (value <= t->get_value()) {
                    if (t->move_left()) {
                        t = t->move_left();
                    }
                    else {
                        t->set_left(new_node);
                        inserted = 1;
                    }
                }
                else {
                    if (t->move_right()) {
                        t = t->move_right();
                    }
                    else {
                        t->set_right(new_node);
                        inserted = 1;
                    }
                }
            }
        }
        ++size;
    }
}

void BST::inOrder(TreeNode* treePtr) {
    if (treePtr) {
        inOrder(treePtr->move_left());
        cout << setw(3) << treePtr->get_value();
        inOrder(treePtr->move_right());
    }
}

void BST::printTree(TreeNode* treePtr, int l) {
    if (treePtr) {
        if (treePtr->move_right()) {
            printTree(treePtr->move_right(), l + 4);
        }
        if (l) {
            cout << setw(l) << " ";
        }
        if (treePtr->move_right()) {
            cout << " /\n" << setw(l) << " ";
        }
        cout << treePtr->get_value() << "\n";

        if (treePtr->move_left()) {
            cout << setw(l) << " " << " \\\n";
            printTree(treePtr->move_left(), l + 4);
        }
    }
}

void BST::postOrder(TreeNode* treePtr) {
    if (treePtr) {
        postOrder(treePtr->move_left());
        postOrder(treePtr->move_right());
        cout << setw(3) << treePtr->get_value() << endl;
    }
}

void BST::preOrder(TreeNode* treePtr) {
    if (treePtr) {
        cout << setw(3) << treePtr->get_value();
        preOrder(treePtr->move_left());
        preOrder(treePtr->move_right());
    }
}

int BST::get_height(TreeNode* tree) {
    if (!tree) {
        return 0;
    }
    else {
        return 1 + max(get_height(tree->move_left()), get_height(tree->move_right()));
    }
}

void BST::print_all(int option) {
    switch (option) {
    case 0:
        inOrder(rootPtr);
        cout << endl;
        break;
    case 1:
        preOrder(rootPtr);
        cout << endl;
        break;
    case 2:
        postOrder(rootPtr);
        cout << endl;
        break;
    default:
        cout << "inOrder" << endl;
        inOrder(rootPtr);
        cout << endl;
        cout << "preOrder" << endl;
        preOrder(rootPtr);
        cout << endl;
        cout << "postOrder" << endl;
        postOrder(rootPtr);
        cout << endl;
        cout << "Tree" << endl;
        printTree(rootPtr, 0);
        cout << endl;
    }
  
}

