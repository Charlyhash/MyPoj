
/*
poj1003 - 简单计算题
题目大意：给你一个长度，要用多少个card才能搭起来,因为是在桌子边缘上的，
所以第一个长度为1/2,第二个长度为1/3...
	0.01<len<5.20
Reference:http://blog.csdn.net/lyy289065406/article/details/6642575
心得：理清题意，多思考。
思路：用维护一个长度数组，记录第index个card后的总长度
	1 -- 1/2
	2 -- 1/3
	3 -- 1/4
	...
那么: length[i] = length[i-1] + (1.0)/(i + 1)
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