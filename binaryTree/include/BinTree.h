#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class BinTree
{
    public:
        Node * root;

        BinTree(int val);
        ~BinTree();

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