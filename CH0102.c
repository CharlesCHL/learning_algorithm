

#include <stdio.h>
#include <stdlib.h>

long long int mulmod(long long int, long long int, long long int);


int main(void)
{
	int a = 12;
	int b = 13;
	int p = 7;

	int ans = mulmod(a, b, p);

	printf("ans = %d\n", ans);

	return 0;

}

long long int mulmod(long long int a, long long int b, long long int p)
{
	long long int ans = 0 % p;
	for(; b; b >>= 1)
	{
		if(b & 1)
			ans = (ans + a) % p;
		a = (a * 2) % p;
	}
	return ans;
}


