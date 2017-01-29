#include<bits/stdc++.h>
using namespace std;

int *Rank,*parent,n,e;
struct EDGE
{
    int u,v,w;
    bool operator<(const EDGE& p) const
    {
        return w < p.w;
    }
};
vector<EDGE> edge;

void makeSet()
{
    Rank = new int [n+1];
    parent = new int [n+1];
    for(int i=0;i<n+1;i++) Rank[i]=0,parent[i] = i;
}
int find(int x)
{
    if(parent[x]!=x) parent[x] = find(parent[x]);
    return parent[x];
}
void Union(int u, int v)
{
    int x = find(u),y = find(v);
    if(x==y) return;

    if(Rank[x]<Rank[y]) parent[x] = y;
    else if(Rank[x]>Rank[y]) parent[y] = x;
    else parent[x] = y,Rank[x]++;
}
int MST()
{
    sort(edge.begin(),edge.end());
    int cnt = 0 , mst = 0;
    for(int i=0;i<edge.size();i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        u = find(u);
        v = find(v);
        if(u!=v)
        {
            cnt++;
            mst+=w;
            Union(edge[i].u,edge[i].v);
            //parent[u] = v;
            if(cnt==n-1) break;
        }
    }

    return mst;
}
void read()
{
    freopen("input.txt","r",stdin);
}


int main()
{
    read();
    cin>>n>>e;
    makeSet();
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        EDGE get;
        get.u = x;
        get.v = y;
        get.w = w;
        edge.push_back(get);
    }
    cout<<MST()<<endl;


    return 0;
}
