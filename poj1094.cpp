/*
poj1094 ��������
��Ŀ���⣺������ĸ��ƫ���ϵ���ж�ʱ����Ψһȷ������֮��Ĺ�ϵ��
�������������Է�Ϊ3�������1�������жϣ�2���л�������ì�ܣ�3���������㲻���ж�
a.������û�л����л���ֱ���������ȷ�����������������һ���ǣ�ֱ���жϷ���ߣ��϶����л��ˣ�
�ڶ�������ǣ����ɵ��������ں���ĸ����С����Ŀ�и�������ĸ�ĸ�����
b.���û�л�����ô�Ϳ��᲻���ж������������ж���������ٶ���һ�У�
���ȫ���ж��껹���ж������������ȷ������
c.������û�л���Ҳ�����ڶ����������ÿ��ȡ�������Ϊ��ĵ�ֻ��һ��������ô���Ǵ�
*/

#include <iostream>
#include <stack>
#define LOACAL
#ifdef LOACAL
#include <fstream>
#endif
using namespace std;

#define MAXN 27
int graph[MAXN][MAXN];	//ͼ
int indegree[MAXN];		//�������
int list[MAXN];			//�������
int in[MAXN];			//��ʱ�������

/*
��������
*/
int topo_sort(int n)
{
	memcpy(in, indegree, sizeof(indegree));
	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		if (!in[i])		//���Ϊ0
			s.push(i);
	}
	int countt = 0;
	bool flag = false;
	while (!s.empty())
	{
		if (s.size() > 1)	//һ���ж�����Ϊ0��˵����ֹһ������ʽ
			flag = true;
		int tmp = s.top();
		list[countt++] = tmp;		//��¼���
		s.pop();
		for (int i = 0; i < n; ++i)	//ɾ��tmp�йصıߺ��������������Ϊ0�����ѹ��ջ
		{
			if (graph[tmp][i] && (--in[i] == 0))
				s.push(i);
		}
	}
	if (countt != n)		//Ϊ�պ��ж������л��Ļ���������<n
		return 1; //�л�
	else if (flag)
		return 2;	//�ж������
	return 0;		//��Ψһ�����

}

int main()
{
	int n, m;
#ifdef LOACAL
	FILE* s;
	if (freopen_s(&s, "poj1094.txt", "r", stdin) != 0)
	{
		cout << "Open file error!" << endl;
		return -1;
	}
#endif
	while (cin >> n >> m && (n || m))
	{
		bool flag = false, flag2 = false;//flag:�Ƿ�����жϣ�flag2:�Ƿ��л�
		memset(graph, 0, sizeof(graph));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= m; ++i)
		{
			char a, b, waste;
			cin >> a >> waste >> b;
			if (!flag && !flag2)
			{
				if (graph[b - 'A'][a - 'A'] == 1)		//�з���ı�
				{
					flag2 = true;
					cout << "Inconsistency found after " << i << " relations." << endl;
					continue;
				}
				if (graph[a - 'A'][b - 'A'] == 0)		//��û������
				{
					graph[a - 'A'][b - 'A'] = 1;
					indegree[b - 'A']++;
				}

				int flag3 = topo_sort(n);
				if (flag3 == 0)
				{
					cout << "Sorted sequence determined after " << i << " relations: ";
					for (int j = 0; j < i; ++j)
					{
						cout << (char)(list[j] + 'A');
					}
					cout << "." << endl;
					flag = true;
				}
				else if (flag3 == 1)
				{
					cout << "Inconsistency found after " << i << " relations." << endl;
					flag2 = true;
				}
			}
		}

		if (!flag && !flag2)
			cout << "Sorted sequence cannot be determined." << endl;
	}

	fclose(s);
	return 0;
}

