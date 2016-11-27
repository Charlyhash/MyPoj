/*
poj-2063 完全dp
题目大意：
有n中投资方案，每一年，每种钱数为value, 利润为interest。计算N年最后的钱数
输入：
第一个行为测试用例个数nCase
第二行为钱数total和年数year
第三行为方案数num
后面为每一个方案的钱数m和利润p

解题思路：完全dp
需要注意的地方：
由于total和m都是1000的整数倍，那么可以除以1000，以减少dp的次数。
题目要求year年的钱数，因此每年的钱数还要作为总钱数total作为下一年的钱数继续dp.

*/


#include <cstdio>

#pragma warning(disable:4996)

#define LOACAL
#ifdef LOACAL
#include <iostream>
#include <fstream>
using namespace std;
#endif

const int MAX_D = 12;
const int MAX_M = 1000005;

int m[MAX_D];
int p[MAX_D];
int dp[MAX_M];
int total, year, num;

int GetMax(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
#ifdef LOACAL
	FILE* s;
	if (freopen_s(&s, "poj2063.txt", "r", stdin) != 0)
	{
		cout << "Open file error!" << endl;
		return -1;
	}
#endif
	int nCase;
	scanf("%d", &nCase);
	while (nCase--)
	{
		//初始化
		for (int i = 0; i < MAX_D; ++i)
			m[i] = p[i] = 0;
		for (int i = 0; i < MAX_M; ++i)
			dp[i] = 0;
		scanf("%d%d%d", &total, &year, &num);
		for (int i = 0; i < num; ++i)
		{
			scanf("%d%d", &m[i], &p[i]);
			m[i] /= 1000;
		}
		
		for (int i = 0; i < year; ++i)
		{
			//初始化
			for (int j = 0; j <= total/1000; ++j)
				dp[j] = 0;
			//dp
			for (int j = 0; j < num; ++j)
			{
				for (int k = m[j]; k <= total / 1000; ++k)
					dp[k] = GetMax(dp[k], dp[k - m[j]] + p[j]);
			}
			total += dp[total / 1000];
		}
		printf("%d\n", total);
	}

#ifdef LOACAL
	fclose(s);
#endif
	return 0;
}