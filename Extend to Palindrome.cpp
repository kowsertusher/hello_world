#include<bits/stdc++.h>
using namespace std;

void read()
{
    freopen("Input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    ///read();
    string s;
    while(cin>>s)
    {
        int len = s.length();
        int temp =0;
        bool flag = true;
        int temp_len = len;
        int length = len-1;
        for(int j=0;j<temp_len/2;j++)
            {
                if(s[j]!=s[length])
                {
                    flag = false;
                    break;
                }
                length--;
            }
        if(flag) cout<<s<<endl;
        else
        {
        for(int i=0;i<len;i++)
        {
            temp_len = len-i;
            length = len-1;
            flag = true;

            for(int j=i;j<(i+temp_len/2);j++)
            {
                if(s[j]!=s[length])
                {
                    flag = false;
                    break;
                }
                length--;
            }
            if(flag)
            {
                    temp =i;
                    break;
            }
        }
        //cout<<temp<<endl;
        for(int j=temp-1;j>=0;j--)
            s+=s[j];
        cout<<s<<endl;
        }
    }

    return 0;
}
