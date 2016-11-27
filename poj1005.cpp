/*
poj1005-简单计算
题目大意：河水以半圆的形状侵蚀土地，每年50，问房子建在(x,y)处多少年会被侵蚀
解题思路：
	在(x, y)处，面积为s = 1/2 * π * r^2
	需要year = floor(s / 50 + 1)
输入输出：
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

