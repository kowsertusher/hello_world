#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while(b!=0)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
int divisor(int n)
{
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(gcd(n,i)==1) cnt++;

    }
    return cnt;
}

int main()
{
    int n;
    cin>>n;
    //cout<<divisor(n)<<endl;
    for(int j=1;j<=n;j++)
    {
        if(gcd(j,n)==1)
        {
            bool flag = true;
            set<long long> s;
            for(int i=1;i<=divisor(n);i++)
            {
                long long temp = pow(j,i);
                temp = temp%n;
                cout<<temp<<" ";
                s.insert(temp);
            }
            cout<<"   j= "<<j<<"<<"<<endl;
            if(s.size()==divisor(n)) cout<<j<<endl;
            s.clear();
        }
    }
}

