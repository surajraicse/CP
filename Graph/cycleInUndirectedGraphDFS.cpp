#include<bits/stdc++.h>
using namespace std;

////Cycle Detection in Undirected Graph using DFS

int dfs(int node, int par, vector<int> &vis, vector<vector<int>> &list)
{
    vis[node]=1;
    for(auto adj: list[node])
    {
        if(!vis[adj])
        {
            return dfs(adj,node,vis,list);
        }
        else if( adj != par)
            return 1;
    }
    return 0;
}

int main()
{
    int node,edge,n1,n2;
    cin>>node>>edge;
    vector<vector<int>> list(node+1);
    vector<int> vis(node+1,0);
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;
        list[n1].push_back(n2);
        list[n2].push_back(n1);
    }
    for(int i=1; i<=node; i++)
    {
        if(!vis[i])
        {
            if(dfs(i,0,vis,list))
            {
                cout<<"There is a cycle.";
                return 0;
            }
        }
    }
    cout<<"Graph is cycle free.";
    return 0;
}