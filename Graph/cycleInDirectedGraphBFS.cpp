#include<bits/stdc++.h>
using namespace std;

//Cycle Detection in Directed Graph using BFS (Kahn's Algorithm)

int main()
{
    int node, edge, n1, n2;
    cin>>node>>edge;
    vector<vector<int>> list(node+1);
    vector<int> indeg(node+1,0);
    queue<int> q;
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;
        list[n1].push_back(n2);
        indeg[n2]++;
    }
    for(int i=1; i<node+1; i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(auto adj : list[temp])
        {
            indeg[adj]--;
            if(indeg[adj]==0)
            {
                q.push(adj);
            }
        }
    }
    for(int i=1; i<=node; i++)
    {
        if(indeg[i]!=0)
        {
            cout<<"Graph has a cycle";
            return 0;
        }
    }
    cout<<"Graph is cycle free";
    return 0;
}