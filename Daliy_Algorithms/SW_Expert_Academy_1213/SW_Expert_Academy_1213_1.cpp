// // [SW Expert Academy] 1213. String
// 라빈 카프 방식으로 풀이
#include<iostream>
#include<string>
using namespace std;
#define BASE 8

int n, ans;
string sentence;
string pattern;

long long calchash(string s)
{
	long long sum = 0;
	for (int i = 0; i < (int)pattern.size(); i++)
	{
		sum = (sum << BASE) + s[i];
	}
	return sum;
}
long long findnewhash(int s, int e, int high, long long prehash)
{
	return (prehash - (sentence[s] << (BASE*high)) << BASE) + sentence[e];
}
int main(void)
{
	int T = 10;
	while (T--)
	{
		cin >> n;
		cin >> pattern >> sentence;
		ans = 0;

		long long phash = calchash(pattern);
		long long shash = calchash(sentence);
		int psize = (int)pattern.size();

		for (int i = 0; i <= (int)sentence.size() - psize; i++)
		{
			shash = findnewhash(i, i + psize, psize-1, shash);
			if (shash == phash) ans++;
		}
		cout << '#' << n << ' ' << ans << '\n';
	}
	return 0;
}
