/*
poj1004 - ��ƽ����
��Ŀ���⣺����12���µ����ѣ���ƽ����
����˼·��ά��һ������sum��ÿ�ж���֮��ӵ�sum�ϣ����sum/12
*/

#include <iostream>
using namespace std;

int main()
{
	double sum = 0;
	double tmp;
	for (int i = 0; i < 12;++i)
	{
		cin >> tmp;
		sum += tmp;
	}
	cout << "$" << sum / 12 << endl;
}