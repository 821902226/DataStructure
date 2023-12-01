#pragma once
#include <iostream>

using namespace std;

class DynamicArray
{
    public:
        int * array;    //数组，保存在堆区
        int capacity;   //数组容量，存满后自动扩容
        int size;       //数组大小

        DynamicArray();
        ~DynamicArray();

        //插入数据
        void insert(int pos, int val);
        //遍历数组
        void forEach();
        //按索引删除数据
        void removeByPos(int pos);
        //按值删除数据--每次只删除一个,返回删除值的索引
        int removeByval(int val);
        
};