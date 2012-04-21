#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;

int unit[101];
vector<int> g[101];
int last, sum;
int n, m;

int main()
{
    int t, i, j;
    cin >> t;
    for (j = 1; j <= t; j++)
    {
        memset(unit, 0, sizeof(unit));
        cin >> n >> m;
        for (i = 0; i < n; i++)
        {
            cin >> unit[i];
            g[i].clear();
        }
        for (i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        sum = 0;
        int cur = 0;
        while (g[cur].size() != 0)
        {
            int mMax = 0;
            int maxI = 0;
            for (i = 0; i < g[cur].size(); i++)
            {
                if (unit[g[cur][i]] > mMax)
                {
                    mMax = unit[g[cur][i]];
                    maxI = i;
                }
            }
            sum += mMax;
            cur = g[cur][maxI];
        }
        printf("Case %d: %d %d\n", j, sum, cur);
    }
    return 0;
}
