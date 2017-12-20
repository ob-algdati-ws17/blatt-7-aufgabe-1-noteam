//
// Created by hm-nwimmer on 19.12.2017.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#endif //AVLTREE_H
class avlTree {
private :
    struct Node {
        int key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *lastNode = nullptr;
        int balance = 0;
    };

public :
    void insert(const int value);
    void remove(const int value);
    bool search(const int value) const;
};