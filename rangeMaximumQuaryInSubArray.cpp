#include<bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n , int k)
{
    vector <int> maxQ;
    deque<int> qi(k);

    for(int i=0;i<n;i++)
    {
        while(!qi.empty()&&arr[i]>=arr[qi.back()])
            qi.pop_back();
        qi.push_back(i);

        while(!qi.empty()&&qi.front()<=i-k)
            qi.pop_front();
        if(i>=k-1) maxQ.push_back(arr[qi.front()]);
    }
    cout <<"MAX Q"<<endl;
    for(int i=0;i<maxQ.size();i++)
        cout<<maxQ[i]<<" ";
}

int main()
{
    int arr[] = {12,1,78,90,57,89,56};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr,size,k);

    return 0;
}

