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

    while(cin>>n)
    {
        if(n==0) break;
        if(n<=101) printf("f91(%d) = 91\n",n);
        else printf("f91(%d) = %d\n",n,(n-10));
    }


}
