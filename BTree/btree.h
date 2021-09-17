#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
#include "node.h"

class BTree {
    TreeNode* root;
    int t;

public:
    BTree(int temp) {
        root = NULL;
        t = temp;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    TreeNode* search(int k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void insert(int k);
};

#endif