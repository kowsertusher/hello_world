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
int a[10000000];
void read(){
    freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
}

int main(){
    vector <int> v;
    set    <int> s;
    read();
    int n,m,sum,sum1,low,high;
  /// memset(a,0,sizeof(a));
    while(cin>>n>>sum){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    low=0;
    sum1=0;
    high=0;
    int max1=100000;
    sum1=a[0];
    while(high<n){
       if(sum1>=sum)
       {
           int count=high-low+1;
           max1=min(max1,count);
       }

       if(sum1>=sum&&low<=high){
            sum1=sum1-a[low];
            low++;
       }
       else if(sum>sum1)
       {
            high++;
            if(high<n)
           sum1=sum1+a[high];
       }

    }
    cout<<max1<<endl;
    }



  return 0;
}


