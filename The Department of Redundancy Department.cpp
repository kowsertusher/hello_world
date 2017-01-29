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
    unordered_map<int , int> m;
    set<int> s;
    vector <int > l;
    int a;
    while(cin>>a)
    {
        if(!s.count(a)) l.push_back(a);
        m[a]++;
        s.insert(a);
    }
    //reverse(m.begin(),m.end());
    for(int i=0;i<l.size();i++)
        cout<<l[i]<<" "<<m[l[i]]<<endl;

}
