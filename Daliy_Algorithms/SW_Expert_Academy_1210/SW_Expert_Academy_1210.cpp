// [S/W 문제해결 기본] 1210. 2일차 - Ladder1
#include<iostream>
#include<cstring>
using namespace std;

int ladder[101][101];

// 왼쪽, 오른쪽, 위
int dx[3] = {0, 0, -1};
int dy[3] = {-1, 1, 0};

int finddeparture(int _x, int _y)
{
	int x = _x;
	int y = _y;
	
	while (1)
	{
		if (x == 0) return y;
		for (int i = 0; i < 3; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];

			if (mx < 0 || mx >= 100 || my < 0 || my >= 100) continue;
			if (ladder[mx][my] == 0) continue;
			x = mx;
			y = my;
			ladder[mx][my] = 0;
			break;
		}
	}
	return y;
}

int main(void)
{
	int num;

	for (int T = 1; T <= 2; T++)
	{
		memset(ladder, 0, sizeof(int) * 101 * 101);
		cin >> num;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
			{
				cin >> ladder[i][j];
			}
		}

		for (int i = 0; i < 100; i++)
		{
			if (ladder[99][i] == 2)
			{
				int ans = finddeparture(99, i);
				cout << '#' << num << ' ' << ans << '\n';
				break;
			}
		}
	}
	return 0;
}
