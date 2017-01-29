#include<bits/stdc++.h>
using namespace std;

void read(){
    freopen("input.txt","r",stdin);
}

int main(){
    read();
    queue<int>q;
    vector<int>v[1000];
    int color[1000];
    int n,d,flag,u,l;
    while(cin>>n){
        if(n==0)
            return 0;

    else
    {
     cin>>d;
     for(int i=0;i<d;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

     }

     memset(color,0,sizeof(color));
     int flag=1;

     for(int j=0;j<n;j++){
             if(color[j]==0){
                color[j]=1;
             }
            u=j;
            l=v[u].size();

            for(unsigned i=0;i<l;i++){

                int a=v[u][i];


                if(color[a]==0)
                    {
                        if(color[u]==1)
                        {
                            color[a]=2;
                        }
                        else
                        {
                            color[a]=1;
                        }

                    }

                    else if(color[a]==color[u]) {
                            flag=0;
                            break;
                    }

            }
            if(flag==0) break;

     }
        if(flag) cout<<"BICOLORABLE"<<endl;
        else cout<<"NOT BICOLORABLE"<<endl;

        for(unsigned i=0;i<n;i++)
            v[i].clear();
        }
    }

     return 0;



}


