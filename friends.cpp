#include<bits/stdc++.h>
using namespace std;

vector<int> *edge;
int *visited,*finishTime,*perent,*discovaryTime;
int time1;
int vertix;
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
void topoSort()
{


    int maxcnt=0;
    for(int i=1;i<=vertix;i++)
    {
        for(int i=0;i<=vertix;i++)
              visited[i] =0;
        stack<int> myStack;
        dfsVisit(i,myStack);
        int size = myStack.size();
        maxcnt = max(maxcnt,size);
    }
    cout<<maxcnt<<endl;

}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
    //read();
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++)
    {
       int nEdge;
       cin>>vertix>>nEdge;
       edge = new vector<int> [vertix+1];
       visited = new int [vertix+1];

      for(int i=1;i<=nEdge;i++)
       {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
      }
      topoSort();
    }
}


