#include<bits/stdc++.h>
using namespace std;
const int v=6;
bool bfs(int grap[v][v],int s , int t, int parent[])
{
    queue<int> q;
    vector<bool> visited(v,false);

    visited[s] = true;
    parent[s] = -1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<v;i++)
        {
            if(!visited[i]&&grap[u][i]>0)
            {
                visited[i] = true;
                parent[i] = u;
                q.push(i);
            }
        }
    }
    return visited[t];

}
int maxFlow(int graph[v][v],int s,int t)
{
    int MAXFLOW =0;
    int rGraph[v][v];
    int parent[v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            rGraph[i][j] = graph[i][j];
        }
    }
    while(bfs(rGraph,s,t,parent))
    {
        int minFlow = INT_MAX;
        for(int v=t;v!=s;v=parent[v])
        {
            int u = parent[v];
            minFlow = min(minFlow,rGraph[u][v]);
        }
        for(int v=t;v!=s;v=parent[v])
        {
            int u = parent[v];
            //minFlow = min(minFlow,rGraph[u][v]);
            rGraph[u][v] -=minFlow;
            rGraph[v][u] +=minFlow;
        }
        MAXFLOW+=minFlow;


    }
    return MAXFLOW;
}
int main()
{
    /*int graph[v][v] = { {
                            0,16,13,0,0,0
                        },
                        {0,0,10,12,0,0},
                        {
                            0,4,0,0,14,0
                        },
                        {
                            0,0,9,0,0,20
                        },
                        {
                            0,0,0,7,0,4
                        },
                        {
                            0,0,0,0,0,0
                        }
                      };
        cout<<maxFlow(graph,0,5)<<endl;
    */

    int e;
    cin>>e;
    int graph[v][v];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x][y] = w;
    }
    cout<<"Maximum Flow "<<maxFlow(graph,0,5)<<endl;



}
/*
int e,V;
    cin>>V>>e;
    int graph[V][V];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x][y] = w;
    }
*/
