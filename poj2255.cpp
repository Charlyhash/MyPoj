/*
poj2255-��������������������������������������
reference:	
1. http://blog.csdn.net/cbs612537/article/details/8530294
2. http://blog.csdn.net/mtawaken/article/details/7352328

����˼·��	
�õ�����˼�룬��������ĵ�һ��Ϊ���ڵ㣬�����������Ϊ�����������ݹ���ã�
�ò�ͬ�ĺ����ݹ���ڻ᲻һ������˵ݹ����Ӧ�ø��ݵݹ麯���ľ��������ȷ��.

�ĵã�
���Ӳ����ã��Եݹ黹�ǲ��ܺú����ã�Ҫ��ϰ��
�ݹ�Ĺؼ����ڽ����⻮��Ϊ��ģС��������Ȼ��ȷ���ݹ�ĳ��ڣ��ڵݹ���ڸ�����Ƶĵݹ麯����ȷ����
MakeTree�����Ƕ�������������黮�֣�ǰ����������Ϊ�����⣬��������MakeTree����������£���������������鲻����ʱ
Ӧ���˳������ֻ
*/
#include <iostream>

using namespace std; 

char pre[27];		//�������
char mid[27];		//�������
int pos = -1;		//�������������±�

/*
preStart,preLastΪ�����������������յ�
midStart,midLastΪ�����������������յ�
*/
void MakeTree1(int preStart, int preLast, int midStart, int midLast)
{
	char value = pre[preStart];		//��������ĵ�һ���±�
	int i = 0;
	while (mid[i] != value)			//���⻮�֣��ҵ�������������������ȵ�λ�ã��������Ϊ����
		++i;
	if (midStart < i)
	{
		MakeTree1(preStart + 1, preStart + i - midStart, midStart, i - 1);
	}
	if (midLast > i)
	{
		MakeTree1(preStart + i - midStart + 1, preLast, i + 1, midLast);
	}
	cout << value;				//�ݹ���ڣ���midStart = midLast = iʱ�����
}


/*
i��jΪ��������������յ㣬ÿ�θ������������ֵ����������������Ϊ�������顣
*/
void MakeTree(int i, int j)		
{
	int k;		//���������λ��
	if (i > j)	//�ݹ���ڣ���i>j�������Ѿ�������
		return;
	pos++;		//ÿ��ѭ������������������±�����ƶ�1
	for (k = i; k < j; ++k)		//�ҵ�k
	{
		if (pre[pos] == mid[k])
			break;
	}
	//�Ի��ֵ���������ݹ����MakeTree
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


