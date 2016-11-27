/*
poj 3624
Bessie has gone to the mall's jewelry store and spies a charm bracelet.
Of course, she'd like to fill it with the best charms possible from the N (1 ≤ N ≤ 3,402) available charms.
Each charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400), a 'desirability' factor Di (1 ≤ Di ≤ 100),
and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M (1 ≤ M ≤ 12,880).
Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di

Output

* Line 1: A single integer that is the greatest sum of charm desirabilities that
can be achieved given the weight constraints

题目大意：M为能容纳的总重量，N为物品数。从N个物品中选择总重量不超过M的物品，使得desirability最大。

解题思路：01背包问题
dp[i][j]表示第i个物品放入容量为j的重量中最大的吸引力
dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + d[i]) 其中weight[i]为j的重量，d[i]为j的吸引力

优化:计算dp[j]时，能取到dp[i-1][j] 和 dp[i-1][j-weight[i]]即可，让循环从m...1,这样每次计算dp[j]时，
dp[i-1][j] 和 dp[i-1][j-weight[j]]为上一次计算的值。
状态转移方程为：dp[j] = max{dp[j], dp[j-w[i]]+d[i]}

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//const int MAX_M = 12885;
//const int MAX_N = 3410;
//
//int dp[MAX_N][MAX_M];
//int w[MAX_N];
//int d[MAX_N];
//
//int main()
//{
//	int m, n;
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; ++i)
//		cin >> w[i] >> d[i];
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= m; ++j)
//		{
//			if (w[i] <= j)
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + d[i]);
//			}
//			else
//				dp[i][j] = dp[i-1][j];
//		}
//	}
//
//	cout << dp[n][m] << endl;
//
//	return 0;
//}

const int MAX_M = 12885;
const int MAX_N = 3410;

int dp[MAX_M];
int w[MAX_N];
int d[MAX_N];

int main()
{
	int m, n;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> d[i];
	//for (int i = 1; i <= n; ++i)
	//{
	//	for (int j = m; j >= 1; --j)
	//	{
	//		if (w[i] <= j)
	//		{
	//			dp[j] = std::max(dp[j], dp[j - w[i]] + d[i]);
	//		}
	//		else
	//			dp[j] = dp[j];
	//	}
	//}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= w[i]; --j)
		{
			dp[j] = std::max(dp[j], dp[j - w[i]] + d[i]);
		}
	}

	std::cout << dp[m] << endl;

	return 0;
}