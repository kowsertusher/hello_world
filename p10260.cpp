#include<bits/stdc++.h>
using namespace std;

void read(){
    freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
}

int main(){
    vector <int> v;
    set    <int> s;
    read();
    char str[30];
    char a[30];
    while(cin>>str){
            int m=0;
            int i=0;
            if(str[i]=='B'||str[i]=='F'||str[i]=='P'||str[i]=='V')
               a[m++]=1+48;
            if(str[i]=='C'||str[i]=='G'||str[i]=='J'||str[i]=='K'||str[i]=='Q'||str[i]=='S'||str[i]=='X'||str[i]=='Z')
               a[m++]=2+48;
            if(str[i]=='D'||str[i]=='T')
                a[m++]=3+48;
            if(str[i]=='L')
                a[m++]=4+48;
            if(str[i]=='M'||str[i]=='N')
                a[m++]=5+48;
            if(str[i]=='R')
                a[m++]=6+48;
        for( i=1;i<strlen(str);i++){
            if((str[i]=='B'||str[i]=='F'||str[i]=='P'||str[i]=='V')&&(str[i-1]!='B'&&str[i-1]!='F'&&str[i-1]!='P'&&str[i-1]!='V'))
               a[m++]=1+48;
            if((str[i]=='C'||str[i]=='G'||str[i]=='J'||str[i]=='K'||str[i]=='Q'||str[i]=='S'||str[i]=='X'||str[i]=='Z')&&
               (str[i-1]!='C'&&str[i-1]!='G'&&str[i-1]!='J'&&str[i-1]!='K'&&str[i-1]!='Q'&&str[i-1]!='S'&&str[i-1]!='X'&&str[i-1]!='Z'))
               a[m++]=2+48;
            if((str[i]=='D'||str[i]=='T')&&(str[i-1]!='D'&&str[i-1]!='T'))
                a[m++]=3+48;
            if(str[i]=='L'&&str[i-1]!='L')
                a[m++]=4+48;
            if((str[i]=='M'||str[i]=='N')&&(str[i-1]!='M'&&str[i-1]!='N'))
                a[m++]=5+48;
            if(str[i]=='R'&&str[i-1]!='R')
                a[m++]=6+48;

        }

        a[m]='\0';
        cout<<a<<endl;

    }



  return 0;
}
