// BOJ 3/2 코딩테스트 대비 모의고사 B번 - Baaaaaaaaaduk2 (Easy)
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int N, M, ans;
int board[21][21];
int visited[21][21];
vector<pair<int, int>>v;
queue<pair<int, int>>q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };

// 죽일 수 있는 상대 돌의 개수 세기
int bfs(int _x, int _y)
{
	int val = 0;
	bool flag = true;

	q.push(make_pair(_x, _y));
	visited[_x][_y] = 1;
	val++;

	while (!q.empty())
	{
		int qsz = q.size();
		while (qsz--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if (mx < 0 || mx >= N || my < 0 || my >= M) continue;
				if (board[mx][my] == 1) continue;
				if (visited[mx][my]) continue;
				if (board[mx][my] == 0) flag = false;
				if (board[mx][my] == 2)
				{
					visited[mx][my] = 1;
					q.push(make_pair(mx, my));
					val++;
				}
			}
		}
	}
	// 
	if (!flag) val = 0;
	return val;
}

void stone(int idx, int cnt)
{
	// 돌을 두개 놓았으면 잡을 수 있는 돌을 체크한다.
	if (cnt == 2)
	{
		int val = 0;
		int lans = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 2 && visited[i][j] == 0) {
					val = bfs(i, j);
					lans += val;
				}
			}
		}
		if (ans < lans) ans = lans;
		return;
	}

	int sz = (int)v.size();
	for (int i = idx; i < sz; i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		board[x][y] = 1;
		stone(i + 1, cnt+1);
		board[x][y] = 0;
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 0) v.push_back(make_pair(i, j));
		}
	}

	int sz = (int)v.size();
	for (int i = 0; i < sz-1; i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		board[x][y] = 1;
		stone(i + 1, 1);
		board[x][y] = 0;
	}

	cout << ans;
	return 0;
}
