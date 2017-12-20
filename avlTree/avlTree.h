//
// Created by hm-nwimmer on 19.12.2017.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#endif //AVLTREE_H

#include <iostream>
#include <vector>

using namespace std;

class avlTree {
private :
    struct Node {
        int key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *lastNode = nullptr;
        int balance = 0;

        vector<int> *preorder() const;  // (Hauptreihenfolge)
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)
    };

public :

    ~AVLTree();

    void insert(const int value);
    void remove(const int value);
    bool search(const int value) const;

    std::vector<int> *preorder() const;  // (Hauptreihenfolge)
    std::vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
    std::vector<int> *postorder() const; // (Nebenreihenfolge)

};