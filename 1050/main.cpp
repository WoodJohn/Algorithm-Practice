#include <stdio.h>
#define MIN -1000000000
using namespace std;

int data[101][101];
int dp[101][101]; //dp[i][j][k]表示以第i行为首行、第j行为末行的最大矩阵和
int sum[101][101][101]; //sum[i][j][k]表示第k列从第i行到第j行的和
int n, max;

int find(int i, int j)
{
    if (dp[i][j] != MIN)
        return dp[i][j];
    if (i == j)
    {
        int t = 0;
        int tmax = MIN;
        for (int ii = 1; ii <= n; ii++)
        {
            t += data[i][ii];
            if (t > tmax)
                tmax = t;
            if (t < 0)
            {
                t = 0;
            }
        }
        dp[i][j] = tmax;
        return dp[i][j];
    }
    int ssum = 0;
    int tmax = MIN;
    for (int ii = 1; ii <= n; ii++)
    {
        ssum += sum[i][j][ii];
        if (ssum > tmax)
            tmax = ssum;
        if (ssum < 0)
            ssum = 0;
    }
    dp[i][j] = tmax;
    return dp[i][j];
}

int main()
{
    scanf("%d", &n);
    max = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
                dp[i][j] = MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
            {
                if (j == i)
                    sum[i][j][k] = data[j][k];
                else
                    sum[i][j][k] = sum[i][j - 1][k] + data[j][k];
            }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = find(i, j);
            if (t > max)
                max = t;
        }
    }
    printf("%d\n", max);
    return 0;
}
