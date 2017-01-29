#include<bits/stdc++.h>
using namespace std;
typedef  pair <int,int> pi;
int fx[] = {1 , -1 , 0 , 0};
int fy[] = {0 , 0 , 1 , -1};
int cell[1001][1001],d[1001][1001],vi[1001][1001];
int row,col;

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
        for(int i=0;i<4;i++)
        {
            int tx = topx + fx[i];
            int ty = topy + fy[i];
            if(tx>=0&&tx<=row&&ty>=0&&ty<=col&&cell[tx][ty]!=-1&&vi[tx][ty]==0)
            {
                vi[tx][ty] = 1;
                d[tx][ty] = d[topx][topy]+1;
                q.push(make_pair(tx,ty));
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
    while( cin>>row>>col)
    {
      if(row==0&&col==0) break;
      memset(cell,0,sizeof(cell));
      int c;

       scanf("%d ",&c);
      for(int i=0;i<c;i++)
      {
        int x ,y;
        cin>>x>>y;
        for(int j=0;j<y;j++)
        {
            int tm;
            cin>>tm;
            cell[x][tm] = -1;
        }
     }
     int sx,sy,dx,dy;
     cin>>sx>>sy>>dx>>dy;
     bfs(sx,sy);
     cout<<d[dx][dy]<<endl;

    }

    return 0;
}
/*
 for(int i=0;i<row;i++)
      {
        for(int j=0;j<col;j++)
            cout<<cell[i][j]<<" ";
        cout<<endl;
      }
*/
