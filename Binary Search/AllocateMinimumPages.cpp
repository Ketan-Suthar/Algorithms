#include <bits/stdc++.h>
using namespace std;

#define li long int

bool isValid(li arr[], li n, li k, li maximum)
{
    li sum = 0, students = 1, i=0;
    for(; i < n; i++)
    {
        sum += arr[i];
        if(sum > maximum)
        {
            ++students;
            sum = arr[i];
        }
        if(students > k)
            return 0;
    }
    return 1;
}

li fun(li arr[], li n, li k, li minimum, li maximum, li sum)
{
    if(n < k)
        return -1;
    li start = maximum, end = sum;
    li result = -1;
    while(start <= end)
    {
        li mid = start + (end - start) / 2;
        if(isValid(arr, n , k, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
        //cout << start << " " << mid << " " << end << " fun ";
    }
    return result;
}
int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    li n, k, minimum = INT_MAX, maximum = INT_MIN, sum = 0;
	    cin >> n;
	    li arr[n];
	    for(li i=0; i<n; i++)
	    {
	        cin >> arr[i];
	        sum += arr[i];
	        if(arr[i] > maximum)
	            maximum = arr[i];
	       else
	            minimum = arr[i];
	    }
	   cin >> k;
	   cout << fun(arr, n, k, minimum, maximum, sum) << "\n";
	}
	return 0;
}