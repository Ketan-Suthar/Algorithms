// Program to count swaps required to balance string 
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

// Function to calculate swaps required 
long swapCount(char s[], int n) 
{ 
	// Keep track of '[' 
	vector<int> pos; 
	for (int i = 0; i < n; ++i) 
		if (s[i] == '[') 
			pos.push_back(i); 

	int count = 0; // To count number of encountered '[' 
	int p = 0; // To track position of next '[' in pos 
	long sum = 0; // To store result 

	for (int i = 0; i < n; ++i) 
	{ 
		// Increment count and move p to next position 
		if (s[i] == '[') 
		{ 
			++count; 
			++p; 
		} 
		else if (s[i] == ']') 
			--count; 

		// We have encountered an unbalanced part of string 
		if (count < 0) 
		{ 
			// Increment sum by number of swaps required 
			// i.e. position of next '[' - current position 
			sum += pos[p] - i; 
			swap(s[i], s[pos[p]]); 
			++p; 

			// Reset count to 1 
			count = 1; 
		} 
	} 
	return sum; 
} 

// Driver code 
int main() 
{ 
	char s[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	cout << swapCount(s, n) << "\n"; 

	return 0; 
} 
