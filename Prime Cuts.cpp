#include<bits/stdc++.h>
using namespace std;
#define max 1000
bool prime[max];
void read()
 {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 }
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
    //read();
    int n ,k;
    while(cin>>n>>k)
    {
        int k1 = k;
        vector<int> v;
        v.push_back(1);
        for(int i=2;i<=n;i++)
        {
            if(prime[i]) v.push_back(i);
        }
        if(v.size()%2) k = 2*k -1;
        else k = 2*k;
        int low,high;
        if(k>=v.size() )
        {
            low = 0;
            high = v.size();
        }
        else if(v.size()%2)
        {
            low = (v.size()/2) - (k/2);
            high = (v.size()/2) + (k/2)+1;
        }
        else
        {
            low = (v.size()/2) - (k/2);
            high = (v.size()/2) + (k/2);
        }
        printf("%d %d: ",n,k1);
        for(int i = low;i<high;i++)
            if(i!=high-1)
            cout<<v[i]<<" ";
        else cout<<v[i];
        cout<<endl<<endl;
    }
 }
