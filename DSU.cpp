#include<bits/stdc++.h>
using namespace std;

int *rank,*parent,n,e;
vector<pair<int,int> > edge;
void makeSet()
{
    rank = new int [n];
    parent = new int [n];
    for(int i=0;i<n;i++) rank[i]=0,parent[i] = i;
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

    if(rank[x]<rank[y]) parent[x] = y;
    else if(rank[x]>rank[y]) parent[y] = x;
    else parent[x] = y,rank[x]++;
}
bool isCycle()
{
    for(int i=0;i<edge.size();i++)
    {
        int x = find(edge[i].first);
        int y = find(edge[i].second);
        if(x==y) return true;
        Union(x,y);
    }
    return false;
}

int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        edge.push_back(make_pair(x,y));
    }
    makeSet();
    if(isCycle()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}
