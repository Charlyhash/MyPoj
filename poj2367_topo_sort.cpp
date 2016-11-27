#include <iostream>
#include <fstream>
using namespace std;
#define MAXN 105
int adj[MAXN][MAXN];	//邻接表
int inDegree[MAXN];		//入度
int n;
int result[MAXN];		//结果数组
int top;

void topo_sort()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (inDegree[j] == 0)
			{
				result[top++] = j;		//记录结果
				inDegree[j] = -1;		//以后不再访问			
				for (int k = 0; k <= n; ++k)
				{
					if (adj[j][k] == 1)
					{
						inDegree[k]--;		//和j位置相关的入度减1
					}
				}
				break;
			}
		}

	}
}

int main()
{
	int i, j;
	FILE* stream;
	if (freopen_s(&stream, "poj2367.txt", "r", stdin) != 0)
	{
		cout << "Fail to open file!" << endl;
		return -1;
	}
	cin >> n;
	memset(inDegree, 0, MAXN* sizeof(int));
	memset(adj, 0, MAXN*sizeof(int));
	for (i = 1; i <= n; ++i)
	{
		while (cin >> j, j)
		{
			adj[i][j] = 1;
			inDegree[j]++;
		}
	}
	topo_sort();
	for (i = 0; i < top; ++i)
	{
		cout << result[i] << " ";
	}

	fclose(stream);
	return 0;
}