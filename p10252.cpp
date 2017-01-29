#include<bits/stdc++.h>
using namespace std;

const int max1=10000;
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

   char str1[max1],str2[max1];

   char str3[max1];

   while(scanf("%s%s",str1,str2)!=EOF){
        int l1=strlen(str1);
        int l2=strlen(str2);

        if(l1>l2){
            strcpy(str,str1);
            strcpy(str1,str2);
            strcpy(str2,str);
        }
        ///cout<<str1<<" "<<str2<<endl;
        int m=0;
        for(int i=0;i<strlen(str1);i++){
            for(int j=0;j<strlen(str2);j++){
              if(str1[i]==str2[j])
              {   str2[j]='5';
                  str3[m++]=str1[i];
                  break;
              }
            }
        }
        str3[m]='\0';
        sort(str3,str3+strlen(str3));
        cout<<str3<<endl;

   }

  return 0;
}
