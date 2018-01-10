#include "avlTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdio>
//
// Created by hm-nwimmer on 19.12.2017.
//


using namespace std;
//-----Destruct Tree------//

avlTree::~avlTree() {
    delete firstNode;
}

//-----Node Methoden------//

avlTree::Node::Node(int key, Node* parent) : key(key),parent(parent) {
    this->right = nullptr;
    this->left  = nullptr;
}

avlTree::Node::Node(int key, Node* lastNode, Node* left, Node* right, int balance) : key(key),parent(lastNode),left(left), right(right), balance(balance) {
}

avlTree::Node::~Node() {
    delete left;
    delete right;
}



bool avlTree::Node::hasChild() const {
    return left != nullptr || right != nullptr;
}

//----private Methoden-----//


avlTree::Node *avlTree::getSymmetricFollower(Node *node) {
    Node* current = node->right;
    while (true) {
        if (current->left == nullptr) {
            return current;
        } else {
            current = current->left;
        }
    }
}


//Balancing Methoden
void avlTree::upIn(Node *start) {
    if (start != nullptr && start->parent != nullptr) {
        if (start == firstNode) {
            return;
        } else {
            if (start->key < start->parent->key) {
                if (start->parent->balance = 1){
                    start->parent->balance = 0;
                } else if (start->parent->balance = 0) {
                    start->parent->balance = -1;
                    upIn(start->parent);
                } else if (start->parent->balance = -1){
                    rotateRight(start->parent);
                } else {
                    Node *parent = start->parent;
                    rotateLeft(start);
                    rotateRight(parent);
                }
            } else if (start->key > start->parent->key) {
                if (start->parent->balance = -1) {
                    start->parent->balance = 0;
                } else if (start->parent->balance = 0) {
                    start->parent->balance = 1;
                    upIn(start->parent);
                } else if (start->balance = 1) {
                    rotateLeft(start->parent);
                } else {
                    Node *parent = start->parent;
                    rotateRight(start);
                    rotateLeft(parent);
                }
            }
        }
    }

}

void avlTree::upOut(Node* start){
    //Linke Seite
    if (start != nullptr && start->parent) {
        // linker Nachfolger
        if (start->parent->left == start) {
            // Fall 1.1 bal P* = -1
            if (start->parent->balance == -1) {
                start->parent->balance = 0;
                upOut(start->parent);
            }
            // Fall 1.2 bal P* = 0
            else if (start->parent->balance == 0) {
                start->parent->balance = 1;
                // fertig
            // Fall 1.3
            } else {
                // Fall 1.3.1
                if (start->parent->right->balance == 0) {
                    rotateLeft(start->parent);
                // Fall 1.3.2
                } else if (start->parent->right->balance == 1) {
                    Node* myR = start->parent->right;
                    rotateLeft(start->parent);
                    upOut(myR);
                // Fall 1.3.3
                } else {
                    Node* myR = start->parent->right->left;
                    rotateRight(start->parent->right);
                    rotateLeft(start->parent);
                    upOut(myR);
                }

            }
        // Rechter Nachfolger
        } else {
            // Fall 2.1
            if (start->parent->balance == -1) {
                start->parent->balance = 0;
                upOut(start->parent);
            }
            // Fall 2.2
            else if (start->parent->balance == 0) {
                start->parent->balance = 1;
                // fertig
            }
            // Fall 2.3
            else {
                // Fall 2.3.1
                if (start->parent->left->balance == 0) {
                    rotateRight(start->parent);
                }
                // Fall 2.3.2
                else if (start->parent->right->balance == 1){
                    Node* myR = start->parent->left->right;
                    rotateRight(start->parent);
                    upOut(myR);
                }
                // Fall 2.3.3
                else {
                    Node* myR = start->parent->left->right;
                    rotateLeft(start->parent->right);
                    rotateRight(start->parent);
                    upOut(myR);
                }
            }
        }
    }
}

// rotate Methoden


void avlTree::rotateLeft(Node* node) {

    Node *rightside = node->right;
    Node *saveParent = node->parent;
    Node *t2 = node->right->left;
    if (saveParent == nullptr) {
        firstNode = rightside;
        firstNode->left = node;
        node->left = t2;
    } else {
       saveParent->right = rightside;
        saveParent->balance -= 1;
        rightside->right = node;
        rightside->balance -= 1;
        node->right = t2;
}
}

void avlTree::rotateRight(Node* node) {
    Node* leftside = node->left;
    Node* saveParent = node->parent;
    Node* t2 = node->left->right;
    if (saveParent == nullptr) {
        firstNode = leftside;
        firstNode->right = node;
        node->right = t2;
    } else {
        saveParent->left = leftside;
        saveParent->balance += 1;
        leftside->right = node;
        leftside->balance +=1;
        node->left = t2;
    }
}


