#include<bits/stdc++.h>
using namespace std;
void rep(string &s)
{
    for(int i=0;i<s.length();i++)
    {
        if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))) s[i] = ' ';
    }
}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    //read();
    string s;
    while(getline(cin,s))
    {
        rep(s);
        istringstream ss(s);
        int cnt = 0;
        while(ss>>s)
        {
            cnt++;
        }
        cout<<cnt<<endl;
    }
}
