
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
    freopen("output.txt","w",stdout);
}

int main(){
    vector <int> v;
    set    <int> s;
    //read();
   int count1=0;
   unsigned res=859963392;

   for(int i=1; ;i++ ){
        int a=i;
        while(!(a%2)){
            a=a/2;
        }
        while(!(a%3)){
            a=a/3;
        }
        while(!(a%5)){
            a=a/5;
        }
        if(a==1) count1++;



        if(count1==150){
                //cout<<i<<endl;
        break;
        }
   }
        cout<<"The 1500'th ugly number is "<<""<<res<<"."<<endl;


  return 0;
}
