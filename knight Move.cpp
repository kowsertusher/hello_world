#include<bits/stdc++.h>
using namespace std;
typedef  pair <int,int> pi;
int d[9][9];
int vi[9][9];
int fx[] = {2,2,-2,-2,1,-1,1,-1};
int fy[] = {1,-1,1,-1,2,2,-2,-2};

void bfs(int sx , int sy)
{
 memset(vi,0,sizeof(vi));
    vi[sx][sy] = 1;
    d[sx][sy] = 0;
    queue<pi> q;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        pi top = q.front(); q.pop();
        int topx = top.first;
        int topy = top.second;
        for(int i=0;i<8;i++)
        {
            int tx = topx + fx[i];
            int ty = topy + fy[i];
            if(tx>=0&&tx<8&&ty>=0&&ty<8&&vi[tx][ty]==0)
            {
                vi[tx][ty] = 1;
                d[tx][ty] = d[topx][topy]+1;
                q.push(make_pair(tx,ty));
            }
        }
    }
}
int main()
{

    string s1,s2;
    while( cin>>s1>>s2)
    {
        memset(vi,0,sizeof(vi));
        memset(d,1000000,sizeof(d));
        int sx = s1[0]-'a';
        int sy = s1[1]- 49;
        int dx = s2[0]-'a';
        int dy = s2[1] -49;
        bfs(sx,sy);
        //printf("To get from %s to %s takes %d knight moves.\n",s1);
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<d[dx][dy]<<" knight moves."<<endl;
    }



}
