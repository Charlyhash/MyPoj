/*
poj-1384 完全背包

题目大意：一个盒子装着硬币，空盒子的质量E,装了硬币质量为F。有N种不同的硬币有着价值P和质量W。求解最少的钱数
输入：
第一行为测试用例的数目
每一个测试用例，第一行为E， F,第二行为硬币的数量N,接下来的N行为N种硬币的P和W

输出：最少的钱数

解题思路：
完全背包问题。
一般框架：
for (int i = 0; i < nObj; ++i)
{
	for (int j = w[i]; j <= weightSum; ++j)
	{
		dp[j] = max(dp[j], dp[j-w[i]]+p[i]);
	}
}

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#pragma warning(disable:4996)

#define LOACAL
#ifdef LOACAL
#include <fstream>
#endif

using namespace std;

const int MAX_N = 505;
const int MAX_W = 10005;
const int MAX_INT = 1000000;

int t;
int dp[MAX_W];
int p[MAX_N];
int w[MAX_N];

int main()
{

#ifdef LOACAL
	FILE* s;
	if (freopen_s(&s, "poj1384.txt", "r", stdin) != 0)
	{
		cout << "Open file error!" << endl;
		return -1;
	}
#endif
	scanf("%d", &t);
	while (t--)
	{
		int e, f;
		int weightSum;		//容纳的总重量
		scanf("%d%d", &e, &f);
		weightSum = f - e;
		int n;
		scanf("%d", &n);
		//初始化
		for (int i = 0; i < MAX_N; ++i)
			p[i] = w[i] = 0;
		for (int i = 1;i <= n; ++i)
		{
			scanf("%d%d", &p[i], &w[i]);
		}
		//注意题目要求
		for (int i = 0; i <= MAX_W; ++i)
			dp[i] = MAX_INT;
		dp[0] = 0;

		//完全背包
		for (int i = 1; i <= n; ++i)
		{
			for (int j = w[i]; j <= weightSum; ++j)
			{
				dp[j] = min(dp[j], dp[j-w[i]]+p[i]);
			}
		}

		if (dp[weightSum] == MAX_INT)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[weightSum]);
		}
	}

#ifdef LOACAL
	fclose(s);
#endif
	return 0;
}