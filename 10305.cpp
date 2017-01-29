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
    for(int i=0;i<=vertix;i++)
        visited[i] =0;

    stack<int> myStack;

    for(int i=1;i<=vertix;i++)
    {
        if(visited[i]==0)
            dfsVisit(i,myStack);
    }
    vector<int> v;
    while(!myStack.empty())
    {
        v.push_back(myStack.top());
        myStack.pop();
    }

    for(int i=0;i<v.size();i++)
    {
        if(i!=v.size()-1) cout<<v[i]<<" ";
        else cout<<v[i]<<endl;
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
    int nEdge;
    while(cin>>vertix>>nEdge)
    {
       if(vertix==0&&nEdge==0) break;
       edge = new vector<int> [vertix+1];
       visited = new int [vertix+1];

      for(int i=1;i<=nEdge;i++)
      {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
     }
      topoSort();
    }
}

