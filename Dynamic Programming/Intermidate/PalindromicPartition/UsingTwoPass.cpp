#include <bits/stdc++.h>

using namespace std;

bool ispalindrome(string str, int l, int r)
{
    while(l < r){
        if(str[l] != str[r]) return false;
        l++; r--;
    }
    return true;
}

int mincuts(string str, int n)
{
    vector<int> cuts (n+1, INT_MAX);
    vector<vector<int>> tracker (26, vector<int>());
    cuts[0] = -1;
    //tracker[str[0] - 'a'].push_back(0);
    for(int i=1; i<=n; i++)
    {
        cuts[i] = cuts[i-1] + 1;
        //cout << str[i-1] << " ";
        if( !(tracker[str[i-1]-'a']).empty() )
        {
            for(auto &j: tracker[str[i-1]-'a'])
            {
                //cout << "index: " << j << " ";
                if(!ispalindrome(str, j-1, i-1)) continue;
                cuts[i] = min(cuts[i], cuts[j-1] + 1);   
                //cout << cuts[i] << " ";
            }
        }
        //cout << cuts[i] << endl;
        tracker[str[i-1]-'a'].push_back(i);
    }
    return cuts[n];
}

int main()
 {
	//code
	int q;
	cin >> q;
	
	for (int q_i=0; q_i<q; q_i++){
	    string str;
	    cin >> str;
	    //cin.ignore();
	    
	    cout << mincuts(str, str.length()) << endl;
	}
	return 0;
}