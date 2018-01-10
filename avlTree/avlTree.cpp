#include "avlTree.h"
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



bool avlTree::Node::hasChild() {
    if (left == nullptr && right == nullptr) {
        return false;
    } else {
        return true;
    }
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
               rotateLeft(start);
               rotateRight(start->parent);
           }
        } else if (start->key > start->parent->key) {
            if (start->parent->balance = 1) {
                start->parent->balance = 0;
            } else if (start->parent->balance = 0) {
                start->parent->balance = 1;
                upIn(start->parent);
            } else if (start->balance = 1) {
                rotateLeft(start->parent);
            } else {
                rotateRight(start);
                rotateLeft(start->parent);
            }
        }
    }
}

void avlTree::upOut(Node* start){

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
        node->right = t2;
    }
}


void avlTree::removeRotation(Node* previous,Node* removeNode,bool leftSide) {

}



int avlTree::calculateBalance() {

}


int avlTree::getHeight(Node* p) {
    Node* links = p;
    Node* rechts = p;
    int leftside = 0;
    int rightside = 0;
    //Linke Höhe berechnen
    while (links->hasChild()) {
        leftside++;
        links = links->left;
    }
    while (rechts->hasChild()) {
        rightside++;
        rechts = rechts->right;
    }
    return max(rightside,leftside);
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
    if (node->key == value) {
        return true;
    } else if (value < node->key) {
        return search(value,node->left);
    } else if ( value > node->key) {
        return search(value,node->right);
    } else {
        return false;
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
    int q = 0;
   // bool right_side = true;
    if (node->key == value) {
        // Fall 1 nur Blötter
        if (!node->hasChild()) {
            if (node == node->parent->left) {
                node->parent->left = nullptr;
               // q = getHeight(node->parent);
               //  right_side = false;
            } else {
                node->parent->right = nullptr;
               // q = getHeight(node->parent);
            }
            upOut(node->parent);

            // Fall 2 1 Knoten 1 Leaf
        } else if(node->left || node->right == nullptr) {
            if (node->parent->left == node) {
                if (node->left == nullptr) {
                    node->parent->left = node->right;
                } else {
                    node->parent->left = node->right;
                }
            } else {
                if (node->left == nullptr) {
                    node->parent->right = node->right;
                } else {
                    node->parent->right = node->right;
                }
            }
            upOut(node->parent);
        }
        // Fall 3 Beide Nachfolger Knoten
        // Symmetrischer Nachfolger
        else {
            Node* symmetric = getSymmetricFollower(node);
            node->key = symmetric->key;
            remove(value, symmetric);
        }
    } else {
        remove(value,node->left);
        remove(value,node->right);
    }
}

std::vector<int> *avlTree::inorder() const {
    if (firstNode == nullptr) {
        return nullptr;
    } else {
        auto* tree = new std::vector<int>();
        inorder(firstNode,tree);
        return tree;
    }
}

std::vector<int> *avlTree::inorder(Node *node, std::vector<int> *tree) const {
    // Linke seite
    if (node->left == nullptr) {
        tree->push_back(node->key);
    } else {
        inorder(node->left, tree);
    }
    // Rechte Seite
    if (node->right == nullptr) {
        tree->push_back(node->key);
    } else {
        inorder(node->right,tree);
    }
    return tree;
}

std::vector<int> *avlTree::preorder() const {
    if (firstNode == nullptr) {
        return nullptr;
    } else {
        auto tree = new std::vector<int>();
        preorder(firstNode, tree);
    }
}

std::vector<int> *avlTree::preorder(Node *node, std::vector<int> *tree) const {
    if (node == firstNode) {
        tree->push_back(firstNode->key);
    }
    if (node->left != nullptr) {
        tree->push_back(node->key);
        preorder(node->left,tree);
    }
    if(node->right != nullptr) {
        tree->push_back(node->key);
        preorder(node->right, tree);
    }
    return tree;
}