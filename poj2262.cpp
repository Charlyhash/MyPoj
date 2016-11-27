/*
poj2262 - 素数判断
题目大意：	给定一个数n,把它分解成两个素数的和，在这些分解中，这两个素数差要最大。
			6 <= n < 1000000
解题思路：先判断素数，然后枚举
解题心得：学会筛选法判断素数

*/

#include <iostream>

using namespace  std;
const int MAXN = 1000002;
int a[MAXN];

//int IsPrime(int x)
//{
//	if (x % 2 == 0)
//		return 0;
//	for (int i = 3; i*i <= x; i+=2)
//	{
//		if (x % i == 0)
//			return 0;
//	}
//	return 1;
//}

/*
筛选法对素数打表,O(N)
*/
void OddArray()
{
	int i, j;
	a[0] = 0;
	a[1] = 0;
	for (i = 0; i < MAXN; ++i)		//O(N)
		a[i] = 1;

	for (i = 2; i*i < MAXN; ++i)
	{
		if (a[i] == 1)				//O(N)
		{
			//只有当a[i] = 1时才需要执行a[j]=0,故a[j]=0执行的时间复杂度为O(N)
			for (j = 2*i; j < MAXN; j += i)		//O(N)
				a[j] = 0;
		}
	}
}

int main()
{
	int n;
	OddArray();
	while (cin >> n && n)
	{
		int i;
		for (i = 3; i <= n / 2; i += 2)
			//if (IsPrime(i) && IsPrime(n-i))
			if (a[i] && a[n-i])
				break;
		cout << n << " = " << i << " + " << n - i << endl;
	}

	return 0;
}
