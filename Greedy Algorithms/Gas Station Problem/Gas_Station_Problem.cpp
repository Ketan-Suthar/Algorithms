#include <iostream>

using namespace std;

int gasstationsolution(int gas[], int cost[], int n)
{
	int sur=0, diff=0, start=0;
	for(int i=0;i<n;++i)
	{
		sur += gas[i] - cost[i];
		if(sur<0)
		{
			start = i+1;
			diff += sur;
			sur = 0;
		}
	}
	return sur+diff>=0 ? start : -1;
}

int main()
{
	int gas[5] = {1,2,3,4,5};
	int cost[5] = {3,4,5,1,2};

	int result = gasstationsolution(gas,cost,5);
	cout<<result;
	return 0;
}