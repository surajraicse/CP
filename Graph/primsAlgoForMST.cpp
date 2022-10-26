#include<bits/stdc++.h>
using namespace std;

// Prims's Algorithm for Minimum Spanning Tree

class cmp{
    public:
        int operator()(pair<int,int> &a, pair<int,int> &b)
        {
            return a.second>b.second;
        }
};

int main()
{
    int cNode, cEdge, u, v, wt;
    cin>>cNode>>cEdge;
    vector<pair<int,int>> list[cNode+1];
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> minH;
    vector<int> key(cNode+1, 100010);
    vector<int> par(cNode+1, -1);
    vector<int> mst(cNode+1,0);
    for(int i=0; i<cEdge; i++)
    {
        cin>>u>>v>>wt;
        list[u].push_back({v,wt});
        list[v].push_back({u,wt});
    }
    key[1]=0;
    minH.push({0,1});
    while(!minH.empty())
    {
        u = minH.top().second;
        mst[u]=1;
        minH.pop();
        for(auto adj: list[u])
        {
            v= adj.first;
            wt=adj.second;
            if(!mst[v] && key[v]>wt)
            {
                key[wt]=wt;
                par[v]=u;
                minH.push({wt,v});
            }
        }
    }
    cout<<"MST is: \n";
    for(int i=2; i<cNode+1; i++)
        cout<<i<<" - "<<par[i]<<"\n";
    return 0;
}