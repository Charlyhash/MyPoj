/*
poj2376 ̰���㷨
��Ŀ���⣺��С���串�Ǵ����䣬�����С�ĸ�������������ܸ��ǣ������-1
��Ŀ������ʹ��̰���㷨��ÿ�ζ�Ӧ�����Ѿ����ǵ����価���ܴ�
����������http://contest.usaco.org/DEC04_8.htm
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

//��������
bool cmp(Shift a, Shift b)
{
	if (a.start != b.start)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int N;			//����
int T;			//�ܳ���
Shift a[MAXN];	//�߶�����

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

	int right = 1;		//�Ѿ��ﵽ���Ҷ�
	int newRight = 0;	//�µ��Ҷ�
	int i = 1;
	int cnt = 0;		//�ܶ���

	while(i <= N && right <= T)
	{
		//�ҵ�һ�����
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