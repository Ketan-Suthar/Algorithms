// C++ program to find maximum number of thieves 
// caught 
#include <iostream> 
#include <vector> 
#include <cmath> 

using namespace std; 

// Returns maximum number of thieves that can 
// be caught. 
int policeThief(char arr[], int n, int k) 
{ 
	int res = 0; 
	vector<int> thi; 
	vector<int> pol; 

	// store indices in the vector 
	for (int i = 0; i < n; i++) { 
		if (arr[i] == 'P') 
			pol.push_back(i); 
		else if (arr[i] == 'T') 
			thi.push_back(i); 
	} 

	// track lowest current indices of 
	// thief: thi[l], police: pol[r] 
	int l = 0, r = 0; 
	while (l < thi.size() && r < pol.size())
	{
		// can be caught 
		if (abs(thi[l] - pol[r]) <= k)
		{ 
			res++; 
			l++; 
			r++; 
		}
		// increment the minimum index 
		else if (thi[l] < pol[r]) 
			l++; 
		else
			r++; 
	} 

	return res; 
} 

// Driver program 
int main() 
{ 
	int k, n; 

	char arr1[100]; 
	cin>>n;
	cout<<"\n enter values: ";
	for(int i=0; i<n; ++i)
		cin >> arr1[i];
	cout << "\nenter K: ";
	cin >> k;
	cout << "\nMaximum thieves caught: "
		<< policeThief(arr1, n, k) << endl; 

	return 0; 
} 
