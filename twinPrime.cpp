#include<bits/stdc++.h>
using namespace std;
#define max 20000000
bool prime[max];

void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
    //read();
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
    vector< pair<int,int> >twin;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i+1]-v[i]==2)
        {
           twin.push_back( make_pair(v[i],v[i+1]));
        }
    }
    v.clear();
    int n;
    while(cin>>n)
    {
        printf("(%d, %d)\n",twin[n-1].first,twin[n-1].second);
    }
    //cout<<twin[0].first<<" "<<twin[0].second<<endl;

}
