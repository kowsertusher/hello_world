#include<bits/stdc++.h>
using namespace std;
int dp[1<<15+2];
int w[20][20],n;

int Set(int n,int pos){return n = n|(1<<pos);}
int reset(int n,int pos){return n = n&~(1<<pos);}
int check(int n,int pos){return  n&(1<<pos);}
int call(int mark)
{
    if((1<<n)-1==mark) return 0;
    if(dp[mark]!=-1) return dp[mark];
    int ans = 1<<28;

    for(int i=0;i<n;i++)
    {
        if(check(mark,i)==0)
        {
            int price = w[i][i];
            for(int j=0;j<n;j++)
            {
                if(i!=j and check(mark,j)!=0) price += w[i][j];
            }
            int ret = price + call(Set(mark,i));
            ans = min(ans,ret);

        }
    }
    //cout<<mark<< "  "<<ans<<endl;
    return dp[mark] = ans;
}
int main()
{

    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>w[i][j];
        }
    }
    int res = call(0);
    cout<<res<<endl;
}
