// SW_Expert_Academy_1206 View
#include<iostream>
#include<string.h>
using namespace std;
 
int num, ans;
int building[1001];
 
int findmaxheight(int idx)
{
    // idx-2, idx-1, idx+1, idx+2 중 가장 높은 값 구하기.
    if (building[idx - 2] >= building[idx - 1])
    {
        if (building[idx - 2] >= building[idx + 1])
        {
            if (building[idx - 2] >= building[idx + 2])
                return idx - 2;
            else return idx + 2;
        }
        else
        {
            if (building[idx + 1] >= building[idx + 2])
                return idx + 1;
            else return idx + 2;
        }
    }
    else
    {
        if (building[idx - 1] >= building[idx + 1])
        {
            if (building[idx - 1] >= building[idx + 2])
                return idx - 1;
            else return idx + 2;
        }
        else
        {
            if (building[idx + 1] >= building[idx + 2])
                return idx + 1;
            else return idx + 2;
        }
    }
}
int main(void)
{
    for(int i = 1; i <= 10; i++)
    {
        cin >> num;
        memset(building, 0, sizeof(int)*1001);
        ans = 0;
 
        for (int j = 0; j < num; j++)
        {
            cin >> building[j];
        }
        for (int j = 2; j < num-2; j++)
        {
            int max_hidx = findmaxheight(j);
            if (building[j] > building[max_hidx])
                ans += building[j]-building[max_hidx];
        }
        cout << '#' << i << ' ' << ans << '\n';
    }
    return 0;
}
