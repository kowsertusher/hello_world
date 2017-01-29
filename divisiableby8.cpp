#include<bits/stdc++.h>
using namespace std;

int ar[105], len;
int dp[105][8][2];
string r;
int le=0;
int F(int pos, int rem, int taken, string s) {
 if(pos == len) {
 if(rem == 0 && taken > 0){
 r = s;
 if(r.size()>le)
 le = r.size();
 return 1;
 }
 else return 0;
 }

 if(dp[pos][rem][taken] != -1) {
 return dp[pos][rem][taken];
 }

 int res = F(pos + 1, rem, taken, s);
 res = res | F(pos + 1, (rem * 10 + ar[pos]) % 8, 1, s + (char)(ar[pos] + '0'));
 dp[pos][rem][taken] = res;
 return res;
}

int main() {
 char str[105];
 scanf("%s", str);
 len = strlen(str);
 for(int i = 0; i < len; i++) {
 ar[i] = str[i] - 48;
 }
 memset(dp, -1, sizeof(dp));
 int res = F(0, 0, 0, "");
 if(res > 0){
 puts("Yes");
 cout << r <<le<< endl;
 }
 else puts("No");
 return 0;
}
