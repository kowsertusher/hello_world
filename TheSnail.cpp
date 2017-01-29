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
    double h,u,d,f;
    while(cin>>h>>u>>d>>f)
    {
        if(h==0) break;
        double hi=0,pi = (u*f)/100;
        bool flag = true;
        hi+=u;
        //cout<<hi<<' ';
        if(hi>h)
            {
                cout<<"success on day "<<1<<endl;
                flag = false;
            }
        hi-=d;
        //cout<<hi<<endl;
        if(hi<0&&flag)
            {
                cout<<"failure on day "<<1<<endl;
                flag = false;
            }
        if(flag)
        {
            for(int i=2;;i++)
        {
            //cout<<i<<' '<<hi<<' ';
            u -= pi;
            if(u>0)
            hi+=u;
            if(hi>h)
            {
                cout<<"success on day "<<i<<endl;
                break;
            }
            //cout <<u<<' '<<hi<<' ';
            hi -= d;
            //cout<<hi<<endl;
            if(hi<0)
            {
                cout<<"failure on day "<<i<<endl;
                break;
            }
        }
        }
    }
}
