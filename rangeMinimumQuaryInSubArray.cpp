#include<bits/stdc++.h>
using namespace std;

int printKMin(int arr[],int n,int k)
{
    vector<int> minQ;
    deque<int>qi(k);
    for(int i=0;i<n;i++)
    {
        while(!qi.empty()&&arr[qi.front()]>=arr[i])
        {
            qi.pop_front();
        }
        qi.push_front(i);
        while(!qi.empty()&&qi.back()<=i-k)
            qi.pop_back();
        if(i>=k-1) minQ.push_back(arr[qi.back()]);
    }

    cout<<"MINQ"<<endl;
    for(int i=0;i<minQ.size();i++)
        cout<<minQ[i]<<" ";
}

int main()
{
    int arr[] = {10,2,5,9,6,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMin(arr,size,k);

    return 0;
}
