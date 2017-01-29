#include<bits/stdc++.h>
using namespace std;

void read()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
int main()
{
   // read();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long t;
        cin>>t;

        long long res = t*567;
        res /= 9;
        res +=7492;
        res *= 235;
        res /= 47;
        res -= 498;
        res = res%100;
        res = abs(res);
        res = res/10;
        cout<<res<<endl;
    }
}
