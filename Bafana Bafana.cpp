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
        int n,k,p;
        cin>>n>>k>>p;
        while(p)
        {
            k++;
            p--;
            if(k>n) k =1;
        }
        printf("Case %d: %d\n",tc,k);
    }

}
