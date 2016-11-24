#include<bits/stdc++.h>
using namespace std;

int partition(int arr[] , int low , int high)
{
    int povit = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=povit)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);

    return i+1;
}

void printArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void quickSort(int arr[], int low , int high)
{
    if(low>=high) return ;

    int povitPossition = partition(arr,low,high);
    printArray(arr,7);
    quickSort(arr,low,povitPossition-1);
    quickSort(arr,povitPossition+1,high);
}

int main()
{
    int arr[] = {100,80,40,90,30,70,50};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);

    cout<<"Sorted Array"<<endl;
    printArray(arr,size);
}
