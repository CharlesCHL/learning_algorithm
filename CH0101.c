

#include <stdio.h>
#include <stdlib.h>

int powermod(int, int, int);


int main(void)
{
	int a = 12;
	int b = 13;
	int p = 7;

	int ans = powermod(a, b, p);

	printf("ans = %d\n", ans);

	return 0;

}

int powermod(int a, int b, int p)
{
	int ans = 1 % p;
	for(; b; b >>= 1)
	{
		if(b & 1)
			ans = (long long)ans * a % p;
		a = (long long)a * a % p;
	}
	return ans;
}


