#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class BinSortTree
{
    public:
        Node * root;

        BinSortTree();
        BinSortTree(int val);
        ~BinSortTree();

        //插入节点
        void insert(Node*& node, int val);

        //查找节点
        Node* search(Node* node, int val);

        //删除节点
        Node* deleteNode(Node* node, int val);

        //查找最小值
        Node* Min(Node* node);

        //查找最大值
        Node* Max(Node* node);

        //先序遍历
        void frontTraversal(Node * node);

        //中序遍历
        void middleTraversal(Node * node);

        //后序遍历
        void backTraversal(Node * node);

        //统计叶子节点的数量(左子树和右子树都为空)
        void leafNodeNum(Node * node, int & num);

        //获取树的深度
        int getDepth(Node * node);

};