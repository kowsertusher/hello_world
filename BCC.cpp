#include<bits/stdc++.h>
using namespace std;
#define NIL -1
vector <int > *edge;
stack < pair <int , int > > s;
bool *visited;
int *disc,*low,*parent;
int v,Time,cnt=0;
void BCCUtil(int u)
{
    ++Time;
    int chiled=0;
    visited[u] = true;
    disc[u]=low[u] = Time;
    vector <int > ::iterator i;
    for(i=edge[u].begin();i!=edge[u].end();++i)
    {
        int v = *i;
        //cout<<"low"<<v <<" = "<<low[v] << "       distance and low"<<u<<" = "<< disc[u]<<" "<<low[u]<<endl;
        if(disc[v]==-1)
        {
            chiled++;
            parent[v] = u;
            s.push(make_pair(u,v));
            BCCUtil(v);
            low[u] = min(low[u],low[v]);
            if((disc[u]==1&&chiled>1) ||(disc[u]>1&&low[v]>=disc[u]))
            {
                while(s.top().first!=u||s.top().second!=v)
                {
                    cout<<s.top().first << "--" <<s.top().second<<" ";
                    s.pop();
                }
                cout<<s.top().first<<"--"<<s.top().second<<endl;
                s.pop();
                cnt++;
            }
        }
        else if(parent[u]!=v&&disc[v]<low[u])
        {
            s.push(make_pair(u,v));
            low[u] = min(low[u],low[v]);
        }

    }

}
void BCC()
{
    visited = new bool [v+1];
    //ap = new bool [v+1];
    parent = new int [v+1];
    disc = new int [v+1];
    low = new int [v+1];
    Time = 0;
    for(int i=0;i<v;i++)
    {
        visited[i] = false;
        parent[i] = NIL;
        //ap[i] = false;
        disc[i] = NIL;
        low[i] = NIL;
    }
    for(int i=0;i<v;i++)
    {
        if(disc[i]==NIL)
            BCCUtil(i);
        int j=0;
        //cout<<i<<" dsjf"<<endl;
        while(s.size()>0)
        {
            j=1;
            cout<<s.top().first<<"--"<<s.top().second<<" ";
            s.pop();
        }
        if(j==1)
        {
            cout<<endl;
            cnt++;
        }
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
    BCC();
    cout<<"There are "<< cnt << " BCC In This Graph"<<endl;

}

