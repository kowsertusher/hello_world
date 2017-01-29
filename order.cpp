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
    int a,mod;
    cin>>a>>mod;
    //cout<<divisor(n)<<endl;
    for(int i=1;i<=divisor(mod);i++)
    {
        int temp = pow(a,i);
        //cout<<temp<<endl;
        temp = temp%mod;
        if(temp==1)
        {
            cout<<i <<endl;
            break;
        }
    }
}
