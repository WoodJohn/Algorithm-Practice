#include <iostream>
#include <string.h>
using namespace std;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, w;
    int num[1005], cnt = 0;
    num[0] = 0;
    cin >> n >> w;
    int last = 1;
    while (n--)
    {
        int a;
        cin >> a;
        if (a != last)
        {
            last = a;
            cnt++;
            num[cnt] = 1;
        }
        else
        {
            num[cnt]++;
        }
    }
    int dp[35][1005];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = num[0];
    int mMax = 0;
    for (int i = 0; i <= w; i++)
    {
        for (int j = i; j <= cnt; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
            {
                if (j % 2)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 2] + num[j];
            }
            else
            {
                if (i == 1 && j == 1)
                    dp[i][j] = num[0] + num[1];
                else
                {
                    int a = dp[i - 1][j - 1] + num[j];
                    int b = dp[i][j - 2] + num[j];
                    dp[i][j] = max(a, b);
                    if (dp[i][j] > mMax)
                        mMax = dp[i][j];
                }
            }
        }
    }
    cout << mMax << endl;
    return 0;
}
