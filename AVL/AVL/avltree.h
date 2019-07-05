#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

#include <iomanip>
#include <iostream>
using namespace std;


class AVLTreeNode{
    public:
        int key;                // 关键字(键值)
        int height;         // 高度
        AVLTreeNode *left;    // 左孩子
        AVLTreeNode *right;    // 右孩子

        AVLTreeNode(int value, AVLTreeNode *l, AVLTreeNode *r):
            key(value), height(0),left(l),right(r) {}
};


class AVLTree {
    private:
        AVLTreeNode *mRoot;    // 根结点
        int height(AVLTreeNode* tree);   //获取节点高度
        AVLTreeNode* LL(AVLTreeNode* k2);
        AVLTreeNode* RR(AVLTreeNode* k1);
        AVLTreeNode* LR(AVLTreeNode* k3);
        AVLTreeNode* RL(AVLTreeNode* k1);
        AVLTreeNode* insert(AVLTreeNode* &tree, int key);
        AVLTreeNode* remove(AVLTreeNode* &tree, int key);
        void MidOrder(AVLTreeNode* tree);


    public:
        AVLTree();
        ~AVLTree();
        // 获取树的高度
        int height();
        // 获取树的高度
        int max(int a, int b);
        //插入函数
        void insert(int key);
        void MidOrder();


};



#endif
