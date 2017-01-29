#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int knapsack(int n,int w,int wight[],int val[])
{
    if(n==0||w==0) return dp[n][w] =0;
    if(dp[n][w]!=-1) return dp[n][w];

    if(wight[n-1]>w) return dp[n][w] = knapsack(n-1,w,wight,val);
    dp[n][w] = max(knapsack(n-1,w,wight,val),val[n-1]+knapsack(n-1,w-wight[n-1],wight,val));
    return dp[n][w];
}

int main()
{
    memset(dp,-1,sizeof (dp));
    int n=4,w=5;
    //cin>>n>>w;
    int wight[] = {3,2,4,1};
    int val[] ={10,12,60,40};
    cout<<knapsack(n,w,wight,val)<<endl;
    //cout<<dp[n][w]<<endl;

}
