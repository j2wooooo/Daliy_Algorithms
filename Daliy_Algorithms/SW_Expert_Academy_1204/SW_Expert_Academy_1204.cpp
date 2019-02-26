// SW Expert Academy 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기
#include<iostream>
#include<string.h>
using namespace std;
 
int T, num, lscore, ans;
int score[101];
 
int main(void)
{
    cin >> T;
 
    while (T--)
    {
        cin >> num;
        memset(score, 0, sizeof(int)*101);
 
        for (int i = 0; i < 1000; i++)
        {
            cin >> lscore;
            score[lscore]++;
        }
        ans = 0;
        for (int i = 1; i < 101; i++)
        {
            if (score[ans] <= score[i]) ans = i;
        }
 
        cout << '#' << num << ' ' << ans << '\n';
    }
    return 0;
}
