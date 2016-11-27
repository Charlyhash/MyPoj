/*
poj1700 ̰���㷨
������������n����Ҫ���ӣ���ÿ��ֻ�������ˣ�����̵Ĺ���ʱ�䡣
����˼·��
======1======t[1] + t[0] + t[i] + t[1]
1�������ʹο��ȹ�ȥ�����Ļ���
2���������ĺʹ�����һ���ߣ�Ȼ��ο�Ļ���
3����һ��ѭ��
=======2======t[i] + t[0] + t[i-1] + t[0]
1�����ĺ������ȹ�������
2���������ȹ������ء�

*/

#include <iostream>
#include <algorithm>

const int MAXN = 1005;
int T, N;
int tol;
int t[MAXN];

int main()
{
	std::cin >> T;
	while (T > 0)
	{
		--T;
		std::cin >> N;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> t[i];
		}
		tol = 0;
		std::sort(t, t + N);
		int i = N - 1;
		if (i == 0)		//ֻ��һ����
		{
			tol = t[0];
		}
		while (i > 0)
		{
			if (i == 1)	//ֻ��2���ˣ����ʱ���Ǹ�����
			{
				tol += t[1];
			}
			else if (i == 2)	//3���ˣ�0��1����0�أ�0��2����
			{
				tol += (t[0] + t[1] + t[2]);
			}
			else
			{
				tol += ((2 * t[0] + t[i - 1] + t[i]) < (t[0] + 2 * t[1] + t[i])) ?
					(2 * t[0] + t[i - 1] + t[i]) : (t[0] + 2 * t[1] + t[i]);
			}
			i = i - 2;
		}

		std::cout << tol << std::endl;

	}

	return 0;
}