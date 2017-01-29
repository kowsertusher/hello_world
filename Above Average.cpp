#include<bits/stdc++.h>
using namespace std;

void read()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main()
{
	//read();
	int n;
	cin>>n;
	vector<int> v;
	for(int cc=0;cc<n;cc++)
	{
		int t;
		cin>>t;
		int sum=0;
		int arr[t];
		for(int j=0;j<t;j++)
		{
			cin>>arr[j];
			sum+=arr[j];
		}
		float res = (float) sum/t;
		int count=0;
		for(int i=0;i<t;i++)
		{
			if(arr[i]>res) count++;
		}
		res = ((float)count/t)*100;
		printf("%.3f\%\n",res);
	}
	return 0;
}
