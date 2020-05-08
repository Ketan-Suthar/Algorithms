// C++ program to prints first k pairs with least sum from two 
// arrays. 
#include<bits/stdc++.h> 

using namespace std;

int maxLevel(int arr[], int n)
{
	if(n == 0)
		return 0;

	sort(arr, arr+n);

	int preWidth = arr[0], int preCount = 1;
	int answer = 1;

	int currWidth, currCount;

	for (int i = 1; i < n; ++i)
	{
		++currCount;
		currWidth += arr[i];

		if(currCount > preCount && currWidth > preWidth)
		{
			preCount = currCount;
			preWidth = currWidth;
			currCount = 0;
			preCount = 0;

			++answer;
		}
	}
	return answer;
}

int main() 
{ 
    int boxes[] = {10, 20, 30, 50, 60, 70}; 
    int n = sizeof(boxes)/sizeof(boxes[0]); 
    cout << maxLevel(boxes, n) << endl; 
    return 0; 
} 