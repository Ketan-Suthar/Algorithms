#include <bits/stdc++.h>

using namespace std;

void KMPPreprocessing(string pattern, int *resetTable, int p_size)
{
	int i = 1, j = 0;
	memset(resetTable, -1, sizeof(resetTable));
	while(i < p_size)
	{
		if(pattern[i] == pattern[j])
		{
			resetTable[i] = j;
			++i, ++j;
			continue;
		}
		if(j > 0)
			j = resetTable[j-1] + 1;
		else
			++i;
	}
}

void KMPSearch(string str, string pattern)
{
	int p_size = pattern.size(), t_size = str.size();
	int resetTable[p_size];

	KMPPreprocessing(pattern, resetTable, p_size);

	int i=0, j = 0;
	while((i + p_size - j) <= t_size)
	{
		if(str[i] == pattern[j])
		{
			if(j == p_size-1)
			{
				cout<<"\npattern found at: "<<i-j;
				break;
			}
			++i, ++j;
			continue;
		}
		if(j > 0)
			j = resetTable[j-1] + 1;
		else
			++i;
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

