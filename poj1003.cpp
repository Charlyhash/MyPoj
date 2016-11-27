
/*
poj1003 - �򵥼�����
��Ŀ���⣺����һ�����ȣ�Ҫ�ö��ٸ�card���ܴ�����,��Ϊ�������ӱ�Ե�ϵģ�
���Ե�һ������Ϊ1/2,�ڶ�������Ϊ1/3...
	0.01<len<5.20
Reference:http://blog.csdn.net/lyy289065406/article/details/6642575
�ĵã��������⣬��˼����
˼·����ά��һ���������飬��¼��index��card����ܳ���
	1 -- 1/2
	2 -- 1/3
	3 -- 1/4
	...
��ô: length[i] = length[i-1] + (1.0)/(i + 1)
*/

#include <iostream>

using namespace std;

int main()
{
	double len;					//length
	const int MAXN = 400;		//the number of card
	double length[MAXN];
	int res;					//result
	memset(length, 0, sizeof(length));

	while (cin >> len && len >= 0.01)
	{
		for (res = 1; res < MAXN; ++res)
		{
			length[res] = length[res - 1] + 1.0 / (res + 1.0);
			if (length[res] >= len)		//finished
				break;
		}
		cout << res << " card(s)" << endl;
	}

	return 0;
}