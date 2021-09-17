#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

class TreeNode {
    int* keys;
    int t;
    TreeNode** C;
    int n;
    bool leaf;

public:
    TreeNode(int temp, bool bool_leaf);

    void insertNonFull(int k);
    void splitChild(int i, TreeNode* y);
    void traverse();

    TreeNode* search(int k);

    friend class BTree;
};

#endif