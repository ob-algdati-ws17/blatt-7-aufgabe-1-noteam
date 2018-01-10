#include "testList.h"
#include <memory>
#include <vector>

using namespace std;

// empty list


TEST (testList, Empty_Tree) {
    avlTree tree;
    EXPECT_EQ(nullptr, tree.inorder());
}

TEST (testList, Insert_One) {
    avlTree tree;
    tree.insert(4);
    EXPECT_TRUE(tree.search(4));
}

TEST(testList, InOrder) {
    avlTree tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    auto vector1 = new vector<int>{1,2,3};
    EXPECT_EQ(vector1, tree.inorder());
}

TEST(testList, InsertTwiceSameValue) {
    avlTree tree;
    tree.insert(3);
    tree.insert(3);
    auto vector1 = new vector <int> {3};
    EXPECT_EQ(vector1,tree.inorder());
}

TEST(testList, InsertOneDeleteOne) {
    avlTree tree;
    tree.insert(3);
    tree.remove(3);
    EXPECT_EQ(nullptr,tree.inorder());
}

TEST(testList, InsertOneCaseOneAndTwo) {
    avlTree tree;
    tree.insert(5);
    tree.insert(6);
    //Einfügen Rechts Fall 2
    auto vector1 = new vector <int>{5,6};
    EXPECT_EQ(vector1, tree.inorder());
    // Einfügen Links Fall 1
    tree.insert(4);
    auto vector2 = new vector <int>{4,5,6};
    EXPECT_EQ(tree.inorder(),vector2);
    // Einfügen Links Fall 2
    auto vector3 = new vector <int> {3,4,5,6};
    tree.insert(3);
    EXPECT_EQ(tree.inorder(),vector3);
    //Einfügen rechts Fall 1
    vector3->push_back(7);
    tree.insert(7);
    EXPECT_EQ(tree.inorder(),vector3);
}

TEST(testList, RotateRight_RotateLeft) {
    avlTree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    auto vector1 = new vector <int> {3,4,5};
    EXPECT_EQ(vector1,tree.inorder());
    avlTree tree2;
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(7);
    auto vector2 = new vector <int> {3,4,5,6};
    EXPECT_EQ(vector2,tree.inorder());
}

TEST(testList, RotateLeftRight_RightLeft) {
    avlTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    auto vector1 = new vector <int> {3,4,5};
    EXPECT_EQ(vector1,tree.inorder());
    avlTree tree2;
    tree2.insert(5);
    tree2.insert(7);
    tree2.insert(6);
    auto vector2 = new vector <int> {5,6,7};
    EXPECT_EQ(vector2,tree.inorder());
}