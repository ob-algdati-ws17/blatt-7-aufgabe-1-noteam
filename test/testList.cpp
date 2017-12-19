#include "testList.h"
#include <memory>

using namespace std;

// empty list

TEST(ListTest, Test_EmptyList) {
    list<int, string> l;
    EXPECT_TRUE(l.isEmpty());
}


// insert and search

TEST(ListTest, SearchTest_OneElementInList) {
    list<int, string> l;
    std::tuple<int, string> tin(1, "Eins");
    l += tin;
    EXPECT_EQ("Eins", *l.search(1));
}
// popHead on empty list
TEST(ListTest, Test_Pophead_EmptyList) {
    list<int, string> l;
    EXPECT_TRUE(l.isEmpty());
    auto tout = l.popHead();
    std::tuple<int,string>  tin (-1,"NULL");
    EXPECT_EQ(tout ,tin);
    EXPECT_TRUE(l.isEmpty());
}

// Search Test on Empty List
TEST(ListTest, Test_SearchTest_EmptyList) {
    list<int, string> l;
    EXPECT_TRUE(l.isEmpty());
    EXPECT_EQ(l.search(2) , nullptr);
}

// isSorted on Empty List
TEST(ListTest, Test_isSorted_EmptyList) {
    list<int, string> l;
    EXPECT_TRUE(l.isEmpty());
    auto lessThan = [](int x, int y) { return x < y; };
    EXPECT_TRUE(l.isSorted(lessThan));
}

TEST(ListTest, Test_sort_EmptyList) {
    list<int, string> l;
    EXPECT_TRUE(l.isEmpty());
    auto lessThan = [](int x, int y) { return x < y; };
    l.sort(lessThan);
    EXPECT_TRUE(l.isSorted(lessThan));
}

// Test Sort and remove on List with 3 elements.
// Expection: l still sorted when I remove something
TEST(ListTest, Test_sort_remove_stillSorted) {
    list<int, string> l;
    std::tuple<int, string> tin(1, "Eins");
    std::tuple<int, string> tin2(3, "Vier");
    std::tuple<int, string> tin1(2, "Zwei");
    auto lessThan = [](int x, int y) { return x < y; };
    l += tin;
    l += tin2;
    l += tin1;
    l.sort(lessThan);
    EXPECT_TRUE(l.isSorted(lessThan));
    l -= 2;
    EXPECT_TRUE(l.isSorted(lessThan));
}
// insert and popHead

TEST(ListTest, InsertTest_OneElementInList) {
    list<int, string> l;
    std::tuple<int, string> tin(1, "Eins");
    l += tin;
    EXPECT_FALSE(l.isEmpty());
    auto tout = l.popHead();
    EXPECT_TRUE(l.isEmpty());
    EXPECT_EQ(tin, tout);
}

TEST(ListTest, InsertTest_TwoElementsInList) {
    list<int, string> l;
    std::tuple<int, string> tin1(1, "Eins");
    std::tuple<int, string> tin2(2, "Zwei");
    l += tin1;
    l += tin2;
    EXPECT_FALSE(l.isEmpty());
    auto tout1 = l.popHead();
    EXPECT_FALSE(l.isEmpty());
    EXPECT_EQ(tin1, tout1);
    auto tout2 = l.popHead();
    EXPECT_TRUE(l.isEmpty());
    EXPECT_EQ(tin2, tout2);
}

TEST(ListTest, InsertTest_TwoElementsWithSameKey) {
    list<int, string> l;
    std::tuple<int, string> tin1(1, "Eins");
    std::tuple<int, string> tin2(1, "Zwei");
    l += tin1;
    l += tin2;
    EXPECT_FALSE(l.isEmpty());
    auto tout1 = l.popHead();
    EXPECT_TRUE(l.isEmpty());
    EXPECT_EQ(tin2, tout1);
}

// remove

TEST(ListTest, RemoveTest_OneElementInList) {
    list<int, string> l;
    std::tuple<int, string> tin(1, "Eins");
    l += tin;
    EXPECT_FALSE(l.isEmpty());
    l -= 1;
    EXPECT_TRUE(l.isEmpty());
}

TEST(ListTest, RemoveTest_TwoElementsInListRemove1_2) {
    list<int, string> l;
    std::tuple<int, string> tin1(1, "Eins");
    std::tuple<int, string> tin2(2, "Zwei");
    l += tin1;
    l += tin2;
    EXPECT_FALSE(l.isEmpty());
    l -= 1;
    EXPECT_FALSE(l.isEmpty());
    l -= 2;
    EXPECT_TRUE(l.isEmpty());
}

TEST(ListTest, RemoveTest_TwoElementsInListRemove2_1) {
    list<int, string> l;
    std::tuple<int, string> tin1(1, "Eins");
    std::tuple<int, string> tin2(2, "Zwei");
    l += tin1;
    l += tin2;
    EXPECT_FALSE(l.isEmpty());
    l -= 2;
    EXPECT_FALSE(l.isEmpty());
    l -= 1;
    EXPECT_TRUE(l.isEmpty());
}

TEST(ListTest, RemoveTest_TwoElementsWithSameKey) {
    list<int, string> l;
    std::tuple<int, string> tin1(1, "Eins");
    std::tuple<int, string> tin2(1, "Zwei");
    l += tin1;
    l += tin2;
    EXPECT_FALSE(l.isEmpty());
    l -= 1;
    EXPECT_TRUE(l.isEmpty());
}

// sort

TEST(ListTest, SortTest_TwoElementsInList) {
    list<int, string> l;
    std::tuple<int, string> tin1(1, "Eins");
    std::tuple<int, string> tin2(2, "Zwei");
    l += tin2;
    l += tin1;
    auto lessThan = [](int x, int y) { return x < y; };
    EXPECT_FALSE(l.isSorted(lessThan));
    l.sort(lessThan);
    EXPECT_TRUE(l.isSorted(lessThan));
}

TEST(ListTest, SortTest_ThreeElementsInList) {
    list<int, string> l;
    std::tuple<int, string> tin1(1, "Eins");
    std::tuple<int, string> tin2(2, "Zwei");
    std::tuple<int, string> tin3(3, "Drei");
    l += tin3;
    l += tin2;
    l += tin1;
    auto lessThan = [](int x, int y) { return x < y; };
    EXPECT_FALSE(l.isSorted(lessThan));
    l.sort(lessThan);
    EXPECT_TRUE(l.isSorted(lessThan));
}

TEST(ListTest, SortTest_SevenElementsInList) {
    list<int, string> l;
    std::tuple<int, string> tin1(2, "");
    std::tuple<int, string> tin2(15, "");
    std::tuple<int, string> tin3(43, "");
    std::tuple<int, string> tin4(17, "");
    std::tuple<int, string> tin5(4, "");
    std::tuple<int, string> tin6(8, "");
    std::tuple<int, string> tin7(47, "");
    l += tin1;
    l += tin2;
    l += tin3;
    l += tin4;
    l += tin5;
    l += tin6;
    l += tin7;
    auto lessThan = [](int x, int y) { return x < y; };
    EXPECT_FALSE(l.isSorted(lessThan));
    l.sort(lessThan);
    EXPECT_TRUE(l.isSorted(lessThan));
    auto greaterThan = [](int x, int y) { return x > y; };
    EXPECT_FALSE(l.isSorted(greaterThan));
    l.sort(greaterThan);
    EXPECT_TRUE(l.isSorted(greaterThan));
}
