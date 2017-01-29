#include<bits/stdc++.h>
using namespace std;

const int N=3;

bool wPreferM1OverM(int prefer[2*N][N],int w, int m1 , int m)
{
    for(int i=0;i<N;i++)
    {
        if(prefer[w][i]==m1) return true;
        if(prefer[w][i]==m) return false;
    }
}
void stableMarriage(int prefer[2*N][N])
{
    int wPartner[N];
    bool mFree[N];
    memset(wPartner,-1,sizeof(wPartner));
    memset(mFree,false,sizeof(mFree));
    int freeCount = N;

    while(freeCount>0)
    {
        int m;
        for( m =0;m<N;m++)
            if(!mFree[m]) break;

        for(int i=0;i<N&&mFree[m]==false;i++)
        {
            int w = prefer[m][i];
            if(wPartner[w-N]==-1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }
            else
            {
                int m1 = wPartner[w-N];
                if(!wPreferM1OverM(prefer,w,m1,m))
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }

    cout<<"MEM Marriage To Woman"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<wPartner[i] << "               "<<i+N<<endl;
    }
}
int main()
{
   /* int prefer[2*N][N] =
    {
        {
            7,5,6,4
        },
        {
            5,4,6,7
        },
        {
            4,5,6,7
        },
        {
            4,5,6,7
        },
        {
            0,1,2,3
        },
        {
            0,1,2,3
        },
        {
            0,1,2,3
        },
        {
            0,1,2,3
        }
    };
    */
    int prefer[2*N][N] = {{3, 4 ,5},
                        {5, 4, 3},
                        {4, 3, 5},
                        {1 ,0 ,2},
                        {0, 1, 3},
                        {2, 1, 0}};
    stableMarriage(prefer);

    return 0;
}
