#include<bits/stdc++.h>
using namespace std;

void read(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main(){
    //read();
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

     memset(color,-1,sizeof(color));
     int flag=1;
     color[0]=0;
     q.push(0);
     while(!q.empty()){

            u=q.front();
            q.pop();
            l=v[u].size();

            for(unsigned i=0;i<l;i++){

                int a=v[u][i];


                if(color[a]==-1)
                    {
                        ///cout<<a<<" ";
                        if(color[u]==0)
                        {
                            color[a]=1;
                        }
                        else
                        {
                            color[a]=0;
                        }
                        q.push(a);
                    }

                    else if(color[a]==color[u]) {
                            flag=0;
                            break;
                    }

            }
            if(flag==0) break;

     }
        if(flag) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;

        for(unsigned i=0;i<1000;i++)
            v[i].clear();
            q=queue<int>();
        }
    }

     return 0;



}

