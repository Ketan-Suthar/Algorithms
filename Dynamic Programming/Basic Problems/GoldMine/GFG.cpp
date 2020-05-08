// C++ program to solve Gold Mine problem 
#include<bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 

// Returns maximum amount of gold that can be collected 
// when journey started from first column and moves 
// allowed are right, right-up and right-down 
int getMaxGold(int gold[][MAX], int n, int m) 
{ 
	// Create a table for storing intermediate results 
	// and initialize all cells to 0. The first row of 
	// goldMineTable gives the maximum gold that the miner 
	// can collect when starts that row 
	int goldTable[n][m]; 
	memset(goldTable, 0, sizeof(goldTable)); 
    int res = -1;
	for (int col=m-1; col>=0; col--) 
	{ 
		for (int row=0; row<n; row++) 
		{ 
			// Gold collected on going to the cell on the right(->) 
			int right = (col==m-1)? 0: goldTable[row][col+1]; 

			// Gold collected on going to the cell to right up (/) 
			int right_up = (row==0 || col==m-1)? 0: 
							goldTable[row-1][col+1]; 

			// Gold collected on going to the cell to right down (\) 
			int right_down = (row==n-1 || col==m-1)? 0: 
							goldTable[row+1][col+1]; 

			// Max gold collected from taking either of the 
			// above 3 paths 
			goldTable[row][col] = gold[row][col] + 
							max(right, max(right_up, right_down)); 
	        if(goldTable[row][col] > res)
	            res = goldTable[row][col];
		} 
	} 
 
	return res; 
} 

// Driver Code 
int main() 
{ 
	int t;
	cin >> t;
	while(t--)
	{
	    int m,n;
	    cin >> n >> m;
	    int arr[MAX][MAX];
	    
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < m; j++)
	            cin >> arr[i][j];
	    
	    cout << getMaxGold(arr, n, m) << "\n";
	}
	return 0; 
} 
