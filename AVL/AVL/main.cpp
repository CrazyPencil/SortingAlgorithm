#include <avltree.h>


int main()
{
    AVLTree *mytree=new AVLTree;
    mytree->insert(1);
    mytree->insert(2);
    mytree->insert(5);
    mytree->insert(3);
    mytree->MidOrder();
}
