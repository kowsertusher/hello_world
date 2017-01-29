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
    for(int tc=1;tc<=t;tc++)
    {
        int a,b,sum=0;

        cin>>a>>b;

        for(int i=a;i<=b;i++)
        {
            if(i%2) sum+=i;
        }
        //cout<<sum<<endl;
        printf("Case %d: %d\n",tc,sum);
    }
}
