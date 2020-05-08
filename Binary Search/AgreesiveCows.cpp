#include <bits/stdc++.h>
using namespace std;

bool helper(int stalls[], int n, int cows, int dis)
{
	int start = 0, end = 1;
	--cows;
	while(1)
	{
		while(end < n && (stalls[end]-stalls[start] < dis))
			end++;
		if(end == n)
			break;
		else
		{
			start = end;
			end = start + 1;
			cows--;
		}
		if(cows == 0)
			break;
	}
	if(cows == 0)
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
		{
			// cout << " in el ";
			end = mid - 1;
		}
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