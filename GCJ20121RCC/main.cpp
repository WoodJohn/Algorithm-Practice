#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

struct box
{
    long long num;
    int type;
}boxes[102];

struct toy
{
    long long num;
    int type;
}toys[102];

long long inline max(long long a, long long b)
{
    return a > b ? a : b;
}

long long inline min(long long a, long long b)
{
    return a < b ? a : b;
}

long long dp[102][102];

int main()
{
    int t, i;
    cin >> t;
    FILE *out = fopen("out.out", "w");
    for (i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        int j;
        for (j = 1; j <= n; j++)
        {
            cin >> boxes[j].num >> boxes[j].type;
        }
        for (j = 1; j <= m; j++)
        {
            cin >> toys[j].num >> toys[j].type;
        }
        memset(dp, 0, sizeof(dp));
        int k;
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= m; k++)
            {
                int p, q;
                long long mMax = 0;
                if (boxes[j].type != toys[k].type)
                {
                    dp[j][k] = max(dp[j - 1][k], dp[j][k - 1]);
                    continue;
                }
                for (p = 0; p < j; p++)
                {
                    for (q = 0; q < k; q++)
                    {
                        long long kk = dp[p][q];
                        int tt;
                        long long n1 = 0, n2 = 0;
                        for (tt = p + 1; tt <= j; tt++)
                        {
                            if (boxes[tt].type == boxes[j].type)
                                n1 += boxes[tt].num;
                        }
                        for (tt = q + 1; tt <= k; tt++)
                        {
                            if (toys[tt].type == boxes[j].type)
                                n2 += toys[tt].num;
                        }
                        kk += min(n1, n2);
                        if (kk > mMax)
                            mMax = kk;
                    }
                }
                dp[j][k] = mMax;
            }
        }
        fprintf(out, "Case #%d: %I64d\n", i, dp[n][m]);
    }
    return 0;
}
