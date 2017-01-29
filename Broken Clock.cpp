#include<bits/stdc++.h>
using namespace std;

int main()
{
    int timef;
    cin>>timef;
    string s;
    cin>>s;
    if(timef==12)
    {
        if(s[0]=='0'&&s[1]=='0')
            s[1] = '1';
        else if(s[0]=='1'&&s[1]>'2')
            s[0] = '0';
        else if(s[0]>'1'&&s[1]!='0')
            s[0] = '0';
        else if(s[0]>'1'&&s[1]=='0')
            s[0] = '1';
    }
    else if(timef==24)
    {
        if(s[0]=='2'&&s[1]>='4')
            s[0] = '0';
        else if(s[0]>'2')
            s[0] = '0';
    }
    if(s[3]>='6')
        s[3] = '0';
    cout<<s<<endl;
}
