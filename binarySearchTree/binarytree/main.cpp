#include <iostream>
#include"binarytree.h"

int main()
{
    BinaryTree mytree;
    mytree.insert(16);
    mytree.insert(19);
    mytree.insert(13);
   // mytree.erase(13);
    mytree.insert(15);
    mytree.insert(14);
    mytree.insert(10);
    mytree.insert(9);
    cout<<mytree.TreeSizereturn()<<endl;
    mytree.middleoutput(mytree.RootReturn());
}
