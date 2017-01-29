#include<bits/stdc++.h>
using namespace std;

bool pani(deque<int> s)
{
    bool flag = true;
    int len = s.size();
    int j=len-1;
    for(int i=0;i<(len/2);i++)
    {
        if(s[i]!=s[j])
        {
            flag = false;
            break;
        }
        j--;
    }
    return flag;
}
void read()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
    //read();
    deque<int> d1,d2,d3;
    int n;
    scanf("%d ",&n);

    for(int i=0;i<n;i++)
    {
        string s;
        int j=0;
        cin>>s;
        for( j=0;j<s.size();j++)
        {
            d1.push_back((s[j]-48));
        }
        for( j=0; ; j++)
        {
            d2 = d1;
            reverse(d2.begin(),d2.end());
            int rem =0;
            for(int k = d1.size()-1; k>=0;k--)
            {
                int sum = d1[k]+d2[k] +rem;
                rem = sum/10;
                if(sum>= 10) sum = sum -10;
                d3.push_front(sum);
                ///cout<<d1[k]<<" "<<d2[k]<< ' ' <<rem<<endl;
            }
            if(rem>0) d3.push_front(rem);
            d1 = d3;
            d3.clear();
            bool m = pani(d1);
            if(m)
            {
                j++;
                break;

            }
        }
        cout<<j<<" ";
        for(int j=0;j<d1.size();j++)
                cout<<d1[j];
                cout<<endl;
        /*
        for(int j=0;j<d1.size();j++)
            cout<<d1[j];
    cout<<endl;
    for(int j=0;j<d2.size();j++)
            cout<<d2[j];
    cout<<endl;
    */

    d1.clear();
    d2.clear();
    d3.clear();

    }
}
