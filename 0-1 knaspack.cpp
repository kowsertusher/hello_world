#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int knapsack(int n,int w,int wight[],int val[])
{

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0||j==0) dp[i][j] =0;
            else if(wight[i-1]>j) dp[i][j] = dp[i-1][j];
            else if(wight[i-1]<=j) dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wight[i-1]]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
}
int knapsackSolution(int n,int W,int wight[])
{
    int i=n,w=W;
    vector<int> v;
    while(i&&w>0)
    {
        if(dp[i][w]!=dp[i-1][w])
        {
            v.push_back(i);
            w -=wight[i-1];
            i--;
        }
        else i--;
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}



int main()
{
    memset(dp,-1,sizeof(dp));
    int n=3,w=26;
    //cin>>n>>w;
    int wight[] = {17,2,24};
    int val[] ={72,44,31};
    knapsack(n,w,wight,val);
    cout<<dp[n][w]<<endl;
    knapsackSolution(n,w,wight);

}
