#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int , int > pi;
vector < pi > *edge;
int v;

int MST(int src)
{
    priority_queue<pi,vector<pi> , greater<pi> > pq;
    vector <int > key (v,INF);
    vector < int > parent (v,-1);
    vector < bool > inMst(v,false);
    pq.push(make_pair(0,src));
    key [src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMst[u] = true;

        vector <pi > ::iterator it;
        for(it = edge[u].begin();it!=edge[u].end();++it)
        {
            int v = (*it).first;
            int w = (*it).second;
            if(!inMst[v]&&key[v]>w)
            {
                key[v] = w;
                pq.push(make_pair(key[v],v));
                parent[v] = u;
            }
        }
    }
    int sum=0;
    for(int i=0;i<key.size();i++)
    {
        sum+=key[i];
    }
    return sum;

}

void read()
{
   freopen("input.txt","r",stdin);
}
int main()
{
    read();

    cin>>v;
    int e;
    cin>>e;
    edge  = new vector <pi> [v];

    for (int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edge[--x].push_back(make_pair(--y,w));
        edge[y].push_back(make_pair(x,w));
    }
    cout<<MST(0)<<endl;

    return 0;
}
