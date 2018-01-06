//
// Created by hm-nwimmer on 19.12.2017.
//
#include <vector>
#include "avlTree.h"

using namespace std;
//-----Destruct Tree------//

avlTree::~avlTree() {
    delete firstNode;
}

//-----Node Methoden------//

avlTree::Node::Node(int key, Node* lastNode) : key(key),lastNode(lastNode) {
    this->right = nullptr;
    this->left  = nullptr;
}

avlTree::Node::Node(int key, Node* lastNode, Node* left, Node* right, int balance) : key(key),lastNode(lastNode),left(left), right(right), balance(balance) {
   this->calculateBalance();
}

avlTree::Node::~Node() {
    delete left;
    delete right;
}

void avlTree::Node::calculateBalance() {
    if (this->right == nullptr && this->left == nullptr) {
        this->balance = 0;
    } else if (this->right == nullptr) {
        this->balance = -1/*left->balance*/;
    } else if (this->left == nullptr) {
        this->balance = 1/*right->balance*/;
    } else {
        this->balance = right->balance - left->balance;
    }
}

bool avlTree::Node::hasChild() {
    if (left == nullptr && right == nullptr) {
        return false;
    } else {
        return true;
    }
}



