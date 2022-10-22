#include<bits/stdc++.h>
using namespace std;

//Cycle Detection in Undirected Graph using BFS

int bfs(vector<int> &vis, queue<pair<int,int>> &q,vector<vector<int>> &list)
{
    while(!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto adj: list[node])
        {
            if(!vis[adj])
            {
                vis[adj]=1;
                q.push({adj,node});
            }
            else if(par != adj)
                return 1;
        }
    } 
    return 0;
}

int main()
{
    int node,edge,n1,n2;
    cin>>node>>edge;
    vector<vector<int>> list(node+1);
    vector<int> vis(node+1,0);
    queue<pair<int,int>> q;
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
            q.push({i,0});
            vis[i]=1;
            if(bfs(vis,q,list))
            {
                cout<<"There is a cycle";
                return 0;
            }
        }
    }
    cout<<"Graph is Cycle free";
    return 0;
}