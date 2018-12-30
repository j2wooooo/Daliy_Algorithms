#include<iostream>
using namespace std;
#define max(a, b) (a > b ? a : b)
int T[1500002];
int P[1500002];
int dp[1500002];
int main(void)
{
	int N, i;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
	for (i = N; i >= 1; i--)
	{
		// i+T[i] �� N+1�� �Ѿ�� �� ���� �� �״��.
		if (i + T[i] > N + 1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		}
	}
	cout << dp[1];
	return 0;
}
