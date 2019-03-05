// [SW Expert Academy] 1213. String
// KMP 방식으로 코딩
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int num, ans;
string sentence, pattern;

vector<int> makeTable()
{
	int size = (int)pattern.size();
	vector<int> table(size, 0);

	int j = 0;
	for (int i = 1; i < size; i++)
	{
		while (j != 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}
	return table;
}
int kmp()
{
	vector<int>t = makeTable();
	int ssize = (int)sentence.size();
	int psize = (int)pattern.size();
	int ans = 0;
	int j = 0;
	for (int i = 0; i < ssize; i++)
	{
		while (j != 0 && pattern[j] != sentence[i])
		{
			j = t[j - 1];
		}
		if (pattern[j] == sentence[i])
		{
			if (j == psize - 1)
			{
				ans++;
				j = t[j];
			}
			else
				j++;
		}
	}
	return ans;
}
int main()
{
	int T = 10;
	while (T--)
	{
		cin >> num;
		cin >> pattern;
		cin >> sentence;
		ans = kmp();

		cout << '#' << num << ' ' << ans << '\n';
	}

	return 0;
}
