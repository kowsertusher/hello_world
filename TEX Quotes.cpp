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
    string s;
    long long count =0;
    while (getline(cin,s))
    {
        for(int i=0;i<s.size();i++)
        {
          if(s[i]=='"')
          {
                count++;
                if(count%2==1) cout<<"``";
                else cout<<"''";
         }
         else cout<<s[i];
      }
      cout<<endl;
   }
}
