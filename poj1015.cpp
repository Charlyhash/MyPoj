#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAXN = 801;
const int MAXM = 21;
int n;
int m;
int dp[MAXM][MAXN];		//dp[j][k]:取j个候选人，使其辩控差为k的所用方案中，辩控和最大的辩控和
int path[MAXM][MAXN];	//记录所选定的候选人的编号

						//回溯，确认dp[j][k]方案是否曾选择过候选人i
bool select(int j, int k, int i, int* v)
{
	//对于每一个j，都没有选择i,说明前面的j个没有选择i
	while (j > 0 && path[j][k] != i)		//path[j][k]记录的是dp[i][j]中最后选的那个人的序号
	{
		k -= v[path[j][k]];					//path[j-1][k-v(path[j][k])]为倒数第二个人的序号
		j--;
	}

	return j == 0;
}

int main()
{
	int time = 1;
	while (cin >> n >> m && n)
	{
		//Initial
		int j, k, i;
		int *p = new int[n + 1];	//每个人的控方值
		int *d = new int[n + 1];	//每个人的辩方值
		int *s = new int[n + 1];	//每个人的辩控和
		int *v = new int[n + 1];	//每个人的辩控差

		memset(dp, -1, sizeof(dp));		//初始都为-1
		memset(path, 0, sizeof(path));	//路径都为0

										//input
		for (i = 1; i <= n; ++i)
		{
			cin >> p[i] >> d[i];

			s[i] = p[i] + d[i];		//辩控和
			v[i] = p[i] - d[i];		//辩控差
		}
		int fix = m * 20;		//总修正值，

								//dp
		dp[0][fix] = 0;			//修正后dp[0][fix]才是真正的dp[0][0];
		for (j = 1; j <= m; ++j)
		{
			for (k = 0; k <= 2 * fix; ++k)		//对于每一个d-p
			{
				if (dp[j - 1][k] >= 0)			//初始化为-1，如果选择过，那么>=0。没有选择过不需要管
				{
					for (i = 1; i <= n; ++i)
					{
						if (dp[j][k + v[i]] < dp[j - 1][k] + s[i])		//我们选择的是最大的辩控和dp[j - 1][k] + s[i]	，比当前的辩控和大就替换
						{
							if (select(j - 1, k, i, v))					//序号i的人没有选过
							{
								dp[j][k + v[i]] = dp[j - 1][k] + s[i];	//符合条件
								path[j][k + v[i]] = i;
							}
						}
					}
				}
			}
		}

		//output
		for (k = 0; k <= fix; ++k)
		{
			if (dp[m][fix - k] >= 0 || dp[m][fix + k] >= 0)	//中间的为最小的辩控差，从中间向两边搜索
				break;
		}
		int div = dp[m][fix - k] > dp[m][fix + k] ? fix - k : fix + k;	//最小辩控差
																		//辩控差div-fix(因为整个区间右移了fix),辩控和dp[m][div]
																		//div-fxi = p - d
																		//dp[m][div]= p + d;
																		//p = (dp[m][div] + div - fix) / 2;d = (dp[m][div] - div + fix) / 2

		cout << "Jury #" << time++ << endl;
		cout << "Best jury has value ";
		cout << (dp[m][div] + div - fix) / 2 << " for prosecution and value ";
		cout << (dp[m][div] - div + fix) / 2 << " for defence:" << endl;

		int* id = new int[m];
		for (i = 0, j = m, k = div; i < m; i++)
		{
			id[i] = path[j][k];
			k -= v[id[i]];
			j--;
		}
		sort(id, id + m);   //升序输出候选人编号  
		for (i = 0; i < m; i++)
			cout << ' ' << id[i];
		cout << endl;

		/*Relax*/

		delete p;
		delete d;
		delete s;
		delete v;
		delete id;
	}
	return 0;
}