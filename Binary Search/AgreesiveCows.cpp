#include <bits/stdc++.h>
using namespace std;

bool helper(int stalls[], int n, int cows, int dis)
{
	int pre = stalls[0];
	int cnt = 1;
	
	for (int i = 1; i < n; ++i)
		if(stalls[i] - pre >= dis)
			++cnt, pre = stalls[i];

	if(cnt >= cows)
		return true;
	return false;
}

void fun(int stalls[], int n, int cows)
{
	sort(stalls, stalls+n);
	int start = 0, end = stalls[n-1];
	int res = 0;
	while(start <= end)
	{
		int mid = start + (end - start)/2;

		if(helper(stalls, n, cows, mid))
		{
			res = mid;
			start = mid + 1;
			// cout << " in if ";
		}
		else
			end = mid - 1;

		// cout << start << " " << mid << " " << end << "\n";
	}
	cout << res << "\n";
}

int main() 
{
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
		int n, cows;
		cin >> n >> cows;
		int stalls[n];
		for(int i=0; i<n; i++)
			cin >> stalls[i];
			
		fun(stalls, n, cows);
	}
	return 0;
}