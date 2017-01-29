#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    string s;
    while(cin>>n)
    {
        s="";
        if(n<0) break;
        if(n==0) s +=48+0;
        while(n!=0)
        {
            int rem = n%3;
            s +=48+rem;
            n = n/3;
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
}
