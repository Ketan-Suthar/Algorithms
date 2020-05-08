#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = -1;
        for(int i=2; i*i <= n; i++)
        {
            while(n%i == 0)
                n /= i;
            ans = i;
        }
        if(n > 1)
            ans = n;
        cout << ans << "\n";
    }
	return 0;
}