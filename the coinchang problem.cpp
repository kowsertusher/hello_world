#include<bits/stdc++.h>
using namespace std;
long dp[250][255];
long  cntNumberOfWay(int i,int m,int n,int coin[])
{
    if(i>=n)
    {
        if(m==0) return 1;
        else return 0;
    }
    if(dp[i][m]!=-1) return dp[i][m];
    int r1=0,r2=0;

    if(m-coin[i]>=0)
    {
        r1 = cntNumberOfWay(i,m-coin[i],n,coin);
    }
    r2 = cntNumberOfWay(i+1,m,n,coin);
    dp[i][m] = r1+r2;

    return dp[i][m];
}

int main()
{
    int n,m;
    cin>>n>>m;
    int coin[m];
    for(int i=0;i<250;i++)
    {
        for(int j=0;j<255;j++) dp[i][j] =-1;
    }
    for(int i=0;i<m;i++) cin>>coin[i];
    cout<<cntNumberOfWay(0,n,m,coin)<<endl;
}
