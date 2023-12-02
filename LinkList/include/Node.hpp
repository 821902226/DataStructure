#pragma once
#include <iostream>

using namespace std;

template<class T>
class Node
{
    public:
        T data;
        Node * next;

        Node();
};


template<class T>
Node<T>::Node()
{
    this->data = NULL;
    this->next = NULL;
}
