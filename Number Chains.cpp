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
    vector<long> v;
    long n;
    while (cin>>n)
    {
        string s1,s2;

        if(n==0) break;

        long r = n;
        int cnt = 0;
        int y =20;
        int flag = true;
        cout<<"Original number was "<<r<<endl;
        while (1)
        {
            stringstream ss;
            ss<<r;
            ss>>s1;
            sort(s1.begin(),s1.end());
            s2 = s1;
            reverse(s2.begin(),s2.end());
            stringstream ss1,ss2;
            ss1<<s1;
            long r1;
            ss1>>r1;
            ss2<<s2;
            long r2;
            ss2>>r2;
            cnt++;
            long r3 = r2 - r1;
            cout<<r2<<" - "<<r1<<" = " <<r3<<endl;
            for(int i=0;i<v.size();i++)
            {
                if(v[i]==r3)
                {
                    flag = false;
                    break;
                }
            }
            if(flag==false) break;
            v.push_back(r3);
            r = r3;


        }
        cout<<"Chain length "<<cnt<<endl<<endl;;
        v.clear();

        //cout<<r1<<" "<<r2<<endl;
        //cout<<s1<<endl;
        //cout<<s2<<endl;

    }
}
