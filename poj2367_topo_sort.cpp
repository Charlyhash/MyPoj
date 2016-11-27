#include <iostream>
#include <fstream>
using namespace std;
#define MAXN 105
int adj[MAXN][MAXN];	//�ڽӱ�
int inDegree[MAXN];		//���
int n;
int result[MAXN];		//�������
int top;

void topo_sort()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (inDegree[j] == 0)
			{
				result[top++] = j;		//��¼���
				inDegree[j] = -1;		//�Ժ��ٷ���			
				for (int k = 0; k <= n; ++k)
				{
					if (adj[j][k] == 1)
					{
						inDegree[k]--;		//��jλ����ص���ȼ�1
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