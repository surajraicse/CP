#include<bits/stdc++.h>
using namespace std;

// Topological Sort (BFS) | Kahn's Algorithm

int main()
{
    int node, edge, n1, n2;
    cin>>node>>edge;
    vector<vector<int>> list(node+1);
    queue<int> q;
    vector<int> indeg(node+1);
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;
        list[n1].push_back(n2);
        indeg[n2]++;
    }
    cout<<"Topological sort is:\n";
    for(int i=1; i<=node; i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            cout<<i<<" ";
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto adj: list[node])
        {
            indeg[adj]--;
            if(indeg[adj]==0)
            {
                q.push(adj);
                cout<<adj<<" ";
            }    
        }
    }
    return 0;
}