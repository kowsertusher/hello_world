#include<bits/stdc++.h>
using namespace std;

 void read()
 {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 }

 int main()
 {
     string s;
     int cnt=1;
     while(cin>>s)
     {
         if(!s.compare("*")) break;
         if(!s.compare("Hajj")) printf("Case %d: Hajj-e-Akbar\n",cnt);
         else printf("Case %d: Hajj-e-Asghar\n",cnt);
         cnt++;
     }
 }
