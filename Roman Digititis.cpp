#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int c1=0,c2=0,c3=0,c4=0,c5=0;
        for(int i=1;i<=n;i++)
        {
            int temp = i;
            if(temp>=90)
            {
                c5++;
                c3++;
                temp = temp-90;
            }
            c4+= temp/50;
            temp = temp%50;
            if(temp>=40&&temp<50)
            {
                c4++;
                c3++;
                temp-=40;
            }
            c3 += temp/10;
            temp = temp%10;
            if(temp==9)
            {
                c3++;
                c1++;
                temp-=9;
            }
            c2 +=temp/5;
            temp = temp%5;
            if(temp==4)
            {
                c2++;
                c1++;
                temp-=4;
            }
            c1+=temp;

        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,c1,c2,c3,c4,c5);
    }
}
