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
    while(cin>>t)
    {
        for(int i=0;i<t;i++)
        {
            int n;
            cin>>n;
            long long sum = 0;
            for(int j=0;j<n;j++)
            {
                long long a,b,c;
                cin>>a>>b>>c;
                sum+=a*c;
            }
            printf("%lld\n",sum);
        }
    }
}
