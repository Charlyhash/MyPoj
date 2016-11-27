/*
poj 3468-�߶���
http://poj.org/problem?id=3468
You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations.
One type of operation is to add some given number to each number in a given interval. 
The other is to ask for the sum of numbers in a given interval.

��Ŀ���⣺���ڸ�����һ�����������ֲ�������ĳ������ĺ��Լ�����ĳ�������ֵ
����˼·�����߶�����
*/

#include <cstdio>
#include <algorithm>

using namespace std;

//#pragma warning(disable:4996)

#define ll long long
inline int L(int r)
{
	return r << 1;
}
inline int R(int r)
{
	return (r << 1) + 1;
}
inline int MID(int l, int r)
{
	return (l + r) >> 1;
}
const int max_n = 1e5 + 10;
ll sum;

//���Ľڵ�ṹ���߶ε����left���ص�right
//[left, right]�ĺ��Լ�����ֵadd
struct node
{
	int left;
	int right;
	ll val;
	ll add;
}tree[max_n<<2];//interval tree

ll arr[max_n << 2];//init array

//��һ����
void Built(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].add = 0;
	if (l == r)
	{
		tree[root].val = arr[l];
		return;
	}
	else
	{
		//�ݹ鹹����������
		int mid = MID(l, r);
		Built(l, mid, L(root));
		Built(mid + 1, r, R(root));
		//����root
		tree[root].val = tree[L(root)].val + tree[R(root)].val;
	}

}

void Update(int root)
{
	//��������
	if (tree[root].add)
	{
		tree[L(root)].add += tree[root].add;//
		tree[R(root)].add += tree[root].add;//
		tree[L(root)].val += (tree[L(root)].right - tree[L(root)].left + 1)*tree[root].add;
		tree[R(root)].val += (tree[R(root)].right - tree[R(root)].left + 1)*tree[root].add;
		tree[root].add = 0;
	}
}


//����v
void Add(int l, int r, ll v, int root)
{
	if (l <= tree[root].left && r >= tree[root].right)
	{
		tree[root].add += v;
		tree[root].val += v*(tree[root].right - tree[root].left + 1);
		return;
	}
	else 
	{
		//�ֱ�����������������
		Update(root);
		if (tree[root].left == tree[root].right)
			return;
		int mid = MID(tree[root].left, tree[root].right);
		if (l > mid)
			Add(l, r, v, R(root));
		else if (r <= mid)
			Add(l, r, v, L(root));
		else
		{
			Add(l, mid, v, L(root));
			Add(mid + 1, r, v, R(root));
		}
		tree[root].val = tree[L(root)].val + tree[R(root)].val;
	}
}

void Solve(int l, int r, int root)
{
	if (l <= tree[root].left && r >= tree[root].right)
	{
		sum += tree[root].val;
		return;
	}
	else {
		Update(root);
		if (tree[root].left == tree[root].right)
			return;
		int mid = MID(tree[root].left, tree[root].right);
		if (l > mid)
			Solve(l, r, R(root));
		else if (r <= mid)
			Solve(l, r, L(root));
		else
		{
			Solve(l, mid, L(root));
			Solve(mid + 1, r, R(root));
		}
	}
}

int main()
{
	//freopen("poj3468.txt", "r", stdin);
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		for (int i = 1; i <= m; ++i)
			scanf("%lld", arr + i);
		//����
		Built(1, m, 1);
		char c[2];
		while (n--)
		{
			scanf("%s", c);
			if ('C' == c[0])
			{
				int l, f;
				ll v;
				scanf("%d %d %lld", &l, &f, &v);
				Add(l, f, v, 1);
			}
			else
			{
				int l, f;
				scanf("%d %d", &l, &f);
				sum = 0;
				Solve(l, f, 1);
				printf("%lld\n", sum);
			}
		}
	}

}