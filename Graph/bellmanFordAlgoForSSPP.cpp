#include<bits/stdc++.h>
using namespace std;

//cnode, cedge, u, v , wt, isNegCycle
//list vector<pair<int,int>>[]
// wt vector<int>
struct node{
    int u;
    int v;
    int wt;
    node(int a, int b, int c)
    {
        u=a;
        v=b;
        wt=c;
    }
};

int main()
{
    int cNode, cEdge, u, v, wt, src, isNegCycle=0;
    cin>>cNode>>cEdge;
    vector<node> list;
    vector<int> dist(cNode+1,100010);
    for(int i=0; i<cEdge; i++)
    {
        cin>>u>>v>>wt;
        list.push_back(node(u,v,wt));
    }
    cin>>src;
    dist[src]=0;
    for(int i=1; i<cNode; i++)
    {
        for(auto edge: list)
        {
            u=edge.u;
            v=edge.v;
            wt=edge.wt;
            if(dist[v]>dist[u]+wt)
            {
                dist[v]=dist[u]+wt;
            }
        }
    }

    for(auto edge: list)
    {
        u=edge.u;
        v=edge.v;
        wt=edge.wt;
        if(dist[v]>dist[u]+wt)
            isNegCycle=1;
    }

    if(isNegCycle)
        cout<<"There is Negative Edge wt. cycle\n";
    else{
        for(int i=1; i<=cNode; i++)
            cout<<dist[i]<<" ";
    }
    
    return 0;
}