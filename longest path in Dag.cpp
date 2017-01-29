#include<bits/stdc++.h>
using namespace std;
vector<pair<int , int> > *edge;
int V;

void path(int s , int d, int disc[],int parent[])
{
    if(disc[d]==INT_MIN) return;
    stack<int > pth;
    for(int i=d;i!=s;i=parent[i]) pth.push(i);
    pth.push(s);
    while(!pth.empty())
    {
        int u = pth.top();
        pth.pop();
        cout <<u<<" ";
    }
    cout<<endl;
}

void topoSortUtil(int v,bool visited[],stack <int> &myStack)
{
    visited[v] = true;
    vector <pair<int , int>  > ::iterator it;
    for(it=edge[v].begin();it!=edge[v].end();++it)
    {
        if(!visited[it->first])
            topoSortUtil(it->first,visited,myStack);
    }
    myStack.push(v);
    //pair<int , int >p;
}
void longestPath(int s)
{
    stack<int> myStack;
    bool visited[V];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<V;i++)
    {
        if(!visited[i]) topoSortUtil(i,visited,myStack);
    }
    int disc[V],parent[V];
    for(int i=0;i<V;i++)
        disc[i] = INT_MIN;
    memset(parent,-1,sizeof(parent));
    disc[s] = 0;

    while(!myStack.empty())
    {
        int v = myStack.top();
        myStack.pop();
        vector <pair<int , int > > ::iterator i;
        if(disc[v]!=INT_MAX)
        {
            for(i=edge[v].begin();i!=edge[v].end();++i)
            {
                if(disc[i->first]<disc[v]+i->second)
                {
                    disc[i->first] = disc[v]+i->second;
                    parent[i->first] = v;
                }
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        (disc[i]==INT_MIN) ? cout<<"INF"<<" " : cout << disc[i]<<" ";
    }
    cout<<endl;
    path(1,4,disc,parent);


}


int main()
{

    int e;
    cin>>V>>e;
    edge = new vector< pair<int , int> > [V];
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edge[x].push_back(make_pair(y,w));
    }
    longestPath(1);
}
