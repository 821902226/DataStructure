#include "Graph.h"

Graph::Graph()
{
    cout<<"Create a Graph"<<endl;
    cout<<"Enter the number of vertices: ";
    cin>>this->vertex_size;
    cout<<"Enter the number of edged: ";
    cin>>this->edge_size;

    this->vertex.resize(this->vertex_size);
    this->edge.resize(this->vertex_size);
    for (int i = 0; i < this->vertex_size; i++)
    {
        this->edge[i].resize(this->vertex_size);
    }
    
    cout<<"Enter "<<this->vertex_size<<" points: "<<endl;
    for (int i = 0; i < this->vertex_size; i++)
    {
        string str;
        cin>>str;
        this->vertex[i] = str;
    }

    cout<<"Enter "<<this->edge_size<<" edges: (vertex1 vertex2)"<<endl;
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
    cout<<"The vertex information is as follows: "<<endl;
    for (int i = 0; i < this->vertex_size; i++)
    {    
        cout<<this->vertex[i]<<" ";
    }
    cout<<endl;

    cout<<"The connection relationship of the edges is as follows: "<<endl;
    for (int i = 0; i < this->vertex_size; i++)
    {
        for (int j = 0; j < this->vertex_size; j++)
        {
            cout<<this->edge[i][j]<<"\t";
        }
        cout<<endl;
    }
}

//深度优先搜索
void Graph::dfs()
{
    vector<bool> visited(this->vertex_size);
    stack<string> s;
    s.push(this->vertex[0]);
    cout<<this->vertex[0]<<" ";
    visited[0] = true;

    while(!s.empty())
    {
        bool flag = false;
        string top = s.top();
        int index = findIndex(top);
        for(int i=0; i<this->vertex_size; i++)
        {
            if(this->edge[index][i]&&!visited[i])
            {
                flag = true;
                visited[i]=true;
                cout<<this->vertex[i]<<" ";
                s.push(this->vertex[i]);
                break;
            }
        }
        if(!flag)   //没有邻接点则弹出
        {
            s.pop();
        }
        
    }
    cout<<endl;
}

//广度优先搜索
void Graph::bfs()
{
    vector<bool> visited(this->vertex_size);
    queue<string> q;
    q.push(this->vertex[0]);
    cout<<this->vertex[0]<<" ";
    visited[0] = true;

    while(!q.empty())
    {
        string front = q.front();
        int index = this->findIndex(front);
        for (int i = 0; i < this->vertex_size; i++)
        {
            if(this->edge[index][i]&&!visited[i])
            {
                visited[i] = true;
                cout<<this->vertex[i]<<" ";
                q.push(this->vertex[i]);
            }
        }
        q.pop();
    }
    cout<<endl;
}
