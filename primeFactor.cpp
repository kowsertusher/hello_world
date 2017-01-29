#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void read()
{
    freopen("Input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    vector<long long> v;

   //read();
   long long n;

   while(cin>>n)
   {
    if(n==0) break;
    long long t = n;
    if(n<0)
    {
        v.push_back(-1);
        n = -n;
    }
    while (n%2 == 0)
    {
        v.push_back(2);
        n = n/2;
    }


    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        v.push_back(n);

    printf("%lld = %lld",t,v[0]);
    for(int i=1;i<v.size();i++)
        printf(" x %lld",v[i]);
    cout<<endl;
    v.clear();
  }


    return 0;
}
