#include<bits/stdc++.h>
using namespace std;
const int v = 5;

bool isBipartiteUtil(int g[][v] , int soure , int color[])
{
    color[soure] = 1;
    queue<int> q;
    q.push(soure);
    while(q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<v;i++)
        {
            if(g[u][i]&&color[i]==-1)
            {
                color[i] = 1-color[u];
                q.push(i);
            }
            else if(g[u][i]&&color[u]==color[i]) return false;
        }
    }
    return true;
}
bool isBipartite(int g[][v])
{
    int color[v+1];
    memset(color,-1,sizeof(color));
    for(int i=0;i<v;i++)
    {
        if(color[i]==-1)
        {
            if(!isBipartiteUtil(g,i,color))return false;
        }
    }
    return true;
}
bool canDividedinTwoClique(int g[][v])
{
    int g1[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            g1[i][j] = (i!=j) ? !g[i][j] : 0;
        }
    }
    return isBipartite(g1);
}
int main()
{
    //v = 5;
    int g[][5] = {{0,1,1,1,0},
                   {1,0,1,0,0},
                   {1,1,0,0,0},
                   {0,1,0,0,1},
                   {0,0,0,1,0}};

    canDividedinTwoClique(g) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}

