#include<stdio.h>
#include<cstring>
#include<iostream>
#include<math.h>

using namespace std;

int countNumbersWith4(int n,int base)
{

   if (n < base)
      return 0;

   // number of digits -1
   int k = log10(n);
   // SOlution matrix
   int *solution = new int[k+1];
   // Solution
   solution[0] = 0, solution[1] = 1;

   for (int i=2; i<=k; i++)
      solution[i] = solution[i-1]*9 + ceil(pow((double)10,i-1));

   int p = ceil(pow((double)10, k));
   // Most significant bit
   int msd = n/p;

   if (msd == base){
      //cout<<solution[k]<<"     "<<n%p<<endl;
      return (msd)*solution[k] + (n%p) + 1;

   }

   if (msd > base)
      return (msd-1)*solution[k] + p + countNumbersWith4(n%p,base);

   return (msd)*solution[k] + countNumbersWith4(n%p,base);
}

int main()
{
   int n =44;
   int base = 2;
   cout<< countNumbersWith4(n,1)<<" "<<countNumbersWith4(n,2)<<" " <<countNumbersWith4(n,3)<<" ";
   cout<<countNumbersWith4(n,4)<<" "<<countNumbersWith4(n,5)<<" " <<countNumbersWith4(n,5)<<" " <<countNumbersWith4(n,6)<<" ";
   cout<<countNumbersWith4(n,7)<<" " <<countNumbersWith4(n,7)<<" "<<countNumbersWith4(n,8)<<" "<<countNumbersWith4(n,9)<<endl;
   return 0;
}

