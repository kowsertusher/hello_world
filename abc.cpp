#include<bits/stdc++.h>
using namespace std;

vector< pair<int,long long> > *edge;
long long dis[100100],per[100100];
int ver;

void bfs()
{
    //memset(dis,INT_MAX,sizeof(dis));
    for(int i=0;i<=ver;i++)
        dis[i] = 1000000000000000;
    memset(per,-1,sizeof(per));
    priority_queue<pair<int,long long>> q;
    dis[1] = 0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int w = q.top().first;
        int u = q.top().second;
        q.pop();
        //if (w>dis[u]) continue;
        for(int i =0;i<edge[u].size();i++)
        {
            pair<int , int > pi = edge[u][i];
            if(dis[u]+pi.second<dis[pi.first])
            {
                dis[pi.first] = dis[u] + pi.second;
                per[pi.first] = u;
                //cout<<pi.first<<" ";
                q.push(make_pair(-dis[pi.first],pi.first));
            }
        }
    }
}

void print(int u)
{
	if (u == -1) return;
	print(per[u]);
	printf("%d ",u);
}

void read()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}
int main()
{

    //read();
    //ios::sync_with_stdio(0);
    cin>>ver;

    edge = new vector< pair<int,long long> > [ver+1];
    //dis = new int [ver+1];
    ///per = new int [ver+1];

    int nedge;
    cin>>nedge;

    for(int i=0;i<nedge;i++)
    {
        int x,y; long long c;
        scanf("%d%d%I64d",&x,&y,&c);
        edge[x].push_back(make_pair(y,c));
        edge[y].push_back(make_pair(x,c));

    }
    bfs();
   if (dis[ver] == 1000000000000000)
		cout<<"-1"<<endl;
	else
		print(ver);

}



