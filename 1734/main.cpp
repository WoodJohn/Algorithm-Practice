/*
POJ 1734
利用修改后的floyd求最小代价回路（好题）
关键修改点：当遍历到K时，表示从1 ~ K-1为中间节点的最小路径已经全部求出。此时，遍历所有i,j(均取
1到K-1之间的值）取i到j的最短距离(已在前K-1次循环中求出)，加上i到K、K到j的值，即求得一个从i到j的
环（即i -> j -> K -> i）。这样遍历K可求得所有环（需要思考why），记录路径找出最小即可。
难点：
1.记录路径。用pre[i][j]表示从i到j的最短路上j的父节点，在找到一个环时用递归产生结果数组
2.去掉1-2-1这样的长度为2的环。只需要在floyd的内层循环中去掉i == j时的情况即可（显然i==j时得到的
最短路一定多次经过某些节点）
*/

#include <stdio.h>
#include <string.h>
#define INF 99999999
using namespace std;

int dist[101][101];
int graph[101][101];
int pre[101][101];
bool used[101][101];
int mMin;
int minN;
int n, m;

int result[101];
int r;

void calc(int a, int p)
{
    if (pre[a][p] != 0)
    {
        calc(a, pre[a][p]);
    }
    result[r++] = p;
}

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= k - 1; i++)
        {
            for (int j = i + 1; j <= k - 1; j++)
            {
                int t = dist[i][j] + graph[i][k] + graph[k][j];
                if (t < mMin)
                {
                    mMin = t;
                    r = 0;
                    calc(i, j);
                    result[r++] = k;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            graph[i][j] = INF;
        }
    }
    memset(pre, 0, sizeof(pre));
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (dist[a][b] > c)
        {
            dist[a][b] = dist[b][a] = c;
            graph[a][b] = graph[b][a] = c;
            pre[a][b] = a;
            pre[b][a] = b;
        }
    }
    mMin = INF;
    floyd();
    if (mMin == INF)
        printf("No solution.\n");
    else
    {
        for (int i = 0; i < r - 1; i++)
        {
            printf("%d ", result[i]);
        }
        printf("%d\n", result[r - 1]);
    }
    return 0;
}
