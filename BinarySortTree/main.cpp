#include <iostream>
#include "Node.h"
#include "BinSortTree.h"

using namespace std;

int main()
{
    //创建一个二叉排序树
    BinSortTree *tree = new BinSortTree();
    tree->insert(tree->root, 5);
    tree->insert(tree->root, 3);
    tree->insert(tree->root, 7);
    tree->insert(tree->root, 9);
    tree->insert(tree->root, 4);
    tree->insert(tree->root, 1);
    tree->insert(tree->root, 2);
    tree->insert(tree->root, 6);
    tree->insert(tree->root, 8);

    //中序遍历，可以让节点值从小到大输出
    tree->middleTraversal(tree->root);
    cout<<endl;

    //查找节点
    Node* node = tree->search(tree->root, 6);
    if(node)
    {
        cout<<"Find the node: "<<node->data<<endl;
    }
    else
    {
        cout<<"The node was not found."<<endl;
    }

    //查找最大值
    Node * node_max =  tree->Max(tree->root);
    if(node_max)
    {
        cout<<"The max value is: "<<node_max->data<<endl;
    }
    else
    {
        cout<<"The tree is empty."<<endl;
    }

    //查找最小值
    Node * node_min =  tree->Min(tree->root);
    if(node_min)
    {
        cout<<"The min value is: "<<node_min->data<<endl;
    }
    else
    {
        cout<<"The tree is empty."<<endl;
    }

    //删除指定节点
    tree->deleteNode(tree->root, 5);
    tree->middleTraversal(tree->root);
    cout<<endl;

    system("pause");
}