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
    scanf("%d ",&n);
    string s[n][2];
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i][0]);
        getline(cin,s[i][1]);
    }
    int q;
    scanf("%d ",&q);
    for(int i=0;i<q;i++)
    {
        string ss;
        getline(cin,ss);
        for(int j=0;j<n;j++)
        {
            if(!ss.compare(s[j][0]))
            {
                cout<<s[j][1]<<endl;
                break;
            }
        }
    }

    /*
    for(int i=0;i<n;i++)
    {
        cout<<s[i][0]<<endl;
        cout<<s[i][1]<<endl;
    }
    */

}
