#include <bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arrival[n], departure[n];
	    for(int i=0;i<n;i++)
	        cin>>arrival[i];
	    for(int i=0;i<n;i++)
	        cin>>departure[i];
	    sort(arrival, arrival+n);
	    sort(departure, departure+n);
	    
	    int plateforms = 1, arrived = 1;
	    int i=1, j=0;
	    while(i < n && j < n)
	    {
	        if(arrival[i] <= departure[j])
	        {
	            ++arrived;
	            ++i;
	        }
	       else
	       {
	            --arrived;
	            ++j;
	       }
	       if(arrived > plateforms)
	            plateforms = arrived;
	    }
	    cout<<plateforms<<'\n';
	}
	return 0;
}