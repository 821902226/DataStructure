#include "Graph.h"

Graph::Graph()
{
    cout<<"创建一个图"<<endl;
    cout<<"输入顶点数：";
    cin>>this->vertex_size;
    cout<<"输入边数：";
    cin>>this->edge_size;

    this->vertex.resize(this->vertex_size);
    this->edge.resize(this->vertex_size);
    for (int i = 0; i < this->vertex_size; i++)
    {
        this->edge[i].resize(this->vertex_size);
    }
    
    cout<<"输入"<<this->vertex_size<<"个顶点："<<endl;
    for (int i = 0; i < this->vertex_size; i++)
    {
        string str;
        cin>>str;
        this->vertex[i] = str;
    }

    cout<<"输入"<<this->edge_size<<"条边：(vertex1 vertex2)"<<endl;
    for (int i = 0; i < this->edge_size; i++)
    {
        string v1, v2;
        cin>>v1>>v2;
        int index1 = this->findIndex(v1);   //暂不考虑没有找到的情况
        int index2 = this->findIndex(v2);
        this->edge[index1][index2] = 1;
        this->edge[index2][index1] = 1;
    }
    
    
}

int Graph::findIndex(string str)
{
    for (int i = 0; i < this->vertex_size; i++)
    {
        if(str==this->vertex[i])
        {
            return i;
        }
    }
    return -1;
}

void Graph::info()
{
    cout<<"顶点信息如下："<<endl;
    for (int i = 0; i < this->vertex_size; i++)
    {    
        cout<<this->vertex[i]<<" ";
    }
    cout<<endl;

    cout<<"边的连接关系如下："<<endl;
    for (int i = 0; i < this->vertex_size; i++)
    {
        for (int j = 0; j < this->vertex_size; j++)
        {
            cout<<this->edge[i][j]<<"\t";
        }
        cout<<endl;
    }
}