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
        long long a,b,c;
        cin>>a>>b>>c;
        if((a+b<=c||b+c<=a||a+c<=b))
            printf("Case %d: Invalid\n",tc);
        else if (a==b&&b==c)
            printf("Case %d: Equilateral\n",tc);
        else if (a==b||b==c||a==c)
            printf("Case %d: Isosceles\n",tc);
        else
            printf("Case %d: Scalene\n",tc);
    }
}
