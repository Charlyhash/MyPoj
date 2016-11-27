/*
poj1562 DFS算法
@代表油田，它的8个方向有@则表示是同一块油田，给一个图，求所有油田块
直接DFS，对于访问过的要做标记
*/

#include <iostream>
#include <fstream>

using namespace  std;

const int N = 100;
int dir[8][8] = { {-1, -1}, {-1,0}, {-1,1 }, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
char map[N][N];
int visited[N][N];
int m, n;

void DFS(int i, int j)
{
	visited[i][j] = 1;
	for (int k = 0; k < 8; ++k)		//对于0个方向的迭代
	{
		int ii = i + dir[k][0];
		int jj = j + dir[k][1];
		if (ii >= 0 && ii < n && jj >= 0 && jj < m && (map[i][j] == '@'))
		{
			if (!visited[ii][jj])
				DFS(ii, jj);
		}

	}
}

int main()
{
	FILE* stream;
	if (freopen_s(&stream, "poj1652.txt", "r", stdin) != 0)
	{
		cout << "Open file error!" << endl;
		return -1;
	}
	int i, j, cnt;
	while (cin >> n >> m, n || m)
	{
		//输入
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				cin >> map[i][j];
			}
		}

		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				if ((map[i][j] == '@') && (!visited[i][j]))
				{
					cnt++;
					DFS(i, j);					
				}
			}
		}

		cout << cnt << endl;
	}

	fclose(stream);
	return 0;
}