#include<bits/stdc++.h>
#define ma 100
using namespace std;
int arr[ma],tree[3*ma],cnt;
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
    tree[node] = max( tree[left] , tree[right]);
}
int quary(int node , int b,int e,int i,int j)
{
    if(i>e||j<b) return INT_MIN;
    if (b>=i&&e<=j) return tree[node];
    int left = 2*node+1;
    int right = 2*node +2;
    int mid = (b+e)/2;
    int p1 = quary(left,b,mid,i,j);
    int p2 = quary(right,mid+1,e,i,j);
    return max(p1,p2);
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

    tree[node] = max(tree[left] ,tree[right]);

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
    //array.fill(tree,INT_MAX);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    init(0,0,n-1);
    cout<<quary(0,0,n-1,0,1)<<endl;
    //for (int i=0;i<3*n;i++) cout<<tree[i]<<" ";
    //cout<<cnt<<endl;
    //update(0, 0, n-1, 1, 5);
    cout<<quary(0,0,n-1,2,4)<<endl;
    //update(0, 0, n-1, 2, 2);
    cout << quary(0, 0, n-1, 4, 4) << endl;
    return 0;
}


