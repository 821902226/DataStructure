#include <iostream>
#include "LinkList.hpp"
#include "Node.hpp"

using namespace std;

int main()
{
    LinkList<float> *list = new LinkList<float>();

    //插入数据
    list->insert(0, 0);
    list->insert(1, 1);
    list->insert(2, 2);
    list->insert(3, 3);
    list->insert(4, 4);
    list->insert(5, 5);
    list->insert(6, 6);
    list->insert(7, 7);
    list->insert(8, 8);
    //遍历链表 (打印函数需根据T自定义)
    list->forEach();
    //按照索引删除节点
    list->removeByPos(3);
    //遍历链表
    list->forEach();
    //按照值删除节点
    list->removeByVal(5);
    //遍历链表
    list->forEach();
    //清空链表
    list->clear();
    cout<<"当前链表大小："<<list->size<<endl;
    //遍历链表
    list->forEach();

    system("pause");
}