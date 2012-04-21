#include <stdio.h>
#include <string.h>
#define N 501
#define INF 1000000000
struct nn
{
    int b,p;
}data[101];

int n, m;
int maxb;
int minmax;
int dp[102][N]; //dp[i][j]表示对第i组设备，带宽为j时的最小费用

inline int min(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < N; j++)\
            {
                dp[i][j] = INF;
            }
        }
        for (int ii = 1; ii <= n; ii++)
        {
            maxb = 0;
            scanf("%d", &m);
            for (int i = 0; i < m; i++)
            {
                scanf("%d %d", &data[i].b, &data[i].p);
                if (maxb < data[i].b)
                    maxb = data[i].b;
                for (int j = 1; j <= N; j++)
                {
                    dp[ii][min(j, data[i].b)] = min(dp[ii - 1][j] + data[i].p, dp[ii][min(j, data[i].b)]);
                }
            }
        }
        double max = 0.0;
        for (int i = 1; i <= maxb; i++)
        {
            if (double(i) / double(dp[n][i]) > max)
                max = double(i) / double(dp[n][i]);
        }
        printf("%.3f\n", max);
    }
    return 0;
}
