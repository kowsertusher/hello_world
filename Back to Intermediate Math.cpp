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
        double d,v,u;
        cin>>d>>v>>u;
        if(v==0||u<=v||u==0) printf("Case %d: can't determine\n",tc);
        else
        {
            double res1 = d/sqrt((u*u)-(v*v));
            double res2 = d/u;
            printf("Case %d: %.3f\n",tc,(res1-res2));
        }
    }
}
