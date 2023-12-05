#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#define MAX 1024

using namespace std;

template<class T>
class Queue
{
    private:
        T *data;
        int size;

    public:
        Queue();
        ~Queue();

        //获取栈的大小
        int getSize();
        //判断栈是否为空
        bool isEmpty();
        //入队
        void push(T val);
        //出队
        void pop();
        //返回队头元素
        T front();
        //返回队尾元素
        T back();

};

template<class T>
Queue<T>::Queue()
{
    this->data = new T[MAX];
    memset(this->data, NULL, MAX);
    this->size = 0;
}

template<class T>
int Queue<T>::getSize()
{
    return this->size;
}

template<class T>
bool Queue<T>::isEmpty()
{
    return this->size==0;
}

template<class T>
void Queue<T>::push(T val)
{
    if(val==NULL)
    {
        return;
    }
    if(this->size==MAX)
    {
        cout<<"插入失败，当前队列已满！"<<endl;
        return;
    }
    this->data[this->size] = val;
    this->size++;
}

template<class T>
void Queue<T>::pop()
{
    if(this->size==0)
    {
        cout<<"出队失败，当前队列为空！"<<endl;
        return;
    }
    T *array = new T[MAX];
    for (size_t i = 1; i < this->size; i++)
    {
        array[i-1] = this->data[i];
    }
    delete [] this->data;
    this->data = array;
    this->size--;
}

template<class T>
T Queue<T>::front()
{
    return this->data[0];
}

template<class T>
T Queue<T>::back()
{
    return this->data[this->size-1];
}

template<class T>
Queue<T>::~Queue()
{
    if(this->data!=NULL)
    {
        delete [] this->data;
        this->data = NULL;
    }
}