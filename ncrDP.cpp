#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int ncr(int n, int r)
{
    if(r==1) return n;
    if(n==r) return 1;
    if(dp[n][r]!=-1) return dp[n][r];

    dp[n][r] = ncr(n-1,r)+ncr(n-1,r-1);
    return dp[n][r];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,r;
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}
