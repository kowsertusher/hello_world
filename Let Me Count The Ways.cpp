#include<bits/stdc++.h>
using namespace std;

long long count( int S[], int m, int n )
{
    long long i, j, x, y;

    long long table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    //read();
    int s[] = {1,5,10,25,50};
    int m = 5;
    int n;
    while(cin>>n)
    {
        if(count(s,m,n)>1)
        printf("There are %lld ways to produce %d cents change.\n",count(s,m,n),n);
        else printf("There is only %lld way to produce %d cents change.\n",count(s,m,n),n);
    }
}
