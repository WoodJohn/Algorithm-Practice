#include <stdio.h>

#define INF 999999

using namespace std;

int graph[101][101];
int n,a,b;

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++)
        {
            int d;
            scanf("%d", &d);
            if (j == 0)
                graph[i][d] = 0;
            else
                graph[i][d] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                if (graph[j][i] + graph[i][k] < graph[j][k])
                    graph[j][k] = graph[i][k] + graph[j][i];
            }
    if (graph[a][b] == INF)
        printf("-1\n");
    else
        printf("%d\n", graph[a][b]);
    return 0;
}
