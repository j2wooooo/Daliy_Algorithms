// SW Expert Academy 1215. 회문1 
#include<iostream>
#include<string>
using namespace std;

int N, ans;
char map[8][8];
string str;

int main(void)
{
	bool flag = true;

	for(int T = 1; T <= 10; T++)
	{
		ans = 0;
		cin >> N;
		getline(cin, str);

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
			{
				cin >> map[i][j];
			}
		}

		// 가로 탐색
		for (int i = 0; i < 8; i++)
		{
			for (int n = 0; n <= 8 - N; n++)
			{
				flag = true;
				for (int j = 0; j < (N / 2); j++)
				{
					if (map[i][j+n] != map[i][N +n - j - 1]) flag = false;
				}
				if (flag)ans++;
			}
		}

		// 세로 탐색
		for (int i = 0; i < 8; i++)
		{
			for (int n = 0; n <= 8 - N; n++)
			{
				flag = true;
				for (int j = 0; j < (N / 2); j++)
				{
					if (map[j+n][i] != map[N+n - j - 1][i]) flag = false;
				}
				if (flag) ans++;
			}
		}

		cout << '#' << T << ' ' << ans << '\n';
	}
	return 0;
}
