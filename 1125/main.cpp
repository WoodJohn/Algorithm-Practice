#include <iostream>
#define INF 999999
using namespace std;

int n;
int graph[101][101];

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    graph[i][j] = 0;
                else
                {
                    graph[i][j] = INF;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            while (t--)
            {
                int a, b;
                cin >> a >> b;
                graph[i][a] = b;
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j])
                        graph[i][j] = graph[i][k] + graph[k][j];
                }
        }
        int rn = 1;
        int nMin = INF;
        for (int i = 1; i <= n; i++)
        {
            int nMax = 0;
            bool check = true;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (graph[i][j] > nMax)
                    nMax = graph[i][j];
                if (graph[i][j] == INF)
                {
                    check = false;
                    break;
                }
            }
            if (check && nMax < nMin)
            {
                nMin = nMax;
                rn = i;
            }
        }
        if (nMin < INF)
            cout << rn << ' ' << nMin << endl;
        else
            cout << "disjoint" << endl;
    }
    return 0;
}
