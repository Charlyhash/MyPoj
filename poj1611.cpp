#include <iostream>
#define LOCAL
#ifdef LOCAL
#include <fstream>
#endif
using namespace std;

const int MAXN = 30001;		//节点数
int parent[MAXN];			//父节点
int ran[MAXN];				//树的高度
int num[MAXN];				//元素的个数

void MakeSet(int x)
{
	parent[x] = x;
	ran[x] = 0;
	num[x] = 1;
}
//查找
int FindSet(int x)
{
	int r = x, tmp;
	while (parent[r] != r)	//找到根节点
		r = parent[r];
	//路径压缩
	while (x != r)
	{
		tmp = parent[x];
		parent[x] = r;
		x = tmp;
	}
	
	return x;
}
//合并
void UnionSet(int x, int y)
{
	x = FindSet(x);
	y = FindSet(y);
	if (x == y)			//有相同的根节点，不用合并啦
		return;
	if (ran[x] > ran[y])
	{
		parent[y] = x;	//x所在的树高度比y高，让x成为y的根节点
		num[x] += num[y];
	}
	else
	{
		parent[x] = y;
		if (ran[x] == ran[y])
			ran[y]++;
		num[y] += num[x];
	}
}
int main()
{
#ifdef LOCAL
	FILE* s;
	if (freopen_s(&s, "poj1611.txt", "r", stdin) != 0)
	{
		cout << "Open file error!" << endl;
		return -1;
	}
#endif
	int n, m, x, y, i, t, j;
	while (cin >> n >> m && (m || n))
	{
		if (m == 0)
		{
			cout << 1 << endl;
			continue;
		}
		for (i = 0; i < n; ++i)
			MakeSet(i);
		for (i = 0; i < m; ++i)
		{
			cin >> t >> x;
			for (j = 1; j < t; ++j)
			{
				cin >> y;
				UnionSet(x, y);
				x = y;
			}
		}
		x = FindSet(0);
		cout << num[x] << endl;

	}
#ifdef LOCAL
	fclose(s);
#endif
	return 0;
}