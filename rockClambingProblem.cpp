#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
 int rock[3][3]={{-1,2,5},{4,-2,3},{1,2,10}};
int r,c;
int call(int i,int j)
{

    if(i>=0&&i<r&&j>=0&&j<c)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int res = INT_MIN;
        res = max(res,call(i+1,j)+rock[i][j]);
        res = max(res,call(i+1,j-1)+rock[i][j]);
        res = max(res,call(i+1,j+1)+rock[i][j]);

        return dp[i][j] = res;
    }
    else return 0;
}


int main()
{
    memset(dp,-1,sizeof(dp));
    r=c=3;
    cout<<call(0,0)<<endl;
}
