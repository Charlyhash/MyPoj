/*
poj1094 拓扑排序
题目大意：给定字母的偏序关系，判断时候能唯一确定它们之间的关系。
拓扑排序结果可以分为3种情况：1、可以判断，2、有环出现了矛盾；3、条件不足不能判断
a.先判有没有环，有环就直接输出不能确定；（有两种情况，一种是，直接判断反向边，肯定就有环了，
第二种情况是，生成的拓扑序内含字母个数小于题目中给出的字母的个数）
b.如果没有环，那么就看会不会有多种情况，如果有多种情况就再读下一行；
如果全部行读完还是有多种情况，就是确定不了
c.如果最后没有环，也不存在多种情况（即每次取出来入度为零的点只有一个），那么才是答案
*/

#include <iostream>
#include <stack>
#define LOACAL
#ifdef LOACAL
#include <fstream>
#endif
using namespace std;

#define MAXN 27
int graph[MAXN][MAXN];	//图
int indegree[MAXN];		//入度数组
int list[MAXN];			//结果数组
int in[MAXN];			//临时入度数组

/*
拓扑排序
*/
int topo_sort(int n)
{
	memcpy(in, indegree, sizeof(indegree));
	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		if (!in[i])		//入度为0
			s.push(i);
	}
	int countt = 0;
	bool flag = false;
	while (!s.empty())
	{
		if (s.size() > 1)	//一次有多个入度为0，说明不止一种排序方式
			flag = true;
		int tmp = s.top();
		list[countt++] = tmp;		//记录结果
		s.pop();
		for (int i = 0; i < n; ++i)	//删除tmp有关的边后计算入度数，入度为0则可以压入栈
		{
			if (graph[tmp][i] && (--in[i] == 0))
				s.push(i);
		}
	}
	if (countt != n)		//为空后判断啦，有环的话，计数会<n
		return 1; //有环
	else if (flag)
		return 2;	//有多种情况
	return 0;		//有唯一的情况

}

int main()
{
	int n, m;
#ifdef LOACAL
	FILE* s;
	if (freopen_s(&s, "poj1094.txt", "r", stdin) != 0)
	{
		cout << "Open file error!" << endl;
		return -1;
	}
#endif
	while (cin >> n >> m && (n || m))
	{
		bool flag = false, flag2 = false;//flag:是否可以判断，flag2:是否有环
		memset(graph, 0, sizeof(graph));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= m; ++i)
		{
			char a, b, waste;
			cin >> a >> waste >> b;
			if (!flag && !flag2)
			{
				if (graph[b - 'A'][a - 'A'] == 1)		//有反向的边
				{
					flag2 = true;
					cout << "Inconsistency found after " << i << " relations." << endl;
					continue;
				}
				if (graph[a - 'A'][b - 'A'] == 0)		//并没有连接
				{
					graph[a - 'A'][b - 'A'] = 1;
					indegree[b - 'A']++;
				}

				int flag3 = topo_sort(n);
				if (flag3 == 0)
				{
					cout << "Sorted sequence determined after " << i << " relations: ";
					for (int j = 0; j < i; ++j)
					{
						cout << (char)(list[j] + 'A');
					}
					cout << "." << endl;
					flag = true;
				}
				else if (flag3 == 1)
				{
					cout << "Inconsistency found after " << i << " relations." << endl;
					flag2 = true;
				}
			}
		}

		if (!flag && !flag2)
			cout << "Sorted sequence cannot be determined." << endl;
	}

	fclose(s);
	return 0;
}

