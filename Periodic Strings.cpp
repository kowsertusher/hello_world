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
    cin>>n;
    string str;
    getline(cin,str);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        //cout<<s<<endl;
        getline(cin,str);
        //getline(cin,str);
        int len = s.length();
        int k=0;
        for(int j=1;j<s.length()+1;j++)
        {
            string ss = s.substr(k,j);
            string sr="";
            int r = len/ss.length();
            for(int l=0;l<r;l++)
                sr+=ss;
                //cout<<sr<<endl;
            if(!s.compare(sr))
            {
                cout<<ss.length()<<endl;
                if(i!=n-1) cout<<endl;
                break;
            }


        }
    }
}
