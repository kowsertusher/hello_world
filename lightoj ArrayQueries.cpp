#include<bits/stdc++.h>
#define max 1000000
using namespace std;
int arr[max],tree[3*max],cnt;
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return ;
    }
    int left = 2*node+1;
    int right = 2*node +2;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = min( tree[left] , tree[right]);
}
int quary(int node , int b,int e,int i,int j)
{
    if(i>e||j<b) return INT_MAX;
    if (b>=i&&e<=j) return tree[node];
    int left = 2*node+1;
    int right = 2*node +2;
    int mid = (b+e)/2;
    int p1 = quary(left,b,mid,i,j);
    int p2 = quary(right,mid+1,e,i,j);
    return min(p1,p2);
}
void update(int node , int b,int e,int i,int newValue)
{
    if(i>e||i<b) return;
    if(b>=i&&e<=i)
    {
        tree[node] = newValue;
        return;
    }
    int left = 2*node +1;
    int right = 2*node +2;
    int mid = (b+e)/2;
    update(left,b,mid,i,newValue);
    update(right,mid+1,e,i,newValue);

    tree[node] = min(tree[left] ,tree[right]);

}
void read()
{
    freopen("input.txt","r",stdin);
}

int main()
{
    //read();
    int tc;
    cin>>tc;

    for (int t =1;t<=tc;t++)
    {
        int n,q;
        //cin>>n>>q;
        //cout<<n<<q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        init(0,0,n-1);
        printf("Case %d:\n",t);
        for (int i=0;i<q;i++)
        {
            int s,e;
            //cin>>s>>e;
            scanf("%d %d",&s,&e);
            printf("%d\n",quary(0,0,n-1,--s,--e));
        }

    }


    return 0;
}


