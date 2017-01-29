#include<bits/stdc++.h>
using namespace std;
vector<int> *v;
int d[30];
bool vi[21];
void bfs(int s)
{
    for(int i=0;i<21;i++)
    {
        d[i] = INT_MAX;
        vi[i] = true;
    }
    queue<int> q;
    d[s] =0;
    vi[s] = false;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(vector<int> ::iterator it = v[u].begin();it!=v[u].end();++it)
        {
            if(vi[*it])
            {
                d[*it] = d[u]+1;
                vi[*it] = false;
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
    int cnt=1;
    int x;
    while(cin>>x)
    {
        v = new vector<int> [21];
        for(int i=0;i<x;i++)
        {
            int y;
            cin>>y;
            v[1].push_back(y);
            v[y].push_back(1);
        }
        for(int i=2;i<20;i++)
        {
            cin>>x;
            for(int j=0;j<x;j++)
            {
                int y;
                cin>>y;
                v[i].push_back(y);
                v[y].push_back(i);
            }
        }
        int n;
        cin>>n;
        printf("Test Set #%d\n",cnt);
        for(int i=0;i<n;i++)
        {
            int s,di;
            cin>>s>>di;
            bfs(s);
            printf("%2d to %2d: %d\n",s,di,d[di]);
        }
        cout<<endl;
        cnt++;
    }
}
