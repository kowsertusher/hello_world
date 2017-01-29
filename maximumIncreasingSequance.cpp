#include<bits/stdc++.h>
#define N 1000
using namespace std;

int dp[N],dir[N],arr[N],n,start;

int len(int u)
{
    if(dp[u]!=-1) return dp[u];
    int mist = 0;
    for(int v = u+1;v<n;v++)
    {
        if(arr[v]>arr[u])
        {
            int temp = len(v);
            if(temp>mist)
            {
                mist = temp;
                dir[u] = v;
            }
        }
    }
    dp[u] = mist+1;
    return dp[u];
}

int LIS()
{
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    int maxIs=0;
    for (int i=0;i<n;i++)
    {
        int temp = len(i);
        if(temp>maxIs)
        {
            maxIs = temp;
            start = i;
        }
    }
    return maxIs;
}
void path()
{
    while(start!=-1)
    {
        cout<<start<<" "<<arr[start]<<endl;;
        start = dir[start];
    }
}
/*
int LIS()
{
    vector<int> lis(n,1);
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i]&&(lis[i]+1)>lis[j])
                lis[j] = lis[i]+1;
        }
    }
    int maxSI=0;

    for (int i=0;i<n;i++)
        maxSI = max(maxSI,lis[i]);

    return maxSI;
}
*/


void read()
{
    freopen("input.txt","r",stdin);
}
int main()
{
    read();
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    cout<<LIS()<<endl;
    path();
}


