/*
poj1562 DFS�㷨
@�����������8��������@���ʾ��ͬһ�������һ��ͼ�������������
ֱ��DFS�����ڷ��ʹ���Ҫ�����
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
	for (int k = 0; k < 8; ++k)		//����0������ĵ���
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
		//����
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