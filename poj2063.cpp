/*
poj-2063 ��ȫdp
��Ŀ���⣺
��n��Ͷ�ʷ�����ÿһ�꣬ÿ��Ǯ��Ϊvalue, ����Ϊinterest������N������Ǯ��
���룺
��һ����Ϊ������������nCase
�ڶ���ΪǮ��total������year
������Ϊ������num
����Ϊÿһ��������Ǯ��m������p

����˼·����ȫdp
��Ҫע��ĵط���
����total��m����1000������������ô���Գ���1000���Լ���dp�Ĵ�����
��ĿҪ��year���Ǯ�������ÿ���Ǯ����Ҫ��Ϊ��Ǯ��total��Ϊ��һ���Ǯ������dp.

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
		//��ʼ��
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
			//��ʼ��
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