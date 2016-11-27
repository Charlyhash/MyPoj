#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAXN = 801;
const int MAXM = 21;
int n;
int m;
int dp[MAXM][MAXN];		//dp[j][k]:ȡj����ѡ�ˣ�ʹ���ز�Ϊk�����÷����У���غ����ı�غ�
int path[MAXM][MAXN];	//��¼��ѡ���ĺ�ѡ�˵ı��

						//���ݣ�ȷ��dp[j][k]�����Ƿ���ѡ�����ѡ��i
bool select(int j, int k, int i, int* v)
{
	//����ÿһ��j����û��ѡ��i,˵��ǰ���j��û��ѡ��i
	while (j > 0 && path[j][k] != i)		//path[j][k]��¼����dp[i][j]�����ѡ���Ǹ��˵����
	{
		k -= v[path[j][k]];					//path[j-1][k-v(path[j][k])]Ϊ�����ڶ����˵����
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
		int *p = new int[n + 1];	//ÿ���˵Ŀط�ֵ
		int *d = new int[n + 1];	//ÿ���˵ı緽ֵ
		int *s = new int[n + 1];	//ÿ���˵ı�غ�
		int *v = new int[n + 1];	//ÿ���˵ı�ز�

		memset(dp, -1, sizeof(dp));		//��ʼ��Ϊ-1
		memset(path, 0, sizeof(path));	//·����Ϊ0

										//input
		for (i = 1; i <= n; ++i)
		{
			cin >> p[i] >> d[i];

			s[i] = p[i] + d[i];		//��غ�
			v[i] = p[i] - d[i];		//��ز�
		}
		int fix = m * 20;		//������ֵ��

								//dp
		dp[0][fix] = 0;			//������dp[0][fix]����������dp[0][0];
		for (j = 1; j <= m; ++j)
		{
			for (k = 0; k <= 2 * fix; ++k)		//����ÿһ��d-p
			{
				if (dp[j - 1][k] >= 0)			//��ʼ��Ϊ-1�����ѡ�������ô>=0��û��ѡ�������Ҫ��
				{
					for (i = 1; i <= n; ++i)
					{
						if (dp[j][k + v[i]] < dp[j - 1][k] + s[i])		//����ѡ��������ı�غ�dp[j - 1][k] + s[i]	���ȵ�ǰ�ı�غʹ���滻
						{
							if (select(j - 1, k, i, v))					//���i����û��ѡ��
							{
								dp[j][k + v[i]] = dp[j - 1][k] + s[i];	//��������
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
			if (dp[m][fix - k] >= 0 || dp[m][fix + k] >= 0)	//�м��Ϊ��С�ı�ز���м�����������
				break;
		}
		int div = dp[m][fix - k] > dp[m][fix + k] ? fix - k : fix + k;	//��С��ز�
																		//��ز�div-fix(��Ϊ��������������fix),��غ�dp[m][div]
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
		sort(id, id + m);   //���������ѡ�˱��  
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