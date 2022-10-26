#include<bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm for Minimum Spanning Tree

struct node{
    int wt;
    int u;
    int v;
    node(int a,int b,int c)
    {
        u = a;
        v = b;
        wt = c;
    }
};

class cmp{
    public: 
        int operator()(node &a, node &b)
        {
            return a.wt > b.wt;
        }
};

int findPar(int child, vector<int> &par)
{
    if(child == par[child])
        return child;
    return par[child] = findPar(par[child], par);
}

void merge(int u, int v, vector<int> &rank, vector<int> &par)
{
    u=findPar(u, par);
    v=findPar(v, par);
    if(rank[u] < rank[v])
       par[u]=v;
    else if(rank[v] < rank[u])
       par[v]=u;
    else{
        par[u]=v;
        rank[v]++;
    }
}


int main()
{
    int cNode, cEdge, wt, u, v;
    vector<pair<int,int>> mst;
    cin>>cNode>>cEdge;
    vector<int> par;
    vector<int> rank(cNode+1,0);
    for( int i=0; i<cNode+1; i++)
        par.push_back(i);
    priority_queue<node, vector<node>, cmp> minH;
    for(int i=0; i<cEdge; i++)
    {
        cin>>u>>v>>wt;
        minH.push(node(u, v, wt));
    }
    while(!minH.empty())
    {
        u = minH.top().u;
        v = minH.top().v;
        wt = minH.top().wt;
        minH.pop();
        if(findPar(u,par) != findPar(v, par))
        {
            merge(u, v, rank, par);
            mst.push_back({u,v});
        }
    }
    cout<<"MST is: \n";
    for(auto temp: mst)
    {
        cout<<temp.first<<" - "<<temp.second<<"\n";
    }

    return 0;
}

