#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector< pair<int,long long > > *edge;
long long dis[200000];
int ver;
bool per[2000000];
void bfs(int s)
{
    memset(per,false,sizeof(per));
    memset(dis,INF,sizeof(dis));
    //priority_queue<pair<long long,int>> q;
    set< pair<long long , int > > q;
    dis[s] = 0;
    per[s] = true;
    q.insert(make_pair(0,s));
    while(!q.empty())
    {
        set< pair<long long , int > > ::iterator it = q.begin();
        long long w = it->first;
        int u = it->second;
        q.erase(q.begin());
        for(int i =0;i<edge[u].size();i++)
        {
            pair<int , long long > pi = edge[u][i];
            if(dis[u]+pi.second<dis[pi.first])
            {
                dis[pi.first] = dis[u] + pi.second;
                per[pi.first] = true;
                q.insert(make_pair(dis[pi.first],pi.first));
            }
        }
    }
}
int main()
{

    //read();
    //ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++)
    {
        cin>>ver;

        edge = new vector< pair<int,long long > > [ver+1];
        //dis = new long long [ver+1];

        int nedge,s,di;
        cin>>nedge>>s>>di;

        for(int i=0;i<nedge;i++)
        {
            int x,y; long long c;
            scanf("%d%d%I64d",&x,&y,&c);
            edge[x].push_back(make_pair(y,c));
            edge[y].push_back(make_pair(x,c));

        }
        bfs(s);
        if(per[di]) cout<<"Case #"<<tc+1<<": "<<dis[di]<<endl;
        else  cout<<"Case #"<<tc+1<<": "<<"unreachable"<<endl;
    }

}

