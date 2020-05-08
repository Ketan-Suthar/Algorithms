#include <iostream>
using namespace std;


long int fun(int values[], int weights[], int n, int cap)
{
    if(n == 0 || cap == 0)
        return 0;
    if(weights[n-1] <= cap)
        return max(values[n-1] + fun(values, weights, n-1, cap - weights[n-1]),
                    fun(values, weights, n-1, cap));
    return fun(values, weights, n-1, cap);
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, capacity;
	    cin >> n >> capacity;
	    int values[n], weights[n];
	    
	    for(int i=0; i<n; i++)
	        cin >> values[i];
	    for(int i=0; i<n; i++)
	        cin >> weights[i];
	    cout << fun(values, weights, n, capacity) << "\n";
	}
	return 0;
}