#include<bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm for Single Source Shortest Path

int main()
{
    int cNode, cEdge, u, v, wt, src;
    cin>>cNode>>cEdge;
    vector<pair<int,int>> list[cNode+1];
    set<pair<int,int>> minH;
    vector<int> curWt(cNode+1,100010);
    for(int i=0; i<cEdge; i++)
    {
        cin>>u>>v>>wt;
        list[u].push_back({v,wt});
        list[v].push_back({u,wt});
    }
    cin>>src;
    minH.insert({0,src});
    curWt[src]=0;
    while(!minH.empty())
    {
        auto temp = *(minH.begin());
        u =  temp.second;
        wt = temp.first;
        minH.erase(minH.begin());
        for(auto adj: list[u])
        {
            v = adj.first;
            int edgeWt = adj.second;
            if( curWt[v] > wt + edgeWt)
            {
                if(curWt[v]!=100010)
                    minH.erase(minH.find({curWt[v],v}));
                curWt[v]= wt+edgeWt;
                minH.insert({curWt[v],v});
            }
        }
    }
    cout<<"Shortest path from Source "<<src<<" is:"<<"\n";
    for(int i=1 ; i<=cNode; i++)
        cout<<i<<" -> "<<curWt[i]<<"\n";
    return 0;
}

