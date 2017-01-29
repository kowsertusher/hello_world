#include<bits/stdc++.h>
using namespace std;
#define row 4
#define col 5

int kande(int arr[],int n)
{
    int sum =0,maxSum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+= arr[i];
        if(sum<0)
        {
            sum =0;
        }
        else if(sum>maxSum)
        {
            maxSum = sum;
        }
    }
    if(maxSum!=INT_MIN) return maxSum;

    maxSum = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxSum)
            maxSum = arr[i];
    }

    return maxSum;
}

int maxSumIn2D(int r[row][col])
{
    int maxSum = INT_MIN;

    for(int left = 0;left<col;left++)
    {
        int arr[row];
        memset(arr,0,sizeof(arr));
        for(int right =left;right<col;right++)
        {
            for(int i=0;i<row;i++)
                arr[i] += r[i][right];
            int sum = kande(arr,row);
            if(sum>maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}
int main()
{
    int r[row][col] =
    {
        {
            1,2,-1,-4,-20
        },
        {
            -8,-3,4,2,1
        },
        {
            3,8,10,1,3
        },
        {
            -4,-1,1,7,-6
        }
    };
    cout<<maxSumIn2D(r)<<endl;

}

