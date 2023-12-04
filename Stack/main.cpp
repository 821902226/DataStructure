#include <iostream>
#include "Stack.hpp"

using namespace std;

void legalBrackets(char *str)
{
    Stack<char> *s = new Stack<char>();

    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='(')
        {
            s->push(str[i]);
        }
        if(str[i]==')')
        {
            if(s->getSize()>0)
            {
                s->pop();
            }
            else
            {
                cout<<"存在非法括号！"<<endl;
                return;
            }
        }
        i++;
    }

    if(s->getSize()>0)
    {
        cout<<"存在非法括号！"<<endl;
    }
}

int main()
{
    Stack<int> *s = new Stack<int>();

    cout<<"栈是否为空："<<s->isEmpty()<<endl;

    for (size_t i = 0; i < 10; i++)
    {
        s->push(i+1);
    }

    cout<<"当前栈的大小："<<s->getSize()<<endl;

    s->pop();
    s->pop();
    s->pop();
    s->pop();

    cout<<"当前栈的大小："<<s->getSize()<<endl;

    cout<<"栈顶元素："<<s->top()<<endl;
    
    char str[] = "5+5*(6)+9/3*1)-(1+3(";

    //利用栈判断是否存在非法括号
    legalBrackets(str);

    system("pause");
}