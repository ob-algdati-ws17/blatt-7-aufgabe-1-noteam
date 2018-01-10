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