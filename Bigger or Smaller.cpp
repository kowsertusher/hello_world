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
    double a,b;
    int cnt=1;
    read();
    while(cin>>a>>b)
    {
        cout<<a<<endl;
        cout<<b<<endl;
        if(a>b) printf("Case %d: Bigger\n",cnt);
        else if (a==b) printf("Case %d: Same\n",cnt);
        else printf("Case %d: Smaller\n",cnt);
        cnt++;
    }
}
