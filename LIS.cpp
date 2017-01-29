#include<bits/stdc++.h>
#define MX 1000
using namespace std;
string s1,s2;
int dp[MX][MX];
bool visited[MX][MX];
string s;
int LIS(int i, int j)
{
    if(s1[i]=='\0'||s2[j]=='\0')
    {
        //cout<<s<<endl;
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
void printLSM(int i,int j)
{
    if(s1[i]=='\0'||s2[j]=='\0')
    {
        cout<<s<<endl;
        return;
    }
    if(s1[i]==s2[j])
    {
        s+=s1[i];
        printLSM(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) printLSM(i+1,j);
        else printLSM(i,j+1);
    }
}

int main()
{
    memset(visited,false,sizeof(visited));
    cin>>s1>>s2;
    cout<<LIS(0,0)<<endl;
    printLSM(0,0);
}
