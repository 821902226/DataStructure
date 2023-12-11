#include "Node.h"

Node::Node(int val)
{
    this->data = val;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
    if(this->left!=nullptr)
    {
        delete this->left;
        this->left = nullptr;
    }
    if(this->right!=nullptr)
    {
        delete this->right;
        this->right = nullptr;
    }
}