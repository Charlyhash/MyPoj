/*
��һ������������N��K����һ���ո�ָ���
����K��ÿ�������������� D��X��Y������֮����һ���ո����������D��ʾ˵�������ࡣ
��D=1�����ʾX��Y��ͬ�ࡣ
��D=2�����ʾX��Y��
Output

ֻ��һ����������ʾ�ٻ�����Ŀ��

Sample Input

100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
Sample Output

3
*/

#include<iostream>

#define LOCAL
#ifdef LOCAL
#include<fstream>
#endif // LOCAL

using namespace std;

const int MAXN = 50005;
const int SAME = 0;
const int ENEMY = 1;
const int FOOD = 2;
struct Animal
{
	int parent;
	int num;
	int relation;
};
Animal ani[MAXN];
long ans;

int FindParent(Animal* node)
{
	int tmp;
	if (node->parent == node->num)
		return node->parent;
	tmp = node->parent;
	node->parent = FindParent(&ani[node->parent]);
	node->relation = (ani[tmp].relation + node->relation) % 3;

	return node->parent;
}

void Union(int x, int y, int a, int b, int d)
{
	ani[b].parent = a;
	ani[b].relation = ((3 - ani[y].relation) + d - 1 + ani[x].relation) % 3;
}

void Init(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		ani[i].num = i;
		ani[i].parent = i;
		ani[i].relation = SAME;
	}
}

int main()
{
#ifdef LOCAL
	FILE* s;
	if ((freopen_s(&s, "poj1182.txt", "r", stdin)) != 0)
	{
		//output 154
		cout << "Open file error!" << endl;
		return -1;
	}
#endif // LOCAL

	int N, K;
	int d, X, Y;
	cin >> N >> K;
	Init(N);
	for (int i = 0; i < K; ++i)
	{
		cin >> d >> X >> Y;
		if (X > N || Y > N)
			ans++;
		else
		{
			if (d == 2 && X == Y)
				ans++;
			else
			{
				int a = FindParent(&ani[X]);
				int b = FindParent(&ani[Y]);
				if (a != b)
				{
					Union(X, Y, a, b, d);
				}
				else
				{
					switch (d)
					{
					case 1:
						if (ani[X].relation != ani[Y].relation)
							ans++;
						break;
					case 2:
						if (((ani[Y].relation + 3 - ani[X].relation) % 3) != 1)
							ans++;
						break;
					default:
						break;
					}
				}
			}
		}
	}
	cout << ans << endl;

#ifdef LOCAL
	fclose(s);
#endif // LOCAL

	return 0;
}