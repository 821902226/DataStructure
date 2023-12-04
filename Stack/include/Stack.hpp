#pragma once
#include <iostream>
#include <string.h> //memset头文件
#define MAX 1024

using namespace std;

template<class T>
class Stack
{
    private:
        T data[MAX];
        int m_size;

    public:
        Stack();
        ~Stack();

        //获取栈的大小
        int getSize();
        //入栈
        void push(T val);
        //出栈
        void pop();
        //返回栈顶元素
        T top();
        //判断栈是否为空
        bool isEmpty();

};

template<class T>
Stack<T>::Stack()
{
    memset(this->data, NULL, MAX);
    this->m_size = 0;
}

template<class T>
int Stack<T>::getSize()
{
    return this->m_size;
}

template<class T>
void Stack<T>::push(T val)
{
    if(val==NULL)
    {
        return;
    }
    if(this->m_size==MAX)
    {
        cout<<"插入失败，当前栈已满！"<<endl;
        return;
    }
    this->data[this->m_size] = val;
    this->m_size++;
}

template<class T>
void Stack<T>::pop()
{
    if(this->m_size==0)
    {
        cout<<"弹出失败，当前栈为空！"<<endl;
        return;
    }

    this->data[this->m_size-1] = NULL;
    this->m_size--;
}

template<class T>
T Stack<T>::top()
{
    return this->data[this->m_size-1];
}

template<class T>
bool Stack<T>::isEmpty()
{
    if(this->m_size==0)
    {
        return true;
    }
    return false;
}

template<class T>
Stack<T>::~Stack()
{
    
}