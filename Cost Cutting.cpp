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
        int arr[3];

        cin>>arr[0]>>arr[1]>>arr[2];

        sort(arr,arr+3);
        printf("Case %d: %d\n",tc,arr[1]);

    }


}
