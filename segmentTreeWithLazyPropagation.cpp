#include<bits/stdc++.h>
using namespace std;
#define MX 1000
int arr[MX];
struct info
{
int sum=0,propagation=0;
}tree[3*MX];

int init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        return tree[node].sum;
    }
    int left = node*2+1;
    int right = node*2+2;
    int mid = (b+e)/2;
    tree[node].sum = init(left,b,mid)+ init(right,mid+1,e);

    return tree[node].sum;
}
void update(int node ,int b,int e,int i,int j,int x)
{
    if(i>e||j<b) return;
    if(b>=i&&e<=j)
    {
        tree[node].propagation += x;
        tree[node].sum += (x*(e-b+1));
        return;
    }
    int left = node*2 +1;
    int right = node*2 +2;
    int mid = (b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].propagation;
}
int quary(int node , int b, int e,int i,int j,int carry=0)
{
    if(i>e||j<b) return 0;
    if(b>=i&&e<=j)
    {
        return tree[node].sum + (e-b+1)*carry;
    }
    int left = node*2 + 1;
    int right = node *2 + 2;
    int mid = (b+e)/2;
    int p1 = quary(left,b,mid,i,j,carry+tree[node].propagation);
    int p2 = quary(right,mid+1,e,i,j,carry+tree[node].propagation);

    return p1+p2;
}
void read()
{
    freopen("input.txt","r",stdin);
}

int main()
{
    read();
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(0,0,n-1);
    cout<<"Before Sum = "<<quary(0,0,n-1,1,3)<<endl;
    update(0,0,n-1,1,5,20);
    update(0,0,n-1,1,3,-5);
    cout<<"After Sum = "<<quary(0,0,n-1,1,3)<<endl;

    return 0;
}
