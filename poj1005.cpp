/*
poj1005-�򵥼���
��Ŀ���⣺��ˮ�԰�Բ����״��ʴ���أ�ÿ��50���ʷ��ӽ���(x,y)��������ᱻ��ʴ
����˼·��
	��(x, y)�������Ϊs = 1/2 * �� * r^2
	��Ҫyear = floor(s / 50 + 1)
���������
Sample Input

2
1.0 1.0
25.0 0.0
Sample Output

Property 1: This property will begin eroding in year 1.
Property 2: This property will begin eroding in year 20.
END OF OUTPUT.
*/

#include<iostream>
using namespace std;

const double pi = 3.1415926535;

int main()
{
	int year;
	int N;		//input lines
	double area;
	
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		double x, y;
		cin >> x >> y;
		area = 0.5 * pi * (x*x + y*y);
		year = (int)(area / 50.0 + 1.0);
		cout << "Property " << i << ": This property will begin eroding in year " << year << '.' << endl;
	}
	cout << "END OF OUTPUT." << endl;
}