int avlTree::getHeight(Node* p) {
    return max(p->left == nullptr ? 0 : getHeight(p->left) + 1, p->right == nullptr ? 0 : getHeight(p->right) + 1);
}


//----public Methoden-----//



void avlTree::insert(const int value) {
    if (search(value)) {
        return;
    }else if(firstNode==nullptr) {
        firstNode = new Node(value, nullptr);
    } else {
        Node *current = firstNode;
        while (true) {
            bool isRight = current->key < value;
            if (isRight) {
                if(current->right == nullptr) {
                    current->right = new Node(value,current);
                    upIn(current->left);
                    break;
                } else {
                    current = current->right;
                }
            } else {
                if(current->left == nullptr) {
                    current->left = new Node(value, current);
                    upIn(current->left);
                    break;
                } else {
                    current = current->left;
                }
            }
    }
    }
}


bool avlTree::search(const int value) const {
    search(value,firstNode);
}

bool avlTree::search(const int value, Node *node) const {
    if (node == nullptr) {
        return false;
    } else if (node->key == value) {
        return true;
    } else if (value < node->key) {
        return search(value,node->left);
    } else if ( value > node->key) {
        return search(value,node->right);
    }
}




void avlTree::remove(const int value) {
    if (!search(value)) {
        return;
    } else {
        remove(value,firstNode);
    }
}

void avlTree::remove(const int value, Node *node) {
    if (node == firstNode && !node->hasChild()) {
        delete node;
        firstNode = nullptr;
        return;
    }
    Node* parent1 = node->parent;
    int q = 0;
        if (node->key == value) {
            if (!node->hasChild()) {
                if (node == node->parent->left) {
                    node->parent->left = nullptr;
                    q = getHeight(node->parent);
                    if (q == 1) {
                        node->parent->balance = 1;
                    } else if (q == 0) {
                        upOut(node->parent);
                    } else {
                        if (node->parent->right->left != nullptr) {
                            rotateRight(node->parent->right);
                            rotateLeft(node->parent);
                        } else {
                            rotateLeft(node->parent);
                        }
                        upOut(node->parent);
                    }
                } else {
                    node->parent->right = nullptr;
                    q = getHeight(node->parent);
                    if (q == 1) {
                        node->parent->balance = 1;
                    } else if (q == 0) {
                        upOut(node->parent);
                    } else {
                        if (node->parent->left->right != nullptr) {
                            rotateLeft(node->parent->left);
                            rotateRight(node->parent);
                        } else {
                            rotateRight(node->parent);
                        }
                        upOut(node->parent);
                    }
                }
                upOut(node->parent);

                // Fall 2 1 Knoten 1 Leaf
            } else if (node->left || node->right == nullptr) {
                if (node->parent->left == node) {
                    // Links kein Blatt
                    if (node->left == nullptr) {
                        parent1->left = node->right;
                        parent1->balance += 1;
                        parent1->left->right = nullptr;
                    } else {
                        parent1->left = node->left;
                        parent1->balance -= 1;
                        parent1->left->left = nullptr;
                    }
                    node->parent->left->parent = node->parent;
                } else {
                    if (node->left == nullptr) {
                        parent1->right = node->right;
                        parent1->balance += 1;
                        parent1->right->right = nullptr;
                    } else {
                        parent1->right = node->left;
                        parent1->balance -= 1;
                        parent1->right->left = nullptr;
                    }
                    node->parent->right->parent = node->parent;
                }
                upOut(node->parent);
            }
                // Fall 3 Beide Nachfolger Knoten
                // Symmetrischer Nachfolger
            else {
                Node *symmetric = getSymmetricFollower(node);
                node->key = symmetric->key;
                remove(value, symmetric);
            }
        } else {
            if (node->left != nullptr) {
                remove(value, node->left);
            }
            if (node->right != nullptr) {
                remove(value, node->right);
            }
        }

}

std::vector<int> *avlTree::inorder() const {
    if (firstNode == nullptr) {
        return nullptr;
    } else {
        auto* tree = new std::vector<int>();
        inorder(firstNode,tree);
        for(auto i = tree->begin(); i != tree->end(); i++)
        {
            std::cout<<*i<<endl;
        }
        return tree;
    }
}

std::vector<int> *avlTree::inorder(Node *node, std::vector<int> *tree) const {
    // Linke seite
    if (node->left != nullptr) {
        inorder(node->left, tree);
    }
    tree->push_back(node->key);
    // Rechte Seite
    if (node->right != nullptr) {
        inorder(node->right,tree);
    }
    return tree;
}
