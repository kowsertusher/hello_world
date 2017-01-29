#include<bits/stdc++.h>
using namespace std;
map<int , vector<int> > v;
map <int , int > d;
map < int , bool> vi;
void bfs(int s)
{
    for(map<int , vector<int > > ::iterator it = v.begin();it!=v.end();++it)
    {
        d[it->first] = INT_MAX;
        vi[it->first] = true;
    }
    vi[s] = false;
    d[s] = 0;
    queue<int > q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(vector<int > ::iterator it = v[u].begin();it!=v[u].end();++it)
        {
            if(vi[*it])
            {
                vi[*it] = false;
                d[*it] = d[u]+1;
                //cout<<d[*it]<<" ";
                q.push(*it);
            }
        }
    }
}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    //read();
     int n;
     int cnt=1;
     while(cin>>n)
     {
         if(n==0) break;
         for(int i=0;i<n;i++)
         {
             int x,y;
             cin>>x>>y;
             v[x].push_back(y);
             v[y].push_back(x);
         }
         int s,ttl;
         while(cin>>s>>ttl)
         {
             if(s==0&&ttl==0) break;
             bfs(s);

             int count=0;
             for(map<int , int > ::iterator it = d.begin();it!=d.end();++it)
             {
                 if(it->second>ttl) count++;
             }
             d.clear();
             vi.clear();
             printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cnt++,count,s,ttl);
         }
         for(map<int , vector<int > > ::iterator it = v.begin();it!=v.end();++it)
         {
                 it->second.clear();
         }
         v.clear();

     }
}
