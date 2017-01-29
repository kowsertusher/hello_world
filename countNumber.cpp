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

    for(int tc=0;tc<t;tc++)
    {
        int n;
        cin>>n;
        string s="";
        for(int i=1;i<=n;i++)
        {
            string temp;
            stringstream ss;
            ss<<i;
            ss>>temp;
            s+=temp;
        }
        int arr[10];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-48]++;
        }
        for(int i=0;i<10;i++)
        {
            cout<<arr[i];
            if(i!=9) cout<<" ";
            if(i==9) cout<<endl;
        }
    }

}
