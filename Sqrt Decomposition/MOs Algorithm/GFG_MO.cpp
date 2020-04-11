#include <bits/stdc++.h> 
using namespace std; 
 
// Structure to represent a query range 
struct Query 
{ 
    int L, R; 
};

int blockSize;

bool compare(Query x, Query y)
{
	if((x.L/blockSize) != (y.L/blockSize))
		return (x.L/blockSize) < (y.L/blockSize);

	return x.R < y.R;
}

void printQuerySums(int arr[], int n, Query q[], int m)
{
	blockSize = (int)sqrt(n);

	sort(q, q+m, compare);


	int currL=0, currR=0, currSum=0;

	for (int i = 0; i < m; ++i)
	{
		int left = q[i].L, right = q[i].R;

		// Remove extra elements of previous range. For 
        // example if previous range is [0, 3] and current 
        // range is [2, 5], then a[0] and a[1] are subtracted 
        while (currL < left) 
        { 
            currSum -= arr[currL]; 
            currL++; 
        }
        // Add Elements of current Range 
        while (currL > left) 
        { 
            currSum += arr[currL-1]; 
            currL--; 
        } 
        while (currR <= right) 
        { 
            currSum += arr[currR]; 
            currR++; 
        } 
  
        // Remove elements of previous range.  For example 
        // when previous range is [0, 10] and current range 
        // is [3, 8], then a[9] and a[10] are subtracted 
        while (currR > right+1) 
        { 
            currSum -= arr[currR-1]; 
            currR--; 
        } 
  
        // Print sum of current range 
        cout << "Sum of [" << left << ", " << right << "] is "  << currSum << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n, l, r;
	cin >> n;
	int input[n];
	for (int i = 0; i < n; ++i)
		cin >> input[i];

	Query q[] = {{0, 9}, {3, 7}}; 
    int m = sizeof(q)/sizeof(q[0]); 
    printQuerySums(input, n, q, m);

	return 0;
}