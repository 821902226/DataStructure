#include "BinTree.h"

BinTree::BinTree(int val)
{
    this->root = new Node(val);
}

void BinTree::frontTraversal(Node * node)
{
    if(node == nullptr)
    {
        return;
    }

    cout<<node->data<<" ";
    this->frontTraversal(node->left);
    this->frontTraversal(node->right);
}

void BinTree::middleTraversal(Node * node)
{
    if(node == nullptr)
    {
        return;
    }

    this->middleTraversal(node->left);
    cout<<node->data<<" ";  
    this->middleTraversal(node->right);
}

void BinTree::backTraversal(Node * node)
{
    if(node == nullptr)
    {
        return;
    }

    this->backTraversal(node->left);
    this->backTraversal(node->right);
    cout<<node->data<<" ";
}

void BinTree::leafNodeNum(Node * node, int & num)
{ 
    if(node==nullptr)
    {
        return;
    }
    if(node->left==nullptr&&node->right==nullptr)
    {
        num++;
        return;
    }
    this->leafNodeNum(node->left, num);
    this->leafNodeNum(node->right, num);
}

int BinTree::getDepth(Node * node)
{
    if(node == nullptr)
    {
        return 0;
    }

    int lDepth =  this->getDepth(node->left);
    int rDepth =  this->getDepth(node->right);

    return lDepth>rDepth?lDepth+1:rDepth+1;
}

BinTree::~BinTree()
{
    if(this->root!=nullptr)
    {
        delete this->root;
        this->root = nullptr;
    }
}