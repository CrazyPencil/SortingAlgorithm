#include "binarytree.h"

bool BinaryTree::empty()
{
    if(TreeSize==0)
        return true;
    else
        return false;
}

void BinaryTree::find(int temp)
{
    if(TreeSize==0)
    {
        cout<<"empty tree!"<<endl;return;
    }
    Node *p=Root;
    while(p!=nullptr)
    {
        if(p->key==temp)
        {
            cout<<p->key;return;
        }
        else
           {
             if(p->key>temp)
                 p=p->liftchild;
             else
                 p=p->rightchild;
           }
    }
    if(p==nullptr)
    {
        cout<<"Search Failed!";
        return;
    }
}

void BinaryTree::insert(int tempkey)
{
   Node *p=Root;
   Node *pp=nullptr;
   while(p!=nullptr)
   {
       pp=p;
       if(p->key<tempkey)
           p=p->rightchild;
       else
       {
           if(p->key>tempkey)
               p=p->liftchild;
           else
           {
               cout<<"Already exist"<<endl;
               return;
           }

       }
   }
   Node *newnode=new Node;
   newnode->key=tempkey;
   if(Root==nullptr)
       Root=newnode;
   else
   {
       if(pp->key>tempkey)
           pp->liftchild=newnode;
       else
           pp->rightchild=newnode;
   }
   TreeSize++;
   cout<<"Insret succeed"<<endl;
}

void BinaryTree::erase(int tempkey)  //二叉树删除操作
{
    if(TreeSize==0)
    {
        cout<<"empty tree!"<<endl;return;
    }
    Node *pp=nullptr;
    Node *p=Root;
    while(p!=nullptr && p->key!=tempkey)
    {
        pp=p;    //获得要删除节点的父节点
        if(p->key>tempkey)
            p=p->liftchild;
         else
            p=p->rightchild;
    }
    if(p==nullptr)
    {
        cout<<"Search Failed!"; return;
    }
     cout<<"search succeed!"<<endl;
     if(p->liftchild!=nullptr && p->rightchild!=nullptr)  //节点p有两个子树
     {
         Node *maxnode=p->liftchild;
         Node *pmaxnode=p;
         while(maxnode->rightchild!=nullptr)
         {
             pmaxnode=maxnode;
             maxnode=maxnode->rightchild;  //找出左子树中最大的值是maxnode
         }
         p->key=maxnode->key;
         if(maxnode->liftchild != nullptr) //处理左子树最大节点有一个子树的情况
         {
             pmaxnode->rightchild=maxnode->liftchild;
             delete maxnode;
         }
         else      //处理左子树最大节点没有子树的情况
         {
             delete maxnode; pmaxnode->rightchild=nullptr;
         }
         TreeSize--;
         cout<<"delet succeed"<<endl;
         return;
     }

     if(p->liftchild !=nullptr && p->rightchild==nullptr)  //节点p有一个zuo子树
     {
        if(pp==nullptr)
            Root=p->liftchild;
        else
        {
            if(p==pp->liftchild)
                pp->liftchild=p->liftchild;
            else
                pp->rightchild=p->liftchild;
        }
         delete p;
     }

     if(p->liftchild ==nullptr && p->rightchild!=nullptr)  //节点p有一个右子树
     {
        if(pp==nullptr)
            Root=p->rightchild;
        else
        {
            if(p==pp->liftchild)
                pp->liftchild=p->rightchild;
            else
                pp->rightchild=p->rightchild;
        }
         delete p;
     }
     if(p->liftchild ==nullptr && p->rightchild==nullptr) //节点p没有子树
     {
         if(pp==nullptr)
         {
             delete p;Root=nullptr;
         }
         else
         {
             if(p==pp->liftchild)
                  {delete p; pp->liftchild=nullptr;}   //一定要记得将父节点的子树指针设为nullptr
             else
                 {delete p; pp->rightchild=nullptr;}
         }

     }
     TreeSize--;
     cout<<"delete succeed!"<<endl;
}

void BinaryTree::middleoutput(Node *temp)
{
   if(temp!=nullptr)
   {
       middleoutput(temp->liftchild);
       cout<<temp->key<<endl;
       middleoutput(temp->rightchild);
   }

}

Node *BinaryTree::RootReturn()
{return Root;

}



BinaryTree::BinaryTree()
{
    Root=nullptr;
    TreeSize=0;
}

BinaryTree::~BinaryTree()
{
    delete Root;
}

int BinaryTree::TreeSizereturn()
{
    return TreeSize;
}


