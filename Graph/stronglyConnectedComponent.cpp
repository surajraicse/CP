#include<bits/stdc++.h>
using namespace std;

// Strongly Connected Components using Kosaraju’s algorithm

void dfs(int u, stack<int> &s, vector<int> &vis, vector<int> list[])
{
    vis[u]=1;
    for(auto adj : list[u])
    {
        if(!vis[adj])
        {
            dfs(adj, s, vis, list);
        }
    }
    s.push(u);
}

void dfsTrans(int u, vector<int> &vis, vector<int> list[])
{
    vis[u]=1;
    for(auto adj: list[u])
    {
        if(!vis[adj])
        {
            dfsTrans(adj, vis, list);
        }
    }
}

int main()
{
    int cNode, cEdge, nSCC=0, u, v;
    cin>>cNode>>cEdge;
    vector<int> list[cNode+1];
    vector<int> listTrans[cNode+1];
    vector<int> vis(cNode+1,0);
    stack<int> s;
    for(int i=0; i<cEdge; i++)
    {
        cin>>u>>v;
        list[u].push_back(v);
        listTrans[v].push_back(u);
    }
    dfs(1, s, vis, list);
    for(int i=0; i<cNode+1; i++)
        vis[i]=0;
    while(!s.empty())
    {
        u = s.top();
        s.pop();
        if(!vis[u])
        {
            nSCC++;
            dfsTrans(u, vis, listTrans);
        }
    }
    cout<<"No. of Strongly Connected Component's are: "<<nSCC;
    return 0;
}