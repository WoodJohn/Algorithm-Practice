#include <stdio.h>

#define INF 500001

int dis[501][501];

int d1[2][501][501];
int d2[501][2][501];
int d3[501][501][2];

int n,m,a,b,l;

inline int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i <= n ; i ++)
    {
        for (int j = 0; j <= n; j ++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    for (int i = 0; i <= 1; i ++)
        for (int j = 0; j <= n; j ++)
            for (int k = 0; k <= n; k ++)
            {
                d1[i][j][k] = INF;
            }
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= 1; j ++)
            for (int k = 0; k <= n; k ++)
            {
                d2[i][j][k] = INF;
            }
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            for (int k = 0; k <= 1; k ++)
            {
                d3[i][j][k] = INF;
            }
    while (m --)
    {
        scanf("%d %d %d", &a, &b, &l);
        if (dis[a][b] > l && a != b)
        {
            dis[a][b] = dis[b][a] = l;
        }
    }
    for(int k = 0; k <= n; k++)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                if (dis[i][k] != INF && dis[k][j] != INF && (dis[i][j] == INF || dis[i][k] + dis[k][j] < dis[i][j]))
                    dis[i][j] = dis[i][k] + dis[k][j];
    d1[0][0][0] = d2[0][0][0] = d3[0][0][0] = 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j < i; j ++)
        {
            for (int k = 0; k < i; k ++)
            {
                if (d1[(i - 1) % 2][j][k] != INF)
                {
                    d1[i % 2][j][k] = d1[(i - 1) % 2][j][k] + dis[i][i - 1];
                    d2[i - 1][i % 2][k] = min(d2[i - 1][i % 2][k], d1[(i - 1) % 2][j][k] + dis[i][j]);
                    d3[i - 1][j][i % 2] = min(d3[i - 1][j][i % 2], d1[(i - 1) % 2][j][k] + dis[k][i]);
                }
                if (d2[j][(i - 1) % 2][k] != INF)
                {
                    d2[j][i % 2][k] = d2[j][(i - 1) % 2][k] + dis[i][i - 1];
                    d1[i % 2][i - 1][k] = min(d1[i % 2][i - 1][k], d2[j][(i - 1) % 2][k] + dis[i][j]);
                    d3[j][i - 1][i % 2] = min(d3[j][i - 1][i % 2], d2[j][(i - 1) % 2][k] + dis[k][i]);
                }
                if (d3[j][k][(i - 1) % 2] != INF)
                {
                    d3[j][k][i % 2] = min(INF, d3[j][k][(i - 1) % 2] + dis[i][i - 1]);
                    d1[i % 2][k][i - 1] = min(d1[i % 2][k][i - 1], d3[j][k][(i - 1) % 2] + dis[i][j]);
                    d2[j][i % 2][i - 1] = min(d2[j][i % 2][i - 1], d3[j][k][(i - 1) % 2] + dis[k][i]);
                }
            }
        }
    }
    int sum = INF;
    for (int i = 0; i <= n; i ++)
    {
        for (int j = 0; j <= n; j ++)
        {
            int temp = dis[i][0] + dis[j][0] + dis[n][0];
            if (d3[i][j][n % 2] != INF)
                sum = min(sum, d3[i][j][n % 2] + temp);
            if (d2[i][n % 2][j] != INF)
                sum = min(sum, d2[i][n % 2][j] + temp);
            if (d1[n % 2][i][j] != INF)
                sum = min(sum, d1[n % 2][i][j] + temp);
        }
    }
    printf("%d\n", sum);
    return 0;
}
