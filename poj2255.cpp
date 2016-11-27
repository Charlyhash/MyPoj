/*
poj2255-给出二叉树的先序遍历和中序遍历，求后序遍历
reference:	
1. http://blog.csdn.net/cbs612537/article/details/8530294
2. http://blog.csdn.net/mtawaken/article/details/7352328

解题思路：	
用迭代的思想，先序遍历的第一个为根节点，将中序遍历分为左右子树。递归调用，
用不同的函数递归出口会不一样，因此递归出口应该根据递归函数的具体情况来确定.

心得：
脑子不够用，对递归还是不能好好利用，要练习。
递归的关键在于将问题划分为规模小的子问题然后确定递归的出口，在递归出口根据设计的递归函数来确定。
MakeTree函数是对中序遍历的数组划分，前后两部分作为子问题，继续调用MakeTree。这种情况下，当中序遍历的数组不存在时
应该退出。如果只
*/
#include <iostream>

using namespace std; 

char pre[27];		//先序遍历
char mid[27];		//中序遍历
int pos = -1;		//先序遍历数组的下标

/*
preStart,preLast为先序遍历数组的起点和终点
midStart,midLast为中序遍历数组的起点和终点
*/
void MakeTree1(int preStart, int preLast, int midStart, int midLast)
{
	char value = pre[preStart];		//先序遍历的第一个下标
	int i = 0;
	while (mid[i] != value)			//问题划分：找到中序遍历和先序遍历相等的位置，将数组分为两个
		++i;
	if (midStart < i)
	{
		MakeTree1(preStart + 1, preStart + i - midStart, midStart, i - 1);
	}
	if (midLast > i)
	{
		MakeTree1(preStart + i - midStart + 1, preLast, i + 1, midLast);
	}
	cout << value;				//递归出口：当midStart = midLast = i时，输出
}


/*
i，j为中序遍历的起点和终点，每次根据先序遍历的值将中序遍历的数组分为两个数组。
*/
void MakeTree(int i, int j)		
{
	int k;		//划分数组的位置
	if (i > j)	//递归出口：当i>j该数组已经不存在
		return;
	pos++;		//每次循环，先序遍历的数组下标向后移动1
	for (k = i; k < j; ++k)		//找到k
	{
		if (pre[pos] == mid[k])
			break;
	}
	//对划分的两个数组递归调用MakeTree
	MakeTree(i, k - 1);
	MakeTree(k + 1, j);
	
	std::cout << mid[k];
}

int main(void)
{
	while (cin >> pre >> mid)
	{
		//MakeTree(0, strlen(pre) - 1);
		MakeTree1(0, strlen(pre) - 1, 0, strlen(mid)-1);
		cout << endl;
		pos = -1;
	}
	return 0;
}


