/*
poj2262 - �����ж�
��Ŀ���⣺	����һ����n,�����ֽ�����������ĺͣ�����Щ�ֽ��У�������������Ҫ���
			6 <= n < 1000000
����˼·�����ж�������Ȼ��ö��
�����ĵã�ѧ��ɸѡ���ж�����

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
ɸѡ�����������,O(N)
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
			//ֻ�е�a[i] = 1ʱ����Ҫִ��a[j]=0,��a[j]=0ִ�е�ʱ�临�Ӷ�ΪO(N)
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
