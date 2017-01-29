#include<bits/stdc++.h>
using namespace std;

vector<int> *edge;
vector<int> *transposeEdge;
int *visited,*finishTime,*perent,*discovaryTime;
int time1;
int vertix;

void DFSUtil(int v)
{
    visited[v] = 1;
    cout<<v<<" ";
    for(vector<int> ::iterator it = edge[v].begin();it!=edge[v].end();++it)
    {
        if(visited[*it]==0)
        {
            DFSUtil(*it);
        }
    }

}
void getTreanspose()
{
    transposeEdge = new vector<int> [vertix+1];
    for(int i=1;i<=vertix;i++)
    {
        for(vector<int> ::iterator it = edge[i].begin();it!=edge[i].end();++it)
        {
            transposeEdge[*it].push_back(i);
        }
    }
    edge = transposeEdge;
}
void dfsVisit(int v , stack<int> &myStack)
{
    visited[v] = 1;
    for(vector<int> ::iterator it = edge[v].begin();it!=edge[v].end();++it)
    {
        if(visited[*it]==0)
        {
            dfsVisit(*it,myStack);
        }
    }
    myStack.push(v);

}
void scc()
{
    for(int i=0;i<=vertix;i++)
        visited[i] =0;

    stack<int> myStack;

    for(int i=1;i<=vertix;i++)
    {
        if(visited[i]==0)
            dfsVisit(i,myStack);
    }
     for(int i=0;i<=vertix;i++)
        visited[i] =0;
    getTreanspose();
    while(!myStack.empty())
    {
        int v = myStack.top();
        myStack.pop();
        if(visited[v]==0)
        {
            DFSUtil(v);
            cout<<endl;
        }
    }


}
void read()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}
int main()
{
    //read();
    cin>>vertix;
    edge = new vector<int> [vertix+1];
    visited = new int [vertix+1];

    //memset(visited,0,sizeof(visited));
    int nEdge;
    cin>>nEdge;
    for(int i=1;i<=nEdge;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
    }
    cout<<"SCC"<<endl;
    scc();
    return 0;

}
