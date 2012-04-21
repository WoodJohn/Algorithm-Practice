/*
POJ 1734
�����޸ĺ��floyd����С���ۻ�·�����⣩
�ؼ��޸ĵ㣺��������Kʱ����ʾ��1 ~ K-1Ϊ�м�ڵ����С·���Ѿ�ȫ���������ʱ����������i,j(��ȡ
1��K-1֮���ֵ��ȡi��j����̾���(����ǰK-1��ѭ�������)������i��K��K��j��ֵ�������һ����i��j��
������i -> j -> K -> i������������K��������л�����Ҫ˼��why������¼·���ҳ���С���ɡ�
�ѵ㣺
1.��¼·������pre[i][j]��ʾ��i��j�����·��j�ĸ��ڵ㣬���ҵ�һ����ʱ�õݹ�����������
2.ȥ��1-2-1�����ĳ���Ϊ2�Ļ���ֻ��Ҫ��floyd���ڲ�ѭ����ȥ��i == jʱ��������ɣ���Ȼi==jʱ�õ���
���·һ����ξ���ĳЩ�ڵ㣩
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
