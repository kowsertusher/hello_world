#include<bits/stdc++.h>
using namespace std;

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
    while(t--)
    {
        string s;
        cin>>s;
        int len = s.size();
        if(len==3&&((s[0]=='o'&&s[1]=='n')||(s[0]=='o'&&s[2]=='e')||(s[1]=='n'&&s[2]=='e'))) cout<<1<<endl;
        else if(len==3&&((s[0]=='t'&&s[1]=='w')||(s[0]=='t'&&s[2]=='o')||(s[1]=='w'&&s[2]=='o'))) cout<<2<<endl;
        else if(len==5) cout<<3<<endl;
    }
}
