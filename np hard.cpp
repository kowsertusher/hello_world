#include<bits/stdc++.h>
using namespace std;
queue<int>q;
vector<int>v[100010];
int color[100010];
int n,d,u,l;
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
bool bfs(int s)
{
    bool flag = true;
     color[s]=0;
     q.push(s);
     while(!q.empty())
    {
            u=q.front();
            q.pop();
            l=v[u].size();

            for(unsigned i=0;i<l;i++)
            {
                int a=v[u][i];
                if(color[a]==-1)
                {
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

                else if(color[a]==color[u])
                {
                    flag= false;
                    break;
                }

            }
            if(flag==false) break;

     }
     return flag ;
}

int main()
{
    //read();
    bool flag = true;
    memset(color,-1,sizeof(color));
    cin>>n;
    cin>>d;
    for(int i=0;i<d;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        flag = bfs(i);
        if(!flag) break;
    }
    if(!flag) cout<<-1<<endl;
    else
    {
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i=0;i<=n;i++)
        {
            if(color[i]==0) cnt0++;
            else if (color[i]==1)  cnt1++;

        }
        cout<<cnt1<<endl;
        for(int i=0;i<=n;i++)
        {
           if(color[i]==1) cout<<i<<" ";
        }
        cout<<endl;
        cout<<cnt0<<endl;
        for(int i=0;i<=n;i++)
        {
           if(color[i]==0) cout<<i<<" ";
        }
        cout<<endl;

    }


}

