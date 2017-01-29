#include<bits/stdc++.h>
using namespace std;
const int v=8;
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
int disjoinedPath(int graph[v][v],int s,int t)
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
    int graph[v][v] = { {
                            0,1,1,1,0,0,0,0
                        },
                        {
                            0,0,1,0,0,0,0,0
                        },
                        {
                            0,0,0,1,0,0,1,0
                        },
                        {
                            0,0,0,0,0,0,1,0
                        },
                        {
                            0,0,1,0,0,0,0,1
                        },
                        {
                            0,1,0,0,0,0,0,1
                        },
                        {
                            0,0,0,0,0,1,0,1
                        },
                        {
                            0,0,0,0,0,0,0,0
                        }
                      };

        cout<<"Maximum Disjoin Path = "<<disjoinedPath(graph,0,7)<<endl;
    /*
    int e,V;
    cin>>V>>e;
    int graph[V][V];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x][y] = 1;
    }
    */

}

