

#include <stdio.h>
#include <stdlib.h>

//	n个盘子3座塔
int hanoi_1(int n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 3;

	int ans = 0;
	ans += hanoi_1(n - 1) + 1 + hanoi_1(n - 1);

	return ans;
}

//	n个盘子4座塔
int hanoi_2(int n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 3;
	if(n == 3)
		return 5;
	int ans = hanoi_1(n);
	int tmp = 0;
	for(int i = 1; i < n; i++)
	{
		tmp = 2 * hanoi_2(i) + hanoi_1(n - i);
		ans = ans > tmp ? tmp : ans;
	}

	return ans;
}

int main(void)
{
	int n = 10;
	printf("%d\n", hanoi_1(n));
	printf("%d\n", hanoi_2(n));
	return 0;
}



