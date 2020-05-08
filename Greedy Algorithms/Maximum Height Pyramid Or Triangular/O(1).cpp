// CPP program to find the maximum height 
// of Pyramidal Arrangement of array values 
#include <bits/stdc++.h> 
using namespace std; 

int MaximumHeight(int a[], int n) 
{ 
	return floor((-1+sqrt(1+(8*n)))/2); 
} 

int main() 
{ 
	int arr[] = { 40, 100, 20, 30 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << MaximumHeight(arr, n); 
	return 0; 
} 
