#include <bits/stdc++.h>
using namespace std;

void read()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

}
int main(void)
{
	/* code */
	read();
	double mealCost,tip,tex;
	cin>>mealCost>>tip>>tex;
	double result = mealCost+(mealCost*(tip/100))+(mealCost*(tex/100));
	printf("The total meal cost is %.0f dollars.\n",result );

	return 0;
}