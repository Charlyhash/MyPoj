/*
poj 3264:RMQ

��Ŀ���⣺���ڸ���������A[],����һ�����䷶Χ����������������ֵ����Сֵ�Ĳ�

ST�㷨�����RMQ����ľ����㷨��Ԥ����ʱ��ΪO(nl0gn),��ѯʱ��ΪO(1)

Ԥ������

Ԥ������ʹ��DP(��̬�滮)��������Ҫ��������ΪA[]={2,1,4,6,8,3,5,9,6},��Ҫ������Сֵ��
״̬�ռ�Ķ���Ϊ��F[i,j]��ʾ��i������������2^j�����е����ֵ.����F[1,0]=min{A[1]}=2,F[2,2]=max{A[2],A[3],A[4],A[5]} = 1����Ȼ��ʼ״̬ΪF[i,0]=A[i].
״̬ת�Ʒ��̣���ΪF[i,j]��Ԫ�صĸ���Ϊ2^j����������ǿ��ǰ����Ϊ���Ρ���i��i+2^(j-1)-1�ʹ�i+2^(j-1)��i+2^j-1����ô״̬ת�Ʒ���Ϊ��F[i,j]=min(F[i,j-1], F[i+2^(j-1), j-1])

Ԥ����Ĵ������£�

void RMQ(int n)
{
	for (int j = 1; j < 32; ++j)
	{
		for (int i = 1; i <= n; ++i
		{
			if (i + (1 << j) -1 <= n)//���ܳ���n
			dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
		}
	}
}
��ѯ����

��ѯ����Ϊ[i,j],��ô����ֻ��Ҫ�ҵ�����������������С���ݼ���(ע������ڿ������ظ��ģ������ѯ[3,4,5,6,7,8],��Ҫ��[3,4,5,6]��[5,6,7,8]).
���䳤��Ϊ��j-i+1,��ô�������С��Ϊk=log2(j-i+1),����RMQ(A,i,j)=min(dp[i,k][j-2^k+1], k)��
����˵��Ҫ������Ϊ[3,8],k=log2(8-3+1)=2����ôRMQ(A,3,8) = min(dp[3][2], dp[5][2])
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)

const int MAX_N = 50000 + 10;
const int MAX_L = 20;//j�ĳ��ȣ���Լ���Է���1000��000

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