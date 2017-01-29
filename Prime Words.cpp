#include<bits/stdc++.h>
using namespace std;

 void read()
 {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 }
 bool prime(int n)
 {
     bool flag = true;
     for(int i=2;i<=sqrt(n);i++)
     {
         if(n%i==0)
         {
             flag = false;
             break;
         }
     }
     return flag;
 }
 int main()
 {
     int arr[52];
     for(int i=0;i<52;i++)
        arr[i] = i+1;
     string s;
     //read();
     while(cin>>s)
     {
         int sum=0;
         for(int i=0;i<s.size();i++)
         {
             if(s[i]>='a'&&s[i]<='z')
             {
                 sum+=arr[s[i]-'a'];
                 //cout<<arr[s[i]-'a']<<" ";
             }
             else if(s[i]>='A'&&s[i]<='Z')
             {
                 sum+=arr[(s[i]-'A')+26];
                 //cout<<arr[(s[i]-'A')+26]<<" ";
             }
         }
         if(prime(sum)) printf("It is a prime word.\n");
         else printf("It is not a prime word.\n");
         //cout<<endl;
     }
 }
