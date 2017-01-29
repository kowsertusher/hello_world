#include<bits/stdc++.h>
using namespace std;
#define MX 1000001
bool prime[MX];

void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for(int i=2;i<=sqrt(MX);i++)
    {
        if(prime[i])
        {
            for(int j =i*i;j<=MX;j+=i)
                prime[j] = false;
        }
    }
    //read();
    int n;
    while(cin>>n)
    {
        string s;
        stringstream is;
        int temp = n;
        is<<n;
        is>>s;
        reverse(s.begin(),s.end());
        //cout<<s<<endl;
        stringstream i;

        i<<s;
        i>>n;
        //cout<<n<<endl;
        if(prime[n]&&prime[temp]&&n!=temp) cout<<temp<<" is emirp."<<endl;
        else if(prime[temp]) cout<<temp<<" is prime."<<endl;
        else cout<<temp<<" is not prime."<<endl;

    }
}
