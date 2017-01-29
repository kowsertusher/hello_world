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
   // read();
    int n,c,count,temp;
        scanf("%d",&c);
        for(int cc=1;cc<=c;cc++){
            cin>>n;
            count=0;
            for(int i=0;i<n;i++){
                cin>>num[i];
            }
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(num[i]>num[j]){
                        temp=num[i];
                        num[i]=num[j];
                        num[j]=temp;
                        count++;
                    }

                }
            }
            cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
        }

  return 0;
}

