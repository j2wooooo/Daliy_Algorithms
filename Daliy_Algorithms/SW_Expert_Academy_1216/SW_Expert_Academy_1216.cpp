// SW Expert Academy 1215. 회문2 
#include<iostream>
#include<string>
using namespace std;
#define MAX 100

int num, ans;
char map[MAX][MAX];
string str;

int main(void)
{
	bool flag = true;

	for(int T = 1; T <= 10; T++)
	{
		ans = 0;
		cin >> num;
		getline(cin, str);

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++)
			{
				cin >> map[i][j];
			}
		}

		// 가로 탐색
		for (int N = 1; N <= MAX; N++)
		{
			for (int i = 0; i < MAX; i++)
			{
				for (int n = 0; n <= MAX - N; n++)
				{
					flag = true;
					for (int j = 0; j < (N / 2); j++)
					{
						if (map[i][j + n] != map[i][N + n - j - 1]) flag = false;
					}
					if (flag && ans < N)ans = N;
				}
			}

		}

		// 세로 탐색
		for (int N = 1; N <= MAX; N++)
		{
			for (int i = 0; i < MAX; i++)
			{
				for (int n = 0; n <= MAX - N; n++)
				{
					flag = true;
					for (int j = 0; j < (N / 2); j++)
					{
						if (map[j + n][i] != map[N + n - j - 1][i]) flag = false;
					}
					if (flag && ans < N)ans = N;
				}
			}
		}

		cout << '#' << num << ' ' << ans << '\n';
	}
	return 0;
}
