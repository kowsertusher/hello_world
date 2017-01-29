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
    //read();

   int t,n,f;

    scanf("%d",&t);
    for(int tt=0;tt<t;tt++){
        cin>>n>>f;

        for(int cc=0;cc<f;cc++){
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=i;j++)
                {
                    cout<<i;
                }
                cout<<endl;
            }
        for(int i=n-1;i>=1;i--)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<i;
            }
            cout<<endl;
        }
        if(cc!=(f-1)||tt!=(t-1)) cout<<endl;
      }
   }



  return 0;
}

