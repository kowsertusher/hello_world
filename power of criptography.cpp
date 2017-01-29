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
    char num1[100000]="1",num2[100000]="2",num3[100000];
    ///cin>>num1>>num2;
    int n,a,div,rem,m;
    ///cin>>num1>>num2;
    while(scanf("%s%s",num1,num2)!=EOF) {
         n=1;
         int power=atoi(num1);
     while(strcmp(num1,num2)){
    m=0;   n++;
        int l1=strlen(num1);
        int l3=l1;
        l1--;
        div=0;
        a=0;
        while(l3){
            if(l1>=0) a=power*(num1[l1]-48);
            a+=div;
            rem=a%10;
            num3[m]=rem+48;
            m++;
            div=a/10;
            l1--;
            l3--;
           a=0;
        }

        if(div>0) {
                while(div){
                    rem=div%10;
                div=div/10;
                num3[m]=rem+48;
                m++;}
        }

        num3[m]='\0';
        m=0;
        for(int j=strlen(num3)-1;j>=0;j--){
            num1[m]=num3[j] ;
            m++;
        }
        num1[m]='\0';
        }
        cout<<n;
        cout<<endl;
    }

    //}



  return 0;
}


