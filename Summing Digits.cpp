#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    //read();
    ll n;
    while(cin>>n)
    {
        if(n==0) break;
        while((n/10)!=0)
        {
            string s;
            stringstream ss;
            ss<<n;
            ss>>s;
            int sum=0;
            for(int i=0;i<s.size();i++)
            {
                sum+=(s[i]-48);
            }
            n = sum;
        }
        cout<<n<<endl;
    }
}
