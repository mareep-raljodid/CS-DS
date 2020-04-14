#include <gtest/gtest.h>
#include "hashTable.h"
#include "bst.h"

TEST(BinaryTree, getAllDescendingTEST) {

    BinaryTree t;
    t.insert(1);
    t.insert(2);
    EXPECT_EQ(210, t.getAllDescendingTEST());
}

TEST(BinaryTree, getAllAscendingTEST) {

    BinaryTree t;
    t.insert(1);
    t.insert(2);
    EXPECT_EQ(120, t.getAllAscendingTEST());
}

TEST(HashTable, findItem) {
    HashTable h;
    h.addItem(13);
    h.addItem(2);
    h.addItem(114);

    EXPECT_EQ(2, h.findItem(2));
    EXPECT_EQ(13, h.findItem(13));
    EXPECT_EQ(114, h.findItem(114));
    EXPECT_EQ('\0', h.findItem(55));
}
