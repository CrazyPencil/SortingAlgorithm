#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

struct Node
{
    int key=0;
    Node *liftchild=nullptr;
    Node *rightchild=nullptr;
};



class BinaryTree
{
    Node *Root;
    int TreeSize;
public:

    BinaryTree();
    ~BinaryTree();
    int TreeSizereturn();
    bool empty();
    void find(int temp);
    void insert(int tempkey);
    void erase(int tempkey);
    void middleoutput(Node *temp);
    Node *RootReturn();
};

#endif // BINARYTREE_H
