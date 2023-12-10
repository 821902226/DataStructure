#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

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

        void dfs(); //深度优先搜索遍历图

        void bfs(); //广度优先搜索遍历图

    private:
        int findIndex(string str);
        
};