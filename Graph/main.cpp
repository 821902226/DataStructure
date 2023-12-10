#include <iostream>
#include "Graph.h"

using namespace std;


int main()
{
    Graph* graph = new Graph();
    
    //打印图的顶点和边
    graph->info();

    cout<<"-------------------"<<endl;

    //深度优先搜索
    graph->dfs();

    cout<<"-------------------"<<endl;

    //广度优先搜索
    graph->bfs();
    

    system("pause");
}