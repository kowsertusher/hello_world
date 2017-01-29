#include<bits/stdc++.h>
using namespace std;
bool pani(string s)
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
    string s,temp;
    while(cin>>s)
    {
        temp = s;
        bool p = pani(temp);
        bool m =true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='B'||s[i]=='C'||s[i]=='D'||s[i]=='F'||s[i]=='G'||s[i]=='K'||
               s[i]=='N'||s[i]=='P'||s[i]=='Q'||s[i]=='R'||s[i]=='4'||s[i]=='6'||s[i]=='7'||s[i]=='9')
               {
                   m=false;
                   //cout<<"a"<<m<<endl;
                   break;

               }
            ///cout<<" b"<<endl;
        }
        if(m)
        {
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='E') s[i] = '3';
                else if(s[i]=='3') s[i] = 'E';
                else if(s[i]=='J') s[i] = 'L';
                else if(s[i]=='L') s[i] = 'J';
                else if(s[i]=='S') s[i] = '2';
                else if(s[i]=='2') s[i] = 'S';
                else if(s[i]=='Z') s[i] = '5';
                else if(s[i]=='5') s[i] = 'Z';

            }
            int j = s.size()-1;

            for(int i=0;i<temp.size();i++)
            {
               if(temp[i]!= s[j])
               {
                   m = false;
                   break;
               }
               j--;
            }
        }
        //cout<<p<<m<<endl;
        if(p&&m) cout<<temp<<" -- is a mirrored palindrome.\n"<<endl;
        else if(p&&!m) cout<<temp<<" -- is a regular palindrome.\n"<<endl;
        else if(!p&&m) cout<<temp<<" -- is a mirrored string.\n"<<endl;
        else if(!p&&!m) cout<<temp<<" -- is not a palindrome.\n"<<endl;

    }

}
