#include<bits/stdc++.h>
using namespace std;

void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
   // read();
    long long n;
    while(cin>>n)
    {
        if(n==0) break;
        long long t = sqrt(n);
        t = pow(t,2);
        if(n==t) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        //cout<<n<<" "<<t<<endl;
    }
}
