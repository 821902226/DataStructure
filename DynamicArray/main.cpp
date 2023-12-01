#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray* myarray = new DynamicArray();

    //插入数据
    for (int i = 0; i < 7; i++)
    {
        myarray->insert(0, i);
    }
    //数组的遍历
    myarray->forEach();
    cout<<"数组容量:"<<myarray->capacity<<" 数组大小："<<myarray->size<<endl;

    //按照索引删除数据
    myarray->removeByPos(4);
    myarray->forEach();
    cout<<"数组容量:"<<myarray->capacity<<" 数组大小："<<myarray->size<<endl;

    //按照值删除数据
    int res = myarray->removeByval(5);
    //int res = myarray->removeByval(8);
    cout<<res<<endl;
    myarray->forEach();
    cout<<"数组容量:"<<myarray->capacity<<" 数组大小："<<myarray->size<<endl;

    system("pause");
}