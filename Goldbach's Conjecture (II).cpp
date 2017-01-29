#include<bits/stdc++.h>
using namespace std;
#define max 33000


bool prime[max];
int cnt[max];

int main()
{
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for(int i=2;i<=sqrt(max);i++)
    {
        if(prime[i])
        {
            for(int j =i*i;j<=max;j+=i)
                prime[j] = false;
        }
    }
    vector<int> v;
    for(int i=2;i<max;i++)
    {
        if(prime[i]) v.push_back(i);
    }
    memset(cnt,0,sizeof(cnt));

    //cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i;j<v.size();j++)
        {
            if(v[i]+v[j]<max)
            cnt[v[i]+v[j]]++;
        }
    }

    int n;
    while(cin>>n)
    {
        if(n==0) break;
        cout<<cnt[n]<<endl;
    }

}

