#include<bits/stdc++.h>
using namespace std;
#define MX 1010
bool prime[MX];
int main()
{
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for(int i=2;i<=sqrt(MX);i++)
    {
        if(prime[i])
        {
            for(int j =i*i;j<=MX;j+=i)
                prime[j] = false;
        }
    }
    vector<int> v;
    for(int i=0;i<MX;i++)
    {
        if(prime[i]) v.push_back(i);
    }
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<v.size()-1;j++)
        {
            int res = v[j]+v[j+1]+1;
            if(res==i&&prime[i]) cnt++;
        }
    }
    if(cnt>=k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
