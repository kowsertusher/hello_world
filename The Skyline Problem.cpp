#include<bits/stdc++.h>
using namespace std;

int cnt[100000];

void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
    //read();
    memset(cnt,0,sizeof(cnt));
    int l,h,r,max1=0;
    while(cin>>l>>h>>r)
    {
        for(int i=l;i<r;i++)
        {
            cnt[i] = max(cnt[i],h);
        }
        max1 = max(max1,r);
    }
    int p =0;
    for(int i=1;i<max1;i++)
    {
        if(cnt[i]!=p)
        {
            cout<<i<<" "<<cnt[i]<<" ";
            p = cnt[i];
        }
    }
    cout<<max1<<" "<<cnt[max1]<<endl;
}
