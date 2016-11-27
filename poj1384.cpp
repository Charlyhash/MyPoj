/*
poj-1384 ��ȫ����

��Ŀ���⣺һ������װ��Ӳ�ң��պ��ӵ�����E,װ��Ӳ������ΪF����N�ֲ�ͬ��Ӳ�����ż�ֵP������W��������ٵ�Ǯ��
���룺
��һ��Ϊ������������Ŀ
ÿһ��������������һ��ΪE�� F,�ڶ���ΪӲ�ҵ�����N,��������N��ΪN��Ӳ�ҵ�P��W

��������ٵ�Ǯ��

����˼·��
��ȫ�������⡣
һ���ܣ�
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
		int weightSum;		//���ɵ�������
		scanf("%d%d", &e, &f);
		weightSum = f - e;
		int n;
		scanf("%d", &n);
		//��ʼ��
		for (int i = 0; i < MAX_N; ++i)
			p[i] = w[i] = 0;
		for (int i = 1;i <= n; ++i)
		{
			scanf("%d%d", &p[i], &w[i]);
		}
		//ע����ĿҪ��
		for (int i = 0; i <= MAX_W; ++i)
			dp[i] = MAX_INT;
		dp[0] = 0;

		//��ȫ����
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