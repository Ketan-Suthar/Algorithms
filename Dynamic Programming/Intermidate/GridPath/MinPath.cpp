#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MAX 100

int arr[MAX][MAX], temp[MAX][MAX];

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;

	
	for (int i = 0; i < n; i++)
		for(int j=0; j < m; j++)
			cin>>arr[i][j];
	for (int i = 0; i <= n; i++)
		temp[i][m] = INF;
	for (int i = 0; i <= m; i++)
		temp[n][i] = INF;

	temp[n-1][m] = temp[n][m-1] = 0;

	for (int i = n-1; i >= 0; --i)
		for(int j=m-1; j >= 0; --j)
		{
			temp[i][j] = arr[i][j] += min(temp[i+1][j], temp[i][j+1]);
		}

	for (int i = 0; i < n; i++)
	{
		for(int j=0; j < m; j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}	
	return 0;
}