#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    this->array = new int[5];
    this->capacity = 5;
    this->size = 0;
}

void DynamicArray::insert(int pos, int val)
{
    if(pos<0||pos>this->size)   //无效位置，直接尾插
    {
        pos = this->size;
    }

    if(this->size==this->capacity)  //容量已满，进行扩容
    {
        int newCapacity = this->capacity*2;
        int * temp = new int[newCapacity];
        for (int i = 0; i < this->size; i++)    //将原有数据复制到新数组
        {
            temp[i] = this->array[i];
        }
        delete this->array;
        this->array = temp;
        this->capacity = newCapacity;
    }

    //插入数据
    for (int i = this->size-1; i >= pos; i--)
    {
        this->array[i+1] = this->array[i];
    }
    this->array[pos] = val;
    this->size++;
    cout<<"成功插入一个数据："<<val<<endl;
}

void DynamicArray::forEach()
{
    cout<<"动态数组的遍历:"<<endl;
    for (int i = 0; i < this->size; i++)
    {
        cout<<this->array[i]<<"\t";
    }
    cout<<endl;
    
}

void DynamicArray::removeByPos(int pos)
{
    if(this->array==nullptr || pos<0 || pos>this->size-1)
    {
        return;
    }

    for (int i = pos+1; i < this->size; i++)
    {
        this->array[i-1] = this->array[i];
    }
    this->size--;
    cout<<"成功删除位置"<<pos<<"上的数据"<<endl;
}

int DynamicArray::removeByval(int val)
{
    if(this->array==nullptr)
    {
        return -1;
    }

    for (int i = 0; i < this->size; i++)
    {
        if(this->array[i]==val)
        {
            this->removeByPos(i);
            return i;
        }
    }
    
    return -1;

}

DynamicArray::~DynamicArray()
{
    if(this->array!=nullptr)
    {
        delete [] this->array;
        this->array = nullptr;
    }
    delete this;
}