#include <iostream>
#include <string.h>
using namespace std;

struct m
{
    int v;
    int l;
    int r;
}dp[200][200];

int main()
{
    int n;
    cin >> n;
    int i;
    int num[200];
    for (i = 0; i < n; i++)
    {
        cin >> num[i];
        dp[i][i].l = num[i];
        dp[i][i].r = num[i];
    }
    int j, k;
    memset(dp, 0, sizeof(dp));
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j + i - 1 < n; j++)
        {
            int mMin = 999999999;
            if (i == 2)
            {
                mMin = 0;
            }
            else
            {
                for (k = 0; k < i - 2; k++)
                {
                    m a1, a2;
                    a1 = dp[j][j + k + 1];
                    a2 = dp[j + k + 1][j + i - 1];
                    int t;
                    if (a1.l != a1.r || a2.l != a2.r)
                    {
                        t = a1.v + a2.v + a1.l * num[j + k + 1] * a2.r;
                    }
                    if (t < mMin)
                        mMin = t;
                }
            }
            dp[j][j + i - 1].v = mMin;
            dp[j][j + i - 1].l = num[j];
            dp[j][j + i - 1].r = num[j + i - 1];
        }
    }
    cout << dp[0][n - 1].v << endl;
    return 0;
}
