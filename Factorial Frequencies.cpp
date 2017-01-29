#include<bits/stdc++.h>
using namespace std;
void f(int n,char *num1 , char *num2 , char *num3)
{

    int a,div,rem,m;

    for(int i=1;i<=n;i++){
    m=0;
        int l1=strlen(num1);
        int l3=l1;
        l1--;
        div=0;
        a=0;
        while(l3){
            if(l1>=0) a=i*(num1[l1]-48);
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
}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
    //read();
    int n;
    while(cin>>n)
    {
        char num1[100000]="1",num2[100000]="2",num3[100000];
        if(n==0) break;
        f(n,num1,num2,num3);
        int arr[10];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<strlen(num1);i++)
            arr[num1[i]-48]++;
        printf("%d! --\n",n);
        printf("   (0)    %d    (1)    %d    (2)    %d    (3)    %d    (4)    %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
        printf("   (5)    %d    (6)    %d    (7)    %d    (8)    %d    (9)    %d\n",arr[5],arr[6],arr[7],arr[8],arr[9]);
    }
}
