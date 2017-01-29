#include<bits/stdc++.h>
#define max 1000000
using namespace std;
int arr[max],tree[3*max];
void printA(int n)
{
    for (int i=0;i<3*n;i++)
        cout<<tree[i]<<" ";
        cout<<endl;
}
int init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return tree[node];
    }
    int left = 2*node+1;
    int right = 2*node +2;
    int mid = (b+e)/2;
    tree[node] = init(left,b,mid) + init(right,mid+1,e);
    return tree[node];
}
int quary(int node , int b,int e,int i,int j)
{
    if(i>e||j<b) return 0;
    if (b>=i&&e<=j) return tree[node];
    int left = 2*node+1;
    int right = 2*node +2;
    int mid = (b+e)/2;
    int p1 = quary(left,b,mid,i,j);
    int p2 = quary(right,mid+1,e,i,j);
    return p1+p2;
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

    tree[node] = tree[left] +tree[right];

}
void read()
{
    freopen("input.txt","r",stdin);
}

int main()
{
    //read();
    int tc;
    scanf("%d",&tc);
    for (int t=1;t<=tc;t++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        init(0,0,n-1);
        printf("Case %d:\n",t);
        for (int i=0;i<q;i++)
        {
            int v;
            scanf("%d",&v);
            if(v==1)
            {
                int j;
                scanf("%d",&j);
                printf("%d\n",quary(0,0,n-1,j,j));
                update(0,0,n-1,j,0);
                arr[j] = 0;
            }
            else if(v==2)
            {
                int r,s;
                scanf("%d %d",&r,&s);
                //printA(n);

                update(0,0,n-1,r,s+arr[r]);
                arr[r] +=s;
                //printA(n);
            }
            else if(v==3)
            {
                int r,s;
                scanf("%d %d",&r,&s);
                printf("%d\n",quary(0,0,n-1,r,s));
            }
        }

    }
    //update(0, 0, n-1, 2, 2);
    //cout << quary(0, 0, n-1, 2, 2) << endl;
    return 0;
}

