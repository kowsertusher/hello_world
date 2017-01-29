#include<bits/stdc++.h>
using namespace std;

const int max1=1000000;
int num[max1];
char str[max1];
typedef long long ll;
///typedef string str;
class mycase{
public:
    int cc;
    int n;
};
void read(){
    freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
}

int main(){
    vector <int> v;
    set    <int> s;
    read();
    int n,m;
   int a[10],b[10];
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];


    for(int i=0;i<m;i++)
        cin>>b[i];
    int low=0;int high=m-1;
    int sum;
    cin>>sum;
     int count=0;
    while(low<n)
    {
     if((a[low]+b[high])>sum&&high>0)
     {
         high--;
         ///cout<<high<<" ";
     }

     if((a[low]+b[high]==sum))
     {   count++;

     }
     low++;
    }
    cout<<count<<endl;

  return 0;
}

