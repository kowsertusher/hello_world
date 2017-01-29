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
     string s1,s2;
     while(getline(cin,s1))
     {     getline(cin,s2);
         //cout<<s1<<" "<<s2<<"     ";
         string r="";
         for(int i=0;i<s1.size();i++)
         {
             for(int j=0;j<s2.size();j++)
             {
                 if(s1[i]==s2[j])
                 {
                      r+=s1[i];
                      s2.erase(s2.begin()+j);
                      break;
                 }
                 //cout<<s2<<endl;
             }
         }
         //cout<<r<<endl;
         string temp ="";
         while(!r.empty())
         {
             char r1=r[0];
             for(int j=0;j<s1.size();j++)
             {
                 if(r1==s1[j])
                 {
                     temp+=s1[j];
                     r.erase(r.begin());
                     s1.erase(s1.begin()+j);
                     break;

                 }
             }
         }
         sort(temp.begin(),temp.end());
         cout<<temp<<endl;
     }
 }
