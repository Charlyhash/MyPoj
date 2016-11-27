/*
poj1276-���ر���

��Ŀ���⣺��һ��Cash Machine����ֵΪW[i]��Ǯ��ĿΪV[i].������Cash,�����ܻ��õ�����Ǯ��
���룺ǮCash, ��Ǯ������n,����Ϊn��Ǯ����һ��Ϊ��ֵ���ڶ���Ϊ��Ŀ
������ܻ��õ�����Ǯ����

����˼·�����ر���cost=value
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
	int cash;//��Ǯ��
	int n;	//��Ǯ����
	int i, j, k, m;
	while (cin >> cash >> n)
	{
		//��ʼ��
		for (i = 0; i < MAX_N; ++i)
			w[i] = v[i] = 0;
		for (i = 0; i < MAX_M; ++i)
			dp[i] = 0;
		//����
		for (int  i = 0 ; i < n; ++i)
		{
			cin >> w[i] >> v[i];
		}

		//dp
		for (int i = 0; i < n; ++i)
		{
			if (w[i] * v[i] >= cash)
			{
				//��ȫ����
				for (j = v[i]; j <= cash; ++j)
				{
					dp[j] = GetMax(dp[j], dp[j - v[i]] + v[i]);
				}
			}
			else
			{
				//�����Ʋ�֣����ر���
				k = 1;
				m = w[i];
				while (k < m)
				{
					//ת��Ϊ01����
					for (j = cash; j >= k*v[i]; --j)
					{
						dp[j] = GetMax(dp[j], dp[j - k*v[i]] + k*v[i]);
					}
					//������
					m -= k;
					k = k << 1;
				}
				if (m > 0)
				{
					//����ʣ�������
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

