#include "avltree.h"

//私有接口
int AVLTree::height(AVLTreeNode *tree)
{
    if(tree!=nullptr)
        return tree->height;
    return 0;
}

AVLTreeNode *AVLTree::LL(AVLTreeNode *k2) //左左
{
    AVLTreeNode* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height(k2->left), height(k2->right)) + 1;
    k1->height = max( height(k1->left), k2->height) + 1;

    return k1;
}

AVLTreeNode *AVLTree::RR(AVLTreeNode *k1)
{
    AVLTreeNode* k2;

        k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;

        k1->height = max( height(k1->left), height(k1->right)) + 1;
        k2->height = max( height(k2->right), k1->height) + 1;

        return k2;
}

AVLTreeNode *AVLTree::LR(AVLTreeNode *k3)
{
    k3->left = RR(k3->left);

    return LL(k3);
}

AVLTreeNode *AVLTree::RL(AVLTreeNode *k1)
{
    k1->right = LL(k1->right);

    return RR(k1);
}

AVLTreeNode *AVLTree::insert(AVLTreeNode *&tree, int key)   //注意这里传参要使用引用
{
    if (tree == NULL)
        {
            // 新建节点
            tree = new AVLTreeNode(key, NULL, NULL);
            if (tree==NULL)
            {
                cout << "ERROR: create avltree node failed!" << endl;
                return NULL;
            }
        }
        else if (key < tree->key) // 应该将key插入到"tree的左子树"的情况
        {
            tree->left = insert(tree->left, key);
            // 插入节点后，若AVL树失去平衡，则进行相应的调节。
            if (height(tree->left) - height(tree->right) == 2)
            {
                if (key < tree->left->key)
                    tree = LL(tree);
                else
                    tree = LR(tree);
            }
        }
        else if (key > tree->key) // 应该将key插入到"tree的右子树"的情况
        {
            tree->right = insert(tree->right, key);
            // 插入节点后，若AVL树失去平衡，则进行相应的调节。
            if (height(tree->right) - height(tree->left) == 2)
            {
                if (key > tree->right->key)
                    tree = RR(tree);
                else
                    tree = RL(tree);
            }
        }
        else //key == tree->key)
        {
            cout << "Already exist!" << endl;
        }

        tree->height = max( height(tree->left), height(tree->right)) + 1;   //这里要更新节点高度的原因是：因为插入节点之后 相关路径上的节点高度都会变化

        return tree;
}

AVLTreeNode *AVLTree::remove(AVLTreeNode *&tree, int key)  //删除节点函数   传参使用引用
{
    if(tree==NULL)    //若果删除空节点  则返回空
        return NULL;
    if(key < tree->key)   //待删除节点在tree的左子树中
    {
        tree->left=remove(tree->left,key);
        if(height(tree->right)-height(tree->left) ==2 )  //如果破坏平衡 则进行旋转
        {
            AVLTreeNode *r=tree->right;
            if(height(r->left) > height(r->right))
                tree=RL(tree);
            else
                tree=RR(tree);
        }
    }
    else if(key > tree->key)
    {
        tree->right=remove(tree->right,key);
        if(height(tree->left)-height(tree->right) ==2 )  //如果破坏平衡 则进行旋转
        {
            AVLTreeNode *l=tree->left;
            if(height(l->left) > height(l->right))
                tree=LL(tree);
            else
                tree=LR(tree);
        }
    }
    else   //tree就是要删除的点
    {

    }
}

void AVLTree::MidOrder(AVLTreeNode *tree)
{
    if(tree!=nullptr)
    {
        MidOrder(tree->left);
        cout<<tree->key<<' ';
        MidOrder(tree->right);
    }
}






//公有接口
AVLTree::AVLTree():mRoot(nullptr)
{

}

AVLTree::~AVLTree()
{

}

int AVLTree::height()
{
    return height(mRoot);
}

int AVLTree::max(int a, int b)
{
    return a>=b? a:b;
}

void AVLTree::insert(int key)
{
    insert(mRoot,key);
}

void AVLTree::MidOrder()
{
    MidOrder(mRoot);
}


