#include <bits/stdc++.h> 
using namespace std; 

// Structure to represent a query range 
struct Query 
{ 
    int L, R, i; 
};

int blockSize;
int arr[200001];
int fre[1000001];
int cnt = 0;
int ans[200001];

bool compare(Query x, Query y)
{
	if((x.L/blockSize) != (y.R/blockSize))
		return x.L/blockSize < y.R/blockSize;
	return x.R < y.R; 
}

void add(int pos)
{
	fre[arr[pos]]++;
	if(fre[arr[pos]] == 1)
		++cnt;
}

void remove(int pos)
{
	fre[arr[pos]]--;
	if(fre[arr[pos]] == 0)
		--cnt;
}

void printUnique(int arr[], int n, Query que[], int q)
{
	blockSize = (int)sqrt(n);

	sort(que, que+q, compare);

	int ml=0, mr=-1;
	for (int i = 0; i < q; ++i)
	{
		int l = que[i].L;
		int r = que[i].R;

		while(ml > l)
			--ml, add(ml);
		while(mr < r)
			++mr, add(mr);
		while(ml < l)
			remove(ml), ++ml;
		while(mr > r)
			remove(mr), --mr;
		ans[que[i].i] = cnt;
	}
	for (int i = 0; i < q; ++i)
		cout << ans[i] <<"\n";
	
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n, q;
	cin>>n;
	
	for (int i = 0; i < n; ++i)
		cin>>arr[i];

	cin>>q;
	Query que[q];
	for (int i = 0; i < q; ++i)
	{
		cin >> que[i].L >> que[i].R;
		que[i].i = i;
		que[i].L--;
		que[i].R--;
	}

	printUnique(arr, n, que, q);
	return 0;
}