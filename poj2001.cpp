/*
poj 2001-trie

题目大意：对于给定的单词中，找到每一个单词的最短公共前缀且不能与其他的公共前缀相同
解题思路：用trie建立树，节点中有一个count来记录该前缀单词出现的次数。查找时，遇到count
说明这是第一次出现这个前缀，返回。
*/

#include <cstdio>

#pragma warning(disable:4996)//vs

#define MAXLINE 1005//最大长度
#define CHARNUM 30//字母的数量
#define MAXLENGTH 30//单词的长度

struct Trie
{
	int count;
	int next[CHARNUM];//指向的child的序号
}trie[MAXLINE*CHARNUM];//create MAXLINE*CHARNUM个Trie节点

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
		if (trie[p].count == 1)//查找到了
			return;
		printf("%c", str[i]);
		p = trie[p].next[str[i] - 'a'];//p指向child
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

