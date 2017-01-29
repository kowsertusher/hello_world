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
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main(){
    //read();
    long long a[10000000];
    long long count=0,sum=0;
    long long i=0;
    while(scanf("%d",&a[i])!=EOF)
    {
        i++;
        sort(a,a+i);
        if(i%2)
        {
                count=i/2;
                cout<<a[count]<<endl;
        }
        else
        {
                count=i/2;
                sum=a[count-1]+a[count];
                sum=sum/2;
                cout<<sum<<endl;
       }
    }




  return 0;
}
