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
   /// read();
   ll n,k,res;

   while(scanf("%lld %lld",&n,&k)!=EOF){

        res=((n*k)-1)/(k-1);

        cout<<res<<endl;
   }



  return 0;
}

