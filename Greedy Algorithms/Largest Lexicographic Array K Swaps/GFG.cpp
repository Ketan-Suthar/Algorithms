#include<bits/stdc++.h>

using namespace std;

void KSwapMaximum(int arr[], int n, int k)
{
	int maxInd=0;
	for (int i = 0; i < n-1 && k > 0; ++i)
	{
		maxInd = i;
		for(int j=i+1; j<n; ++j)
		{
			if(j-i >= k)
				break;
			if(arr[j] > arr[maxInd])
				maxInd = j;
		}
		for(int j=maxInd; j > i; --j)
			arr[j] ^= arr[j-1] ^= arr[j] ^= arr[j-1];

		k -= maxInd - i;
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = { 1,2,3,4,5,1,1,1,1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 7; 

    KSwapMaximum(arr, n, k); 
  
    // Print the final Array
    cout << "\nanswer is : "; 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
	return 0;
}