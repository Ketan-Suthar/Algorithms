#include <bits/stdc++.h>
using namespace std;

static int table[11][51];

int superEggDrop(int eggs, int floors)
{
    if(table[eggs][floors] != -1)
        return table[eggs][floors];
    if(floors == 0 || floors == 1)
        return floors;
    if(eggs <= 1)
        return floors;
    int min = INT_MAX;
    for(int k=1; k <= floors; k++)
    {
        int low, high;
        if(table[eggs-1][k-1] != -1)
            low = table[eggs-1][k-1];
        else
            low = table[eggs-1][k-1] = superEggDrop(eggs-1, k-1);
        if(table[eggs][floors-k] != -1)
            high = table[eggs][floors-k];
        else
            high = table[eggs][floors-k] = superEggDrop(eggs, floors - k);
        int temp = 1 + max(low , high);
        if(temp < min)
            min = temp;
    }
    return table[eggs][floors] = min;
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int eggs, floors;
	    cin >> eggs >> floors;
	    memset(table, -1, sizeof  table);
	    cout << superEggDrop(eggs, floors) << "\n";
	}
	return 0;
}