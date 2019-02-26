// SW Expert Academy 1209. Sum
#include<iostream>
#include<cstring>
using namespace std;
int num, ans;
int arr[100][100];
int main(void)
{
	for (int T = 0; T < 10; T++)
	{
		cin >> num;
		int sum = 0,ans = 0;
		memset(arr, 0, sizeof(int) * 100 * 100);
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];
		// 행의 합
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
				sum += arr[i][j];
			if (ans < sum) ans = sum;
			sum = 0;
		}
		// 열의 합
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
				sum += arr[j][i];
			if (ans < sum) ans = sum;
			sum = 0;
		}
		// 대각선의 합
		for (int i = 0; i < 100; i++)
		{
			sum += arr[i][i];
			if (ans < sum) ans = sum;
		}
		sum = 0;
		for (int i = 0; i < 100; i++)
		{
			sum += arr[i][100 - 1 - i];
			if (ans < sum) ans = sum;
		}
		cout << '#' << num << ' ' << ans << '\n';
	}
	return 0;
}
