#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000000
void Solution()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int floorOfNumber(int arr[], int n, int target)
{
    if(n == 0)
        return -1;
    if(arr[0] > target)
        return -1;
    if(target > arr[n-1])
        return n-1;
    int start = 0, end = n-1, pos = end;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target)
            return mid;
        if(target > arr[mid])
            pos = end, start = mid + 1;
        else
            pos = mid - 1, end = mid -1;
    }
    return pos;
}

int main()
{
    //Solution();
    int t;
    cin >> t;
    while(t--)
    {
        int n, target;
        cin >> n;
        cin >> target;
        int  arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        cout << floorOfNumber(arr, n , target) << "\n";
    }
    return 0;
}