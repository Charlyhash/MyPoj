/*
poj2376 贪心算法
题目大意：用小区间覆盖大区间，输出最小的覆盖数。如果不能覆盖，则输出-1
题目分析：使用贪心算法，每次都应该让已经覆盖的区间尽可能大
测试用例：http://contest.usaco.org/DEC04_8.htm
*/

#include <iostream>
#include <algorithm>
#define LOCAL
#ifdef LOCAL
#include <fstream>
#endif
const int MAXT = 1000000 + 10;
const int MAXN = 25000 + 10;

typedef struct shift_
{
	int  start;
	int end;
}Shift;

//用于排序
bool cmp(Shift a, Shift b)
{
	if (a.start != b.start)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int N;			//行数
int T;			//总长度
Shift a[MAXN];	//线段数组

int main()
{
#ifdef LOCAL
	FILE *s;
	if (freopen_s(&s, "poj2376.txt", "r", stdin) != 0)
	{
		std::cout << "Open file error!" << std::endl;
		return -1;
	}
#endif

	//scanf_s("%d %d", N, T);
	std::cin >> N >> T;
	for (int i = 1; i <= N; ++i)
	{
		//scanf("%d, %d", a[i].start, a[i].end);
		std::cin >> a[i].start >> a[i].end;

	}
	std::sort(a+1, a+N+1, cmp);

	int right = 1;		//已经达到的右端
	int newRight = 0;	//新的右端
	int i = 1;
	int cnt = 0;		//总段数

	while(i <= N && right <= T)
	{
		//找到一个最长的
		while (i <= N && a[i].start <= right)
		{
			newRight = std::max(newRight, a[i].end);
			++i;
		} 

		if (newRight >= right)
		{
			cnt++;
			right = newRight+1;
		}
		else
		{
			break;
		}
	}

	if (right <= T)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", cnt);
	}

#ifdef LOCAL
	fclose(s);
#endif

	return 0;
}