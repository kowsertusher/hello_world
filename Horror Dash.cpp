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
        int n;
        cin>>n;
        int maxcnt=0;
        for(int i=0;i<n;i++)
        {
            int cc;
            cin>>cc;
            maxcnt= max(maxcnt,cc);
        }
        printf("Case %d: %d\n",tc,maxcnt);
    }
}
