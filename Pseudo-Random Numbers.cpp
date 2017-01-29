#include<bits/stdc++.h>
using namespace std;

void read()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
typedef long long ll;

int main()
{
    //read();
    ll z,i,m,l,j=0;
    int cc=0;

    while(cin>>z>>i>>m>>l)
    {
        if(z==0&&i==0&&m==0&&l==0) break;
        bool flag = false;
        vector<ll> v;
        j=1;
        l = ((z*l)+i)%m;
        while(1)
        {
            v.push_back(l);
            l = ((z*l)+i)%m;
            for(int i=0;i<v.size();i++)
            {
                if(v[i]==l)
                {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            j++;
        }
        printf("Case %d: %d\n",++cc,j);
        v.clear();
    }
    return 0;
}

