#include<bits/stdc++.h>
using namespace std;

int cnt=0;

int minOperatin(int x,int y)
{
    set<int> visited;
    queue<pair<int , int > >q;
    q.push(make_pair(x,0));
    while(!q.empty())
    {
        if(q.front().first==y)
            return q.front().second;
        visited.insert(q.front().first);
        if(q.front().first*2==y||q.front().first-1==y)
            return q.front().second+1;
        //q.pop();
        if(visited.find(q.front().first*2)==visited.end())
        {
            q.push(make_pair(q.front().first*2,q.front().second+1));
        }
        if((q.front().first-1>0)&&visited.find(q.front().first-1)==visited.end())
            q.push(make_pair(q.front().first-1,q.front().second+1));
        q.pop();
    }
}
int main()
{
    cout<<minOperatin(4,5)<<endl;
}
