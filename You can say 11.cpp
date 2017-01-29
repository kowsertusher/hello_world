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
    string s;
    while(cin>>s)
    {
        if(!s.compare("0")) break;
        int r=0,k=0;
        int l = s.size();
        for(int j=0;j<l;j++){
           //cout<<r<<" "<<j<<" "<<endl;
           k=r*10+(s[j]-48);
           r=k%11;

        }
        //cout<<r<<"end"<<endl;
        if(r==0) cout<<s<<" is a multiple of 11."<<endl;
        else cout<<s<<" is not a multiple of 11."<<endl;
    }
}
