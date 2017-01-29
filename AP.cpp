#include<bits/stdc++.h>
using namespace std;
#define NIL -1
vector <int > *edge;

int v,Time;
void APUtil(int u,bool visited[],int disc[],int low[] , int parent[] , bool ap[])
{
    int chiled=0;
    visited[u] = true;
    disc[u]=low[u] =++Time;
    vector <int > ::iterator i;
    for(i=edge[u].begin();i!=edge[u].end();++i)
    {
        int w = *i;

        if(!visited[w])
        {
            chiled++;
            parent[w] = u;
            APUtil(w,visited,disc,low,parent,ap);
            low[u] = min(low[u],low[w]);
            if(parent[u]==NIL&&chiled>1)
                ap[u] = true;
            else if(parent[u]!=NIL&&low[w]>=disc[u])
                ap[u] = true;
        }
        else if(parent[u]!=w)
        {
            //if(parent[u]==v) continue;
            low[u] = min(low[u],low[w]);
        }
    }

}
void AP()
{
    bool *visited,*ap;
    int *disc,*low,*parent;
    visited = new bool [v+1];
    ap = new bool [v+1];
    parent = new int [v+1];
    disc = new int [v+1];
    low = new int [v+1];
    Time = 0;
    for(int i=0;i<=v;i++)
    {
        visited[i] = false;
        parent[i] = NIL;
        ap[i] = false;
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            APUtil(i,visited,disc,low,parent,ap);
    }

    cout<<"AP"<<endl;
    for(int i=0;i<v;i++)
    {
        if(ap[i]) cout<<i<<" ";
    }
}
void read()
{
    freopen("input.txt","r",stdin);
}

int main()
{
    read();

    int e;
    cin>>v>>e;
    edge = new vector < int > [v+1];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);

    }
    AP();

}
