#include <bits/stdc++.h>

using namespace std;

void KMPPreprocessing(string pattern, int *resetTable, int p_size)
{
	int i=0, j = -1;
	resetTable[0]= -1;
	while(i < p_size)
	{
		while(j>=0 && pattern[i] != pattern[j])
			j = resetTable[j];
		++i, ++j;
		resetTable[i] = j;
	}
}

void KMPSearch(string str, string pattern)
{
	int p_size = pattern.size(), t_size = str.size();
	int resetTable[p_size];

	KMPPreprocessing(pattern, resetTable, p_size);

	int i=0, j = -1;
	while(i < t_size)
	{
		while(j>=0 && str[i] != pattern[j])
			j = resetTable[j];
		++i, ++j;
		if(j == p_size)
		{
			cout<<"pattern found at: "<<i-j;
			j = resetTable[j];
		}
	}

}

int main()
{
	string T,P;
	cin>>T;
	cin>>P;
	KMPSearch(T, P);
	return 0;
}

//abaabcxabcxabxa
//abcxabx

