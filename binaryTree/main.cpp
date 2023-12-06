#include <iostream>
#include "Node.h"
#include "BinTree.h"

using namespace std;

int main()
{
    //创建一个二叉树，建立节点之间的关系
    BinTree *tree = new BinTree(5);
    Node * nodeB = new Node(1);
    Node * nodeC = new Node(3);
    Node * nodeD = new Node(2);
    Node * nodeE = new Node(4);
    Node * nodeF = new Node(6);
    Node * nodeG = new Node(8);
    Node * nodeH = new Node(7);
    tree->root->left = nodeB;
    tree->root->right = nodeF;
    nodeB->right = nodeC;
    nodeC->left = nodeD;
    nodeC->right = nodeE;
    nodeF->right = nodeG;
    nodeG->left = nodeH;

    //先序遍历
    tree->frontTraversal(tree->root);
    cout<<endl;
    //中序遍历
    tree->middleTraversal(tree->root);
    cout<<endl;
    //后序遍历
    tree->backTraversal(tree->root);
    cout<<endl;

    //统计叶子节点的数量
    int num = 0;
    tree->leafNodeNum(tree->root, num);
    cout<<"The number of leaf node is: "<<num<<endl;

    //获取树的深度
    int depth = 0;
    depth = tree->getDepth(tree->root);
    cout<<"The depth of tree is: "<<depth<<endl;



    system("pause");
}