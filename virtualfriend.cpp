#include<bits/stdc++.h>
using namespace std;

int *Rank,*parent,n,e;
void makeSet()
{
    Rank = new int [2*n+10];
    parent = new int [2*n+10];
    for(int i=0;i<2*n+10;i++) Rank[i]=1,parent[i] = i;
}
int find(int x)
{
    if(parent[x]!=x) parent[x] = find(parent[x]);
    return parent[x];
}
int  Union(int u, int v)
{
    int x = find(u),y = find(v);
    if(x==y) return Rank[x];

    if(Rank[x]<Rank[y])
    {
         parent[x] = y;
         return Rank[y] += Rank[x];
    }
    else
    {
        parent[y] = x;
        return Rank[x] += Rank[y];

    }
}
int main()
{
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++)
    {
        cin>>n;
        makeSet();
        map<string , int > f;
        int cnt =0;
        for(int i=0;i<n;i++)
        {
            string s,s1;
            cin>>s>>s1;
            int tx = f[s];
            if(tx==0) f[s] = ++cnt, tx = cnt;
            int ty = f[s1];
            if(ty==0) f[s1] = ++cnt,ty = cnt;
            cout<<Union(tx,ty)<<endl;
        }

    }


    return 0;
}

