//Description

//Given a set of sticks of various lengths, is it possible to join them end - to - end to form a square ?
//Input
//
//The first line of input contains N, the number of test cases.Each test case begins with an integer 4 <= M <= 20, the number of sticks.M integers follow; each gives the length of a stick - an integer between 1 and 10, 000.
//Output
//
//For each case, output a line containing "yes" if is is possible to form a square; otherwise output "no".
//Sample Input
//
//3
//4 1 1 1 1
//5 10 20 30 40 50
//8 1 7 2 6 4 4 3 5
//Sample Output
//
//yes
//no
//yes

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n;		//木块总数
int side;	//边长

bool used[21];
int cmp(const void* a, const void *b)		//降序排列, 用于qsort
{
	return *(int*)b - *(int *)a;
}

/*
num:边数 
len:当前组合边以组合的长度
s： stick[]的搜索起点
*/
bool dfs(int* stick, bool* visit,int num, int len, int s)
{
	if (num == 3)
		return true;

	for (int i = s; i < n; ++i)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		if (len + stick[i] < side)
		{
			if (dfs(stick, visit, num, len + stick[i], i))
				return true;
		}
		else if (len + stick[i] == side)
		{
			if (dfs(stick, visit, num + 1, 0, 0))		//构建新的side
				return true;
		}
		visit[i] = false;
	}

	return false;
}


int main()
{
	FILE* stream;
	if (freopen_s(&stream, "poj2362.txt", "r", stdin) != 0)
	{
		cout << "Open file Erroe!" << endl;
		return -1;
	}
	int time;
	cin >> time;
	for (int t = 0; t < time; ++t)
	{
		int sum = 0;		//长度之和
		cin >> n;
		int* stick = new int[n];
		bool* visit = new bool[n];

		for (int i = 0; i < n;++i)
		{
			cin>>stick[i];
			visit[i] = false;

			sum += stick[i];
		}
		if (n < 4 || sum%4 != 0)
		{
			cout << "no" << endl;
			continue;
		}
		qsort(stick, n, sizeof(int), cmp);		//	降序排列
		side = sum / 4;			//边长
		if (side < stick[0])	//边长<单个最大长度
		{
			cout << "no" << endl;
		}

		if (dfs(stick, visit, 0, 0, 0))
			cout << "yes" << endl;
		else
		{
			cout << "no" << endl;
		}
		delete stick;
		delete visit;
	}

	return 0;
}