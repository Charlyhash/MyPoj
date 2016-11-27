/*
poj 3264:RMQ

题目大意：对于给定的数组A[],给定一个区间范围，返回这个区间最大值与最小值的差

ST算法是求解RMQ问题的经典算法，预处理时间为O(nl0gn),查询时间为O(1)

预处理部分

预处理部分使用DP(动态规划)解决。如果要求解的数列为A[]={2,1,4,6,8,3,5,9,6},需要访问最小值。
状态空间的定义为：F[i,j]表示第i个数起，连续的2^j个数中的最大值.比如F[1,0]=min{A[1]}=2,F[2,2]=max{A[2],A[3],A[4],A[5]} = 1。显然初始状态为F[i,0]=A[i].
状态转移方程：因为F[i,j]中元素的个数为2^j个，因此我们考虑把其分为两段。从i到i+2^(j-1)-1和从i+2^(j-1)到i+2^j-1。那么状态转移方程为：F[i,j]=min(F[i,j-1], F[i+2^(j-1), j-1])

预处理的代码如下：

void RMQ(int n)
{
	for (int j = 1; j < 32; ++j)
	{
		for (int i = 1; i <= n; ++i
		{
			if (i + (1 << j) -1 <= n)//不能超过n
			dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
		}
	}
}
查询部分

查询区间为[i,j],那么我们只需要找到覆盖这个闭区间的最小的幂即可(注意这里第可以有重复的，比如查询[3,4,5,6,7,8],需要查[3,4,5,6]和[5,6,7,8]).
区间长度为：j-i+1,那么区间的最小幂为k=log2(j-i+1),则有RMQ(A,i,j)=min(dp[i,k][j-2^k+1], k)。
比如说，要求区间为[3,8],k=log2(8-3+1)=2。那么RMQ(A,3,8) = min(dp[3][2], dp[5][2])
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)

const int MAX_N = 50000 + 10;
const int MAX_L = 20;//j的长度，大约可以访问1000，000

int A[MAX_N];
int dp_min[MAX_N][MAX_L];
int dp_max[MAX_N][MAX_L];

void init(int n)
{
	for (int k = 1; k <= n; ++k)
	{
		dp_min[k][0] = A[k];
		dp_max[k][0] = A[k];
	}
	for (int j = 1; j < MAX_L; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i + (1 << j) - 1 <= n)
			{
				dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << (j - 1))][j - 1]);
				dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
}

int RMQ(int i, int j)
{
	int k = (int)(log(double(j - i + 1)) / log(2.0));
	return max(dp_max[i][k], dp_max[j - (1 << k) + 1][k]) - 
		min(dp_min[i][k], dp_min[j - (1 << k) + 1][k]);
}

int main()
{
	freopen("poj3264.txt", "r", stdin);
	int N, Q;
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	init(N);
	for (int i = 1; i <= Q; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", RMQ(a, b));
	}

	return 0;
}