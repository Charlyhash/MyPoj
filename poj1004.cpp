/*
poj1004 - 求平均数
题目大意：给定12个月的消费，求平均数
解题思路：维护一个总数sum，每行读入之后加到sum上，输出sum/12
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