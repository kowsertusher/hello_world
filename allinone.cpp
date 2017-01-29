#include<bits/stdc++.h>
#define MX 1005
using namespace std;
string s1,s2;
int dp[MX][MX];
bool visited[MX][MX];
string s;
int LIS(int i, int j)
{
    if(s1[i]=='\0'||s2[j]=='\0')
    {
        return 0;
    }
    if(visited[i][j]) return dp[i][j];

    int ans =0;
    if(s1[i]==s2[j])
    {
        ans = 1+LIS(i+1,j+1);
       // s+=s1[i];
    }
    else
    {
        ans = max(LIS(i+1,j),LIS(i,j+1));
    }
    visited[i][j] = true;
    dp[i][j] = ans;
    return dp[i][j];
}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    //read();
    while(cin>>s1)
    {
        cin>>s2;
        memset(visited,false,sizeof(visited));
        if(LIS(0,0)==s1.size()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}


