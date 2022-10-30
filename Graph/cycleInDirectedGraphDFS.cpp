#include<bits/stdc++.h>
using namespace std;

//Cycle Detection in Directed Graph using DFS

int dfs(int node, vector<int> &vis, vector<int> &track, vector<vector<int>> &list)
{
    for( auto adj: list[node])
    {
        if(!vis[adj])
        {
            vis[adj]=1;
            track[adj]=1;
            if(dfs(adj,vis,track,list))
                return 1;
        }
        else if(track[node])
            return 1;
    }
    track[node]=0;
    return 0;
}

int main()
{
    int node,edge,n1,n2;
    cin>>node>>edge;
    vector<vector<int>> list(node+1);
    vector<int> vis(node+1,0);
    vector<int> track(node+1,0);
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;
        list[n1].push_back(n2);
    }
    for(int i=1; i<=node; i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            track[i]=1;
            if(dfs(i,vis,track,list))
            {
                cout<<"There is a cycle.";
                return 0;
            }
        }
    }
    cout<<"Graph is cycle free";
    return 0;
}