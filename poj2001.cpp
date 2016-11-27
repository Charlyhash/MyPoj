/*
poj 2001-trie

��Ŀ���⣺���ڸ����ĵ����У��ҵ�ÿһ�����ʵ���̹���ǰ׺�Ҳ����������Ĺ���ǰ׺��ͬ
����˼·����trie���������ڵ�����һ��count����¼��ǰ׺���ʳ��ֵĴ���������ʱ������count
˵�����ǵ�һ�γ������ǰ׺�����ء�
*/

#include <cstdio>

#pragma warning(disable:4996)//vs

#define MAXLINE 1005//��󳤶�
#define CHARNUM 30//��ĸ������
#define MAXLENGTH 30//���ʵĳ���

struct Trie
{
	int count;
	int next[CHARNUM];//ָ���child�����
}trie[MAXLINE*CHARNUM];//create MAXLINE*CHARNUM��Trie�ڵ�

int pos = 1;

char str[MAXLINE][MAXLENGTH];//the input word

void Insert(char str[])
{
	int p = 1; 

	for (int i = 0; str[i]; ++i)
	{
		if (trie[p].next[str[i] - 'a'] == 0)
		{
			trie[p].next[str[i] - 'a'] = ++pos;
			trie[pos].count = 0;
		}
		p = trie[p].next[str[i] - 'a'];
		trie[p].count++;
	}
	printf("Insert OK:%s\n", str);
}

void Search(char str[])
{
	int p = 1;

	for (int i = 0; str[i]; ++i)
	{
		if (trie[p].count == 1)//���ҵ���
			return;
		printf("%c", str[i]);
		p = trie[p].next[str[i] - 'a'];//pָ��child
	}
}

int main()
{
	freopen("poj2001.txt", "r", stdin);
	int n = 0;
	while (~scanf("%s", str[n]))
		Insert(str[n++]);

	for (int i = 0; i < n; ++i)
	{
		printf("%s ", str[i]);
		Search(str[i]);
		printf("\n");
	}

	return 0;
}

