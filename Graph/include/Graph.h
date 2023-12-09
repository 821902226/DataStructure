#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//无向图
class Graph
{
    public:
        vector<string> vertex;
        vector<vector<int>> edge;   //邻接矩阵
        int vertex_size;
        int edge_size;
    
        Graph();

        void info();    //打印顶点和边的信息

    private:
        int findIndex(string str);
        
};