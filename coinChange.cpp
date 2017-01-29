#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int n=3;

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
/*
int table[n+1][m]
for(int i=0;i<m;i++)
    table[0][i] =1
int x,y;
for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)
        if(i-coin[j]) x = table[i-s[j]][j];
        else x =0;
        if(j>=1) y = table[i][j-1];
        else y =0;
        table[i][j] = x+y;

    return table[n][m-1];

*/

int main()
{
    memset(dp,-1,sizeof(dp));
    int make =4;
    int coin[] = {1,2,3};
    cout<<cntNumberOfWay(0,make,coin)<<endl;
}
