#include<bits/stdc++.h>
using namespace std;

long long dp[10][8000];
int n=5;

int cntNumberOfWay(int i,int m,int coin[])
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
        r1 = cntNumberOfWay(i,m-coin[i],coin);
    }
    r2 = cntNumberOfWay(i+1,m,coin);
    dp[i][m] = r1+r2;

    return dp[i][m];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int make;
    int coin[] = {50,25,10,5,1};
    while(cin>>make)
    cout<<cntNumberOfWay(0,make,coin)<<endl;
}

