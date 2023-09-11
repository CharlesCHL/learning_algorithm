

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	5

int F[1<<SIZE][SIZE];

int hamilton(int, int (*)[SIZE]);

int min(int, int);

int main(void)
{
	int n = SIZE;
	int arr_1[SIZE][SIZE] = {
		{0, 1, 2, 3, 4},
		{1, 0, 1, 2, 3},
		{2, 1, 0, 1, 2},
		{3, 2, 1, 0, 1},
		{4, 3, 2, 1, 0},
	};	//五个点按顺序在一条直线上

	int arr_2[SIZE][SIZE] = {
		{0, 1, 5, 4, 3},
		{1, 0, 3, 5, 1},
		{5, 3, 0, 4, 2},
		{4, 5, 4, 0, 6},
		{3, 1, 2, 6, 0}
	};	//测试用例，不难得出最短路径为12, 12435和14325两种情况
	
	int ans_1, ans_2;

	ans_1 = hamilton(n, arr_1);	//答案显然为4
	
	ans_2 = hamilton(n, arr_2);	//答案显然为4

	printf("ans_1 = %d\n", ans_1);
	
	printf("ans_2 = %d\n", ans_2);
	
	return 0;
}

int hamilton(int size, int (*value)[SIZE])
{
	memset(F, 0x3f, sizeof(F));
	F[1][0] = 0;
	for(int i = 1; i < 1<<SIZE; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if((i>>j)&1)
			{
				for(int k = 0; k < size; k++)
				{
					if(((i^(1<<j))>>k)&1)
						F[i][j] = min(F[i][j], F[i^(1<<j)][k] + value[k][j]);
				}
			}
		}
	}
	return F[(1<<size) - 1][size -1];
}

int min(int a, int b)
{
	return a < b ? a : b;
}

