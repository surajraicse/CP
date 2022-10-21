#include<bits/stdc++.h>
using namespace std;

// Connected component in graph using BFS

void bfs(int node, queue<int> q, vector<int> &vis, vector<int> adj[])
{
    while(!q.empty())
    {
        int fNode = q.front();
        q.pop();
        for( auto temp : adj[fNode] )
        {
            if(!vis[temp])
            {
                q.push(temp);
                vis[temp]=1;
            }
        }
    }
}

int main()
{
    int node, edge, n1, n2, nCompo=0;
    cin>>node>>edge;
    vector<int> list[node+1];
    vector<int> vis;
    queue<int> q;
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;
        list[n1].push_back(n2);
        list[n2].push_back(n1);
    }
    for(int i=0; i<node; i++)
    {
        vis.push_back(0);
    }
    for(int i=1; i<=node; i++)
    {
        if(vis[i]==0)
        {
            q.push(i);
            bfs(i,q,vis,list);
            nCompo++;
        }
    }
    cout<<"No of Connected Components "<<nCompo;
    return 0;
}