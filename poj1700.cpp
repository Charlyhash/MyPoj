/*
poj1700 贪心算法
问题描述：有n个人要过河，船每次只能两个人，问最短的过河时间。
解题思路：
======1======t[1] + t[0] + t[i] + t[1]
1、让最快和次快先过去，最快的回来
2、让最慢的和次慢的一起走，然后次快的回来
3、下一次循序。
=======2======t[i] + t[0] + t[i-1] + t[0]
1、最快的和最慢先过，最快回
2、最快和最先过，最快回。

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
		if (i == 0)		//只有一个人
		{
			tol = t[0];
		}
		while (i > 0)
		{
			if (i == 1)	//只有2个人，按最长时间那个人算
			{
				tol += t[1];
			}
			else if (i == 2)	//3个人，0和1过，0回，0和2过。
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