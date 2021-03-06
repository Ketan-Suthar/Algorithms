#include<bits/stdc++.h> 
using namespace std;

#define MAX 10000
#define MAXSQRT 100

int blockSize;
int blocks[MAX];

void update(int input[], int index, int val) 
{ 
    int blockNumber = index / blockSize; 
    blocks[blockNumber] += val - input[index]; 
    input[index] = val;
}

int query(int arr[], int left, int right)
{
	int sum = 0; 
    while (left < right and left % blockSize != 0 and left != 0) 
    {
        // traversing first block in range 
        sum += arr[left];
        left++;
    } 
    while (left + blockSize <= right)
    { 
        // traversing completely overlapped blocks in range 
        sum += blocks[left/blockSize]; 
        left += blockSize; 
    } 
    while (left <= right) 
    { 
        // traversing last block in range 
        sum += arr[left]; 
        left++; 
    } 
    return sum; 
}

void preprocess(int input[], int n)
{
	int blockInd = -1;

	blockSize = sqrt(n);

	for (int i = 0; i < n; ++i)
	{
		if(i%blockSize == 0)
			++blockInd;
		blocks[blockInd] += input[i];
	}
	for (int i = 0; i <= blockSize; ++i)
	{
		cout << blocks[i] << " ";
	}
}

int main(int argc, char const *argv[])
{
	int n, l, r;
	cin >> n;
	int input[n];
	for (int i = 0; i < n; ++i)
		cin >> input[i];

	preprocess(input, n);

	bool c=1;
	while(c)
	{
		bool up =0;
		cout <<"\n want to update (0/1)? ";
		cin >> up;
		if(up)
		{
			int ind, val;
			cout << "\nenter inded and value: ";
			cin >> ind >> val;
			update(input, ind, val);
		}
		cout << "\n enter l and r: ";
		cin>>l >> r;
		cout << "\nsum: " << query(input, l,r);
		cout << "\ncont?: ";
		cin >> c;
	}

	return 0;
}