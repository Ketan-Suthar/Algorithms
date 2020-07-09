#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define ui unsigned int
#define endl "\n"

int blocks[MAX], arr[MAX+1], blockSize;
ui n,q;

void update(int ind)
{
	int bn = ind / blockSize;
	if(arr[ind] == 0)
		blocks[bn] += 1;
	else
		blocks[bn] -= 1;
	arr[ind] = (!arr[ind]); 
}

void preprocessing()
{
	blockSize = (int)sqrt(n);
	int bi = -1;
	for (int i = 0; i < n; ++i)
	{
		if(i%blockSize == 0)
			++bi;
		if(arr[i])
			blocks[bi] += 1;
	}
}

int query(int left, int right)
{
	int res = 0;
	while(left < right && left%blockSize != 0)
	{
		res += arr[left];
		++left;
	}
	while(left+blockSize <= right)
	{
		res += blocks[left/blockSize];
		left += blockSize;
	}
	while(left <= right)
	{
		res += arr[left];
		++left;
	}
	return res;
}

void printArray()
{
	cout<<"\narray: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i] << " ";
	}
}

void printBlocks()
{
	cout<<"\nblocks: ";
	for (int i = 0; i < blockSize; ++i)
	{
		cout<<blocks[i] << " ";
	}
}

int main()
{
	// your code goes here
	memset(arr, 0, sizeof arr);
	memset(blocks, 0, sizeof blocks);
	cin>>n>>q;

	preprocessing();
	int ch,a,b;
	while(q--)
	{
		cin>>ch>>a>>b;
		if(ch == 0)
			for (int i = a; i <= b; ++i)
				update(i);
		else
			cout<<query(a,b)<<endl;
	}

	return 0;
}
