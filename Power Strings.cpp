#include<bits/stdc++.h>
using namespace std;
void failureFanction(int f[],string& pattern)
{
    int plen=pattern.length();
    int len=0;
    f[0] = 0;
    for(int i=1;i<plen;)
    {
        if(pattern[i]==pattern[len]) f[i++] = ++len;
        else
        {
            if(len) len = f[len-1];
            else f[i++]=0;
        }
    }
}
void read()
{
    freopen("Input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}


int main()
{
    //read();
    string s;
    while(cin>>s)
    {
        if(!s.compare(".")) break;
        int len = s.length();
        int f[s.length()];
        failureFanction(f,s);
        printf("%d\n",(len/(len-f[len-1])));
    }
    return 0;
}
