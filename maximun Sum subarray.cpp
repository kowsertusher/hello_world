#include<bits/stdc++.h>
using namespace std;

int arr[100010];

int main()
{

    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++)
    {
        int n;
        cin>>n;
        for (int i=0;i<n;i++) cin>>arr[i];
        long long maxsub=INT_MIN,maxsub1=INT_MIN,temp=INT_MIN;
        for(int i=0;i<n;i++)
        {
            temp = max(temp,0ll);
            temp+= arr[i];
            maxsub = max(maxsub,temp);
        }
        for (int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                if(maxsub1<0) maxsub1 = arr[i];
                else maxsub1 +=arr[i];
            }
            else
            {
                maxsub1 = max(maxsub1 , (long long )arr[i]);
            }
        }
        cout<<maxsub <<' ' <<maxsub1<<endl;
    }
}
