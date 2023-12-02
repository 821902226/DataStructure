#pragma once
#include <iostream>
#include <Node.hpp>

using namespace std;

template<class T>
class LinkList
{
    public:
        Node<T> * head;
        int size;

        LinkList();
        ~LinkList();

        void insert(int pos, T data);   //插入节点

        void forEach(); //遍历链表

        void removeByPos(int pos); //按照位置删除节点

        void removeByVal(T val); //按照值删除节点

        void clear(); //清空链表
};

template<class T>
LinkList<T>::LinkList()
{
    this->head = new Node<T>();
    this->size = 0;
}

template<class T>
void LinkList<T>::insert(int pos, T data)
{
    if(pos<0||pos>this->size)
    {
        pos = this->size;
    }

    Node<T> * newNode = new Node<T>();
    newNode->data = data;
    Node<T> * cur = this->head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;

    this->size++;

    cout<<"插入一个节点！"<<endl;
    
}

template<class T>
void LinkList<T>::forEach()
{
    Node<T> * cur = this->head;
    while(cur->next)
    {
        cur = cur->next;
        cout<<cur->data<<endl;
    }
}

template<class T>
void LinkList<T>::removeByPos(int pos)
{
    if(pos<0||pos>=this->size)
    {
        cout<<"索引值超出范围!"<<endl;
        return;
    }

    Node<T> * cur = this->head;
    Node<T> * del;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
    del=NULL;

    this->size--;

    cout<<"删除位置"<<pos<<"上的节点"<<endl;
}

template<class T>
void LinkList<T>::removeByVal(T val)
{
    Node<T> * forward = this->head;
    Node<T> * cur = new Node<T>();

    for (int i = 0; i < this->size; i++)
    {
        if(forward->next->data==val)
        {
            cur = forward->next;
            forward->next = cur->next;
            delete cur;
            cur=NULL;
            this->size--;
            cout<<"删除值为"<<val<<"的节点"<<endl;
        }
        forward = forward->next;
    }
    
}

template<class T>
void LinkList<T>::clear()
{
    Node<T> * cur = this->head->next;

    for (int i = 0; i < this->size; i++)
    {
        Node<T> * nextNode = cur->next;
        delete cur;
        cur=nextNode;
    }

    this->head->next=NULL;
    this->size = 0;
    cout<<"清空链表！"<<endl;
    
}

template<class T>
LinkList<T>::~LinkList()
{
    this->clear();
    delete this->head;
    this->head = NULL;
}

