// [S/W 문제해결 기본] 1211. 2일차 - Ladder2
#include<iostream>
#include<cstring>
using namespace std;


int ladder[101][101];
int visited[101][101];
int dis, departure;

// 왼쪽, 오른쪽, 위
int dx[3] = {0, 0, -1};
int dy[3] = {-1, 1, 0};

void finddeparture(int _x, int _y)
{
	int local_distance = 0;
	int x = _x;
	int y = _y;
	
	while (1)
	{
		if (x == 0) {
			if (dis > local_distance)
			{
				dis = local_distance;
				departure = y;
			}
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];

			if (mx < 0 || mx >= 100 || my < 0 || my >= 100) continue;
			if (ladder[mx][my] == 0) continue;
			if (visited[mx][my]) continue;
			x = mx;
			y = my;
			local_distance++;
			visited[mx][my] = 1;
			break;
		}
	}
	return;
}

int main(void)
{
	int num;

	for (int T = 1; T <= 1; T++)
	{
		memset(ladder, 0, sizeof(int) * 101 * 101);
		dis = 10000;
		cin >> num;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
			{
				cin >> ladder[i][j];
			}
		}

		for (int i = 0; i < 100; i++) {
			memset(visited, 0, sizeof(int) * 101 * 101);
			if (ladder[99][i]) finddeparture(99, i);
		}

		cout << '#' << num << ' ' << departure << '\n';
	}
	return 0;
}
