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
    int n;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>n)
    {
        if(n==0)
        {
            cout<<"END OF OUTPUT"<<endl;
            break;
        }
        int sum = 1;
        for(int i=2;i<=n/2;i++)
        {
            if(n%i==0) sum+=i;
        }
        if(sum==n&&n!=1)
        {
            cout<<setw(5)<<n;
            cout<<"  "<<"PERFECT"<<endl;
        }
        else if(sum<n||n==1)
        {
            cout<<setw(5)<<n;
            cout<<"  "<<"DEFICIENT"<<endl;
        }
        else if(sum>n)
        {
            cout<<setw(5)<<n;
            cout<<"  "<<"ABUNDANT"<<endl;
        }
    }
}
