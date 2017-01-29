#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll bigmod(ll n,ll p,ll m){
    if(p==0) return 1;
    else if(p%2==0) return ((bigmod(n,p/2,m))*(bigmod(n,p/2,m)))%m;
    else return ((n%m)*(bigmod(n,p-1,m)))%m;

}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main(){

    //read();
    ll n,p,m;
    while(cin>>n>>p>>m)
    {
    long long res=bigmod(n,p,m);
    cout<<res<<endl;
    }
    return 0;
}
