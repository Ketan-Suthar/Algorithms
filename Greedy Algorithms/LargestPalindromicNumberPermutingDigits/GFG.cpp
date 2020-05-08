#include <bits/stdc++.h> 
using namespace std;

bool isPalindrome(int arr[])
{
	int odds=0;

	for(int i=0; i<9; ++i)
	{
		if(arr[i] != 0 && (arr[i] & 1))
			++odds;
		if(odds > 1)
			return false;
	}
	return true;
}

void largestPalindrome(string s)
{
	int nums[10] = {0};

	for(char x: s)
		nums[x - '0']++;

	if(!isPalindrome(nums))
	{
		cout << "\ncannot form Palindrome";
		return;
	}

	int len = s.size();
	char largest[len];
	int front = 0;

	for(int i=9; i>=0; --i)
	{
		if(nums[i] & 1)
		{
			largest[len/2] = char(i + 48);
			nums[i]--;
		}
		while(nums[i] > 0)
		{
			largest[front] = char(i + 48);
			largest[len - front - 1] = char(i + 48);
			++front;
			nums[i] -= 2;
		}
	}

	cout << "\nlargest Palindrome number is: ";
	for (int i = 0; i < len; ++i)
		cout << largest[i];
}

// Driver Code 
int main() 
{ 
    string s;
    cin >> s; 
    largestPalindrome(s); 
    return 0; 
} 