#include<bits/stdc++.h>
#define max 100
using namespace std;
int arr[max],tree[3*max];
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
    read();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    init(0,0,n-1);
    cout<<quary(0,0,n-1,1,3)<<endl;
    update(0, 0, n-1, 1, 10);
    cout<<quary(0,0,n-1,1,3)<<endl;
    //update(0, 0, n-1, 2, 2);
    //cout << quary(0, 0, n-1, 2, 2) << endl;
    return 0;
}
