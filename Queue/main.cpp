#include <iostream>
#include "Queue.hpp"

using namespace std;

int main()
{
    Queue<int> * q = new Queue<int>();

    cout<<"Size "<<q->getSize()<<endl;
    cout<<"isEmpty "<<q->isEmpty()<<endl;

    //入队
    for (size_t i = 0; i < 10; i++)
    {
        q->push(i+1);
    }

    cout<<"Size "<<q->getSize()<<endl;
    cout<<"isEmpty "<<q->isEmpty()<<endl;

    cout<<"front "<<q->front()<<endl;
    

    //出队
    for (size_t i = 0; i < 3; i++)
    {
        q->pop();
    }

    cout<<"front "<<q->front()<<endl;
    cout<<"back "<<q->back()<<endl;
    cout<<"你干嘛"<<endl;
    
    
    

    system("pause");
}