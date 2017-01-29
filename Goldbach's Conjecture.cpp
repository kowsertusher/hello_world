#include<bits/stdc++.h>
using namespace std;
#define max 1000000

bool prime[max];

void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
    //read();
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i<=sqrt(max);i++)
    {
        if(prime[i])
        {
            for(int j =i*i;j<=max;j+=i)
                prime[j] = false;
        }
    }
    int n ;
    while(cin>>n)
    {
        if(n==0) break;
        bool flag = false;
        int res ,i;
        for(i=2;i<max;i++)
        {
            if(prime[i]) res = n - i;
            if(prime[res]) flag = true;
            if(flag) break;
        }
        printf("%d = %d + %d\n",n,i,res);
    }
}
