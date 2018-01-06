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


        Node(int key, Node* lastNode);

        Node(int key, Node* lastNode, Node* left, Node* right, int balance);

        ~Node();

        void calculateBalance();

        bool hasChild();
    };
    Node* firstNode = nullptr;

    void upIn(Node* start);

    void upOut(Node* start);

    void rotateLeft(Node* rotateThis);

    void rotateRight(Node* rotateThis);

    Node* searchRecursive(Node* start, int key, bool previous);

    void noLeaf(Node* removeNode);

    void leafRight(Node* removeNode);

    void leafLeft(Node* removeNode);

    void twoLeafs(Node* removeNode);

    void removeRotation(Node* previous,Node* removeNode,bool leftSide);

public :

    ~avlTree();

    void insert(const int value);
    void remove(const int value);
    bool search(const int value) const;

    std::vector<int> *preorder() const;  // (Hauptreihenfolge)
    std::vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
    std::vector<int> *postorder() const; // (Nebenreihenfolge)

};