#include<bits/stdc++.h>
using namespace std;

// Bipartite Graph (DFS)

int dfs(int node, vector<int> &col, vector<vector<int>> &list)
{
    for(auto adj: list[node])
    {
        if(col[adj]==-1)
        {
            col[adj]=1-col[node];
            return dfs(adj, col, list);
        }
        else if(col[adj]==col[node])
            return 1;
    }
    return 0;
}

int main()
{
    int node, edge, n1, n2;
    cin>>node>>edge;
    vector<vector<int>> list(node+1);
    vector<int> col(node+1);
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;
        list[n1].push_back(n2);
        list[n2].push_back(n1);
    }
    for(int i=1; i<=node; i++)
    {
        col[i]=-1;
    }
    for(int i=1; i<=node; i++)
    {
        if(col[i]==-1)
        {
            col[i]=1;
            if(dfs(i,col,list))
            {
                cout<<"Not a Bipartite Graph.";
                return 0;
            }
        }
    }
    cout<<"It is a Bipartite Graph.";
    return 0;
}