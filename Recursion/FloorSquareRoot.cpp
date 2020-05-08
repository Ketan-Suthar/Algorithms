// C++ implementation to find the 
// square root of the number N 
// without using sqrt() function 
// source geeksforgeeks.com
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the square 
// root of the number N using BS 
int sqrtSearch(int low, int high, int N) 
{ 

	// If the range is still valid 
	if (low <= high) { 

		// Find the mid-value of the range 
		int mid = (low + high) / 2; 

		// Base Case 
		if ((mid * mid <= N) 
			&& ((mid + 1) * (mid + 1) > N)) { 
			return mid; 
		} 

		// Condition to check if the 
		// left search space is useless 
		else if (mid * mid < N) { 
			return sqrtSearch(mid + 1, high, N); 
		} 
		else { 
			return sqrtSearch(low, mid - 1, N); 
		} 
	} 
	return low; 
} 

// Driver Code 
int main() 
{ 
	int N = 25; 
	cout << sqrtSearch(0, N, N) 
		<< endl; 
	return 0; 
} 
