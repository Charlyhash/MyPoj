
/*Description

There is a rectangular room, covered with square tiles.
Each tile is colored either red or black.A man is standing on a black tile.
From a tile, he can move to one of four adjacent tiles.
But he can't move on red tiles, he can move only on black tiles. 

Write a program to count the number of black tiles 
which he can reach by repeating the moves described above.
*/

#include <iostream>
#include <string>

using namespace std;

int W, H;
char map[21][21];
int result;
void DFS(int p, int q);

int main()
{
	int i,j;
	int p, q;
	FILE* stream;
	if (freopen_s(&stream, "poj1979.txt", "r", stdin) != 0)
	{
		cout << "Open file error!" << endl;
		return -1;
	}
	while ((cin >> W >> H) && (W!=0) && (H!=0))
	{
		result = 0;
		memset(map, 0, sizeof(map));
		//input
		for (i = 0; i < H; ++i)
		{
			for (j = 0; j < W; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == '@')
				{
					p = i;
					q = j;
					map[i][j] = '.';
				}
			}
		}
		
		DFS(p, q);

		cout << result << endl;
	}

	fclose(stream);
	return 0;
}

void DFS(int p, int q)
{
	if (p <= H - 1 && p >= 0 && q >= 0 && q <= W - 1 && map[p][q] == '.')//到达此点满足条件
	{
		result++;
		map[p][q] = '#';
	}
	else
	{
		return;
	}
	DFS(p-1, q);
	DFS(p, q - 1);
	DFS(p, q + 1);
	DFS(p + 1, q);
}
