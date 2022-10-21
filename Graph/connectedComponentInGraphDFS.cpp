#include<bits/stdc++.h>
using namespace std;

// Connected component in graph using DFS

void dfs(int node, vector<int> &vis, vector<int> adj[] )
{
    for( auto neigh : adj[node])
    {
        if(!vis[neigh])
        {
            vis[neigh]=1;
            dfs(neigh,vis,adj);
        }
    }
}

int main()
{
    int node,edge,n1,n2,nCompo=0;
    cin>>node>>edge;
    vector<int> adj[node+1];
    vector<int> vis;
    for(int i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    for(int i=0;i<=node;i++)
        vis.push_back(0);
    for(int i=1;i<=node;i++)
    {
        if(vis[i] == 0)
        {
            vis[i]=1;
            dfs(i,vis,adj);
            nCompo++;
        }
    }
    cout<<"No. of connected components :"<<nCompo;
    return 0;

}