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
    int t;
    cin>>t;
    int sum=0;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        //cout<<s<<endl;
        if(!s.compare("donate"))
        {
            int n;
            cin>>n;
            sum+=n;
        }
        else cout<<sum<<endl;
    }
}
