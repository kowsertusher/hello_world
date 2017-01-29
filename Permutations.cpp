#include<bits/stdc++.h>
using namespace std;

 void read()
 {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 }
 typedef long long ll;
 ll factorial[21];
 ll fat()
 {
     factorial[0] =1;
     for(int i=1;i<21;i++)
     {
       factorial[i] = factorial[i-1]*i;
     }
 }

 int main()
 {
     read();
     fat();
     int t;
     cin>>t;
        //cout<<0%1<<endl;
     while(t--)
     {
         long long permutation;
         string s;
         cin>>s;
         cin>>permutation;
         string result(s);

     for(int i = 0; i < s.size(); ++i)
       {
          sort(result.begin() + i, result.end());
          if (permutation == 0)
             break;
          int charPos = i + permutation / factorial[s.size() - i - 1];
          swap(result[i], result[charPos]);
          permutation = permutation % factorial[s.size() - i - 1];
      }

        cout<<result<<endl;
     }
     return 0;
 }
