lli power(int a, int n)
{
	lli res=1;
	while(n)
	{
		if(n%2)
			res = (res * a)% MOD, n--;
		a = (a * a) % MOF, n /= 2;
	}
	return res;
}