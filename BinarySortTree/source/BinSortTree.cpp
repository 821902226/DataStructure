#include "BinSortTree.h"

BinSortTree::BinSortTree()
{
    this->root = nullptr;
}

BinSortTree::BinSortTree(int val)
{
    this->root = new Node(val);
}

void BinSortTree::insert(Node*& node, int val)  //这里需要传入指针的引用，指针作为函数参数时可以修改指针指向的内容，指针的引用作为函数参数时可以修改指针的指向
{
    if(node==nullptr)
    {
        node = new Node(val);
        return;
    }

    if(val<node->data)
    {
        insert(node->left, val);
    }
    else if(val>node->data)
    {
        insert(node->right, val);
    }
}

Node* BinSortTree::search(Node* node, int val)
{
    if(node==nullptr)
    {
        return nullptr;
    }

    if(val==node->data)
    {
        return node;
    }
    else if(val<node->data)
    {
        return search(node->left, val);
    }
    else
    {
        return search(node->right, val);
    }

}

Node* BinSortTree::deleteNode(Node* node, int val)
{
    if(node==nullptr)
    {
        return node;
    }

    if(val<node->data)
    {
        node->left = deleteNode(node->left, val);
    }
    else if(val>node->data)
    {
        node->right = deleteNode(node->right, val);
    }
    else{
        if(node->left==nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right==nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        //找到后继节点
        Node* successor = Min(node->right);
        node->data = successor->data;
        //递归删除后继节点
        node->right = deleteNode(node->right, successor->data);
    }
    return node;
}

Node* BinSortTree::Min(Node* node)
{
    if(node==nullptr)   // 树为空
    {
        return nullptr;
    }

    if(node->left==nullptr)
    {
        return node;
    }
    else
    {
        return Min(node->left);
    }
}

Node* BinSortTree::Max(Node* node)
{
    if(node==nullptr)   // 树为空
    {
        return nullptr;
    }

    if(node->right==nullptr)
    {
        return node;
    }
    else
    {
        return Max(node->right);
    }
}

void BinSortTree::frontTraversal(Node * node)
{
    if(node == nullptr)
    {
        return;
    }

    cout<<node->data<<" ";
    this->frontTraversal(node->left);
    this->frontTraversal(node->right);
}

void BinSortTree::middleTraversal(Node * node)
{
    if(node == nullptr)
    {
        return;
    }

    this->middleTraversal(node->left);
    cout<<node->data<<" ";  
    this->middleTraversal(node->right);
}

void BinSortTree::backTraversal(Node * node)
{
    if(node == nullptr)
    {
        return;
    }

    this->backTraversal(node->left);
    this->backTraversal(node->right);
    cout<<node->data<<" ";
}

void BinSortTree::leafNodeNum(Node * node, int & num)
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

int BinSortTree::getDepth(Node * node)
{
    if(node == nullptr)
    {
        return 0;
    }

    int lDepth =  this->getDepth(node->left);
    int rDepth =  this->getDepth(node->right);

    return lDepth>rDepth?lDepth+1:rDepth+1;
}

BinSortTree::~BinSortTree()
{
    if(this->root!=nullptr)
    {
        delete this->root;
        this->root = nullptr;
    }
}