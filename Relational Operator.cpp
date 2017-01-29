#include<bits/stdc++.h>
using namespace std;

void read()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

}
int main()
{
	read();
	int n;
	int a,b;
	cin>>n;
	int i=0;

	while(i<n)
	{
		cin>>a>>b;
		if(a>b) cout<<">"<<endl;
		else if(a==b) cout<<"="<<endl;
		else if(a<b) cout<<"<"<<endl; 

		i++;
	}

	return 0;
}