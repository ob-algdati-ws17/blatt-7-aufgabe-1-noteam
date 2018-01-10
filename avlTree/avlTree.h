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
        Node *parent = nullptr;
        int balance = 0;


        Node(int key, Node* parent);

        Node(int key, Node* parent, Node* left, Node* right, int balance);

        ~Node();


        bool hasChild();
    };
    Node* firstNode = nullptr;

    Node* getSymmetricFollower(Node* node);

    void upIn(Node* start);

    void upOut(Node* start);

    void rotateLeft(Node* rotateThis);

    void rotateRight(Node* rotateThis);

    void noLeaf(Node* removeNode);

    void leafRight(Node* removeNode);

    void leafLeft(Node* removeNode);

    void twoLeafs(Node* removeNode);

    void removeRotation(Node* previous,Node* removeNode,bool leftSide);

    int calculateBalance();

    int getHeight(Node* p);


    std::vector<int> *preorder(Node* node,std::vector<int>* tree) const;  // (Hauptreihenfolge)
    std::vector<int> *inorder(Node* node,std::vector<int>* tree) const;   // (Symmetrische Reihenfolge)
//    std::vector<int> *postorder(Node* node,std::vector<int>* tree) const; // (Nebenreihenfolge)

public :

    ~avlTree();

    void insert(const int value);
    void remove(const int value);
    void remove(const int value, Node* node);
    bool search(const int value) const;
    bool search(const int value, Node* node) const;

    std::vector<int> *preorder() const;  // (Hauptreihenfolge)
    std::vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
    std::vector<int> *postorder() const; // (Nebenreihenfolge)

};