#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int t =0;t<tc;t++)
    {
        int f,e,c;
        cin>>f>>e>>c;
        int sum=f+e,cnt=0;
        while(1)
        {
            cnt +=sum/c;
            //cout<<sum<<" "<<cnt<<endl;
            sum = (sum%c)+(sum/c);
            if(sum<c) break;
        }
        cout<<cnt<<endl;
    }
}
