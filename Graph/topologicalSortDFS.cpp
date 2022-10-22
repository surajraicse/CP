#include<bits/stdc++.h>
using namespace std;

// Topological Sort (DFS)

void dfs(int node, stack<int> &s, vector<int> &vis, vector<vector<int>> &list)
{
    vis[node]=1;
    for(auto adj: list[node])
    {
        if(!vis[adj])
            dfs(adj,s,vis,list);
    }
    s.push(node);
}

int main()
{
    int node, edge, n1, n2;
    cin>>node>>edge;
    vector<vector<int>> list(node+1);
    vector<int> vis(node+1,0);
    stack<int> s;
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;
        list[n1].push_back(n2);
    }
    for(int i=1; i<=node; i++)
    {
        if(!vis[i])
            dfs(i,s,vis,list);
    }
    cout<<"Topological Sort is:\n";
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}