/*
poj1276-多重背包

题目大意：有一个Cash Machine，面值为W[i]的钱数目为V[i].问输入Cash,返回能换得的最多的钱数
输入：钱Cash, 零钱的种类n,后面为n中钱，第一个为面值，第二个为数目
输出：能换得的最多的钱数。

解题思路：多重背包cost=value
*/


#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 12;
const int MAX_M = 100005;

int w[MAX_N];
int v[MAX_N];
int dp[MAX_M];

int GetMax(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int cash;//总钱数
	int n;	//零钱种类
	int i, j, k, m;
	while (cin >> cash >> n)
	{
		//初始化
		for (i = 0; i < MAX_N; ++i)
			w[i] = v[i] = 0;
		for (i = 0; i < MAX_M; ++i)
			dp[i] = 0;
		//输入
		for (int  i = 0 ; i < n; ++i)
		{
			cin >> w[i] >> v[i];
		}

		//dp
		for (int i = 0; i < n; ++i)
		{
			if (w[i] * v[i] >= cash)
			{
				//完全背包
				for (j = v[i]; j <= cash; ++j)
				{
					dp[j] = GetMax(dp[j], dp[j - v[i]] + v[i]);
				}
			}
			else
			{
				//二进制拆分：多重背包
				k = 1;
				m = w[i];
				while (k < m)
				{
					//转化为01背包
					for (j = cash; j >= k*v[i]; --j)
					{
						dp[j] = GetMax(dp[j], dp[j - k*v[i]] + k*v[i]);
					}
					//继续分
					m -= k;
					k = k << 1;
				}
				if (m > 0)
				{
					//处理剩余的问题
					for (j = cash; j >= m*v[i]; --j)
					{
						dp[j] = GetMax(dp[j], dp[j - m*v[i]] + m*v[i]);
					}
				}
			}
		}

		cout << dp[cash] << endl;
	}

	return 0;
}

