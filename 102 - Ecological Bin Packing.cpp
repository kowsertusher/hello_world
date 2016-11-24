#include<bits/stdc++.h>
using namespace std;

void read(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int a[9];
int chane(int d,int b,int c){
    int res=0;
    for(int i=0;i<9;i++) {
        if(i!=d&&i!=b&&i!=c)
        res+=a[i];
        }
        return res;
}


int main(){
    char clower[6][4]={ "BCG",
                        "BGC",
                        "CBG",
                        "CGB",
                        "GBC",
                        "GCB"};


    int count[6];
    while(scanf("%d",&a[0])!=EOF){
        for(int i=1;i<9;i++)
            cin>>a[i];

        count[0]=chane(0,5,7);
        count[1]=chane(0,4,8);
        count[2]=chane(2,3,7);
        count[3]=chane(2,4,6);
        count[4]=chane(1,3,8);
        count[5]=chane(1,5,6);
        int maxmin=INT_MAX;
        int pos=0;
        for(int i=0;i<6;i++){
            if(maxmin>count[i]){
                maxmin=count[i];
                pos=i;
            }
        }
        cout<<clower[pos]<<" "<<maxmin<<endl;

    }

  return 0;
}



