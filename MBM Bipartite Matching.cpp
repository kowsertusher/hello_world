#include<bits/stdc++.h>
using namespace std;


bool bpm(vector<bool> *vpgraph,int u, bool seen[],int matchR[] ,int M,int N)
{
    for(int v=0;v<vpgraph[u].size();v++)
    {
        if(vpgraph[u][v]&&!seen[v])
        {
            seen[v] = true;
            if(matchR[v]<0||bpm(vpgraph,matchR[v],seen,matchR,M,N))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int MBM(vector<bool> *vpgraph,int M,int N)
{
    int matchR[N];
    memset(matchR,-1,sizeof(matchR));
    int cnt = 0;
    for(int u = 0;u<M;u++)
    {
        bool seen[N];
        memset(seen,0,sizeof(seen));
        if(bpm(vpgraph,u,seen,matchR,M,N))
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("input.txt","r",stdin);

    int M,N;
    cin>>M>>N;
    vector<bool> *vpgraph = new vector<bool> [M];
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            bool flag;
            cin>>flag;
            vpgraph[i].push_back(flag);
        }
    }
    cout<< "Maximum number of applicants that can get job is ";
    cout<<MBM(vpgraph,M,N)<<endl;

}

