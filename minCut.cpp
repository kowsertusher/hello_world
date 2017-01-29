#include<bits/stdc++.h>
using namespace std;

const int v =6;

bool bfs(int rgraph[v][v],int s,int t,int parent[])
{
    queue<int> q;
    bool visited[v];
    memset(visited,false,sizeof(visited));
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<v;i++)
        {
                if(!visited[i]&&rgraph[u][i]>0 )
                {
                    parent[i] = u;
                    q.push(i);
                    visited[i] =true;
                }
        }
    }
    return visited[t];
}
void dfs(int rgraph[v][v],int s,bool visited[])
{
    visited[s] = true;
    for(int i=0;i<v;i++)
    {
        if(!visited[i]&&rgraph[s][i]>0) dfs(rgraph,i,visited);
    }
}
int minCut(int graph[v][v],int s,int t)
{


  int rgraph [v][v] ;
  for(int i=0;i<v;i++)
  {
      for(int j=0;j<v;j++)
        rgraph[i][j] = graph[i][j];
  }
  int parent[v];
  int mincut = 0;
  while(bfs(rgraph,s,t,parent))
  {
      int minX = INT_MAX;
      for(int i = t ;i!=s ; i = parent[i])
      {
          int u = parent[i];
          minX = min(rgraph[u][i],minX);
      }
      for(int i=t;i!=s;i=parent[i])
      {
          int u = parent[i];
          rgraph[u][i] -= minX;
          rgraph[i][u] += minX;
      }
      mincut+=minX;
  }
  bool visited[v];
  memset(visited,false,sizeof(visited));
  dfs(rgraph,s,visited);
  for(int i=0;i<v;i++)
  {
      for(int j=0;j<v;j++)
      {
          if(visited[i]&&!visited[j]&&graph[i][j]>0)
            cout<<i<< " - "<<j<<endl;
      }
  }
  return mincut;

}
int main()
{
    // Let us create a graph shown in the above example
    int graph[v][v] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout<<"MIN Cut "<<endl;
    cout<<minCut(graph, 0, 5)<<endl;

    return 0;
}
