#include<bits/stdc++.h>
using namespace std;
#define MX 1000001
long long dp[MX];

int main()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<MX;i++)
    {
        for(int j=i;j<MX;j+=i)
            dp[j]++;
    }
    int a,b,c;
    const int mod =  1073741824;
    long long result = 0;
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            for (int k=1;k<=c;k++)
            {
                int temp = i*j*k;
                result = ((result%mod)+(dp[temp]%mod))%mod;

            }
        }
    }
    cout<<result<<endl;
}
