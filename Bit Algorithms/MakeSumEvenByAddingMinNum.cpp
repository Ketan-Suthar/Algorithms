#include <iostream>
using namespace std;
// Function to find out minimum number
int minNum(int arr[], int n)
{
	// Count odd number of terms in array
	int odd = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] % 2)
			odd += 1;
	return (odd % 2)? 1 : 2;
}
// Driver code
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minNum(arr, n);
	return 0;
}