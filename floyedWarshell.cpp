#include<bits/stdc++.h>
#define INF 100000
using namespace std;
int dis[100][100],v,next[100][100];

void floyedWarshall()
{
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                //dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}
void transitiveClosure()
{
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                //dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);

                    dis[i][j] = dis[i][j] or (dis[i][k] and dis[k][j]);

            }
        }
    }
}
void path(int s,int d)
{
    vector<int > v;
    v.push_back(s);
    while(s!=d)
    {
        s = next[s][d];
        v.push_back(s);
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void print()
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            dis[i][j] != INF ? cout<<dis[i][j]<<" " : cout<<"INF"<<" ";
        }
        cout<<endl;
    }
}
void read ()
{
    freopen("input.txt","r",stdin);
}
int main()
{
    read();
    cin>>v;
    int e;
    cin>>e;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INF;
            next[i][j] = -1;
        }
    }
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        dis[--x][--y] = w;
        next[x][y] = y;
    }
    floyedWarshall();
    print();
    path(0,2);
    //transitiveClosure();
}


