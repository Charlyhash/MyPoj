#include <iostream>
#include <string>

//#define  LOCAL
#ifdef LOCAL
#include <fstream>
#pragma warning(disable:4996)
#endif // LOCAL

using namespace std;

string sum(string s1, string s2)
{
	if (s1.length() < s2.length())
	{
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	for (int i = s1.length() - 1, j = s2.length() - 1; i >= 0; i--, j--)
	{
		s1[i] = char(s1[i] + (j >= 0 ? s2[j] - '0' : 0));
		if (s1[i] - '0' >= 10)
		{
			s1[i] = char((s1[i] - '0') % 10 + '0');
			if (i)
				s1[i - 1]++;
			else
				s1 = '1' + s1;
		}
	}

	return s1;

}

int main()
{
#ifdef LOCAL
	freopen("poj1503.txt", "r", stdin);
#endif // LOCAL
	string s;
	cin >> s;

	string s1;
	while (cin >> s1)
	{
		if ((s1.size() == 1 && s1[0] == '0'))
			break;
		s = sum(s, s1);
	}
	cout << s << endl;

#ifdef LOCAL
	fclose(stdin);
#endif // LOCAL
	return 0;
}